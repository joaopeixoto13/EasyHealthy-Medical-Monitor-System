#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/init.h>
#include <linux/module.h>
#include <asm/io.h>
#include <linux/timer.h>
#include <linux/err.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/jiffies.h>
#include "CGPIO.h"

#define DEVICE_NAME "buzzer0"
#define CLASS_NAME "buzzerClass"
MODULE_LICENSE("GPL");

/**
 * @brief Device Variables
 */
static struct class* buzzerDevice_class = NULL;
static struct device* buzzerDevice_device = NULL;
static dev_t buzzerDevice_majorminor;
static struct cdev c_dev;  
static struct class *s_pDeviceClass;
static struct device *s_pDeviceObject;

/**
 * @brief Timer Variable
 */
static struct timer_list timer;

/**
 * @brief Raspberry Pi 
 */
static const int buzzerGpioPin = 23;
SGPIORegister * s_pGpioRegisters;

/**
 * @brief Timer Callback function
 * @details This function is called when the timer expires and turns off the buzzer
 * @param data 
 */
void timer_callback(struct timer_list * data)
{
    GPIO_write(s_pGpioRegisters, buzzerGpioPin, 0);
}

/**
 * @brief Opens the device
 * @param p_inode: File on disk where the device is mounted
 * @param p_file: Structure describing the file
 * @return 0 
 */
int buzzer_device_open(struct inode* p_inode, struct file *p_file)
{
    p_file->private_data = (SGPIORegister *) s_pGpioRegisters;
    return 0;
}

/**
 * @brief Closes the device
 * @param p_inode: File on disk where the device is mounted
 * @param p_file: Structure describing the file
 * @return 0 
 */
int buzzer_device_close(struct inode *p_inode, struct file * pfile)
{
    pfile->private_data = NULL;
    return 0;
}

/**
 * @brief Writes data to the device
 * @param p_file: Kernel level structure describing the file
 * @param p_buff: User level buffer containing the data to write
 * @param len: Number of bytes to be written
 * @param poffset: Offset where to write to (actual position) 
 * @return len 
 */
ssize_t buzzer_device_write(struct file *pfile, const char __user *pbuff, size_t len, loff_t *off) {
    SGPIORegister *pDev; 
	 
    if(unlikely(pfile->private_data == NULL))
        return -EFAULT;
        
    pDev = (SGPIORegister *)pfile->private_data;
    if (pbuff[0]=='0') 
        GPIO_write(pDev, buzzerGpioPin, 0);
    else
    { 
        GPIO_write(pDev, buzzerGpioPin, 1);
        if(len > 2)
        {
            if (len > 20)
                return -EFAULT;
            char time[20];
            int i;
            for(i = 0; i < len-2; i++)
                time[i] = pbuff[i+2];
            time[i] = '\0';
            mod_timer(&timer, jiffies + msecs_to_jiffies(simple_strtol(time, NULL, 10)));
        }
    }
    return len;
}

/**
 * @brief Maps user space into VFS functions
 */
static struct file_operations buzzerDevice_fops = {
    .owner = THIS_MODULE,
    .open = buzzer_device_open,
    .release = buzzer_device_close,
    .write = buzzer_device_write, 
};

/**
 * @brief Module initialization
 * @return 0 if init successful, else error
 */
static int __init buzzerModule_init(void) {
    int ret;
    struct device *dev_ret;

    /**< Try to allocate character device memory */
    if ((ret = alloc_chrdev_region(&buzzerDevice_majorminor, 0, 1, DEVICE_NAME)) < 0) {
        return ret;
    }

    /**< Try to create device class */
    if (IS_ERR(buzzerDevice_class = class_create(THIS_MODULE, CLASS_NAME))) {
        unregister_chrdev_region(buzzerDevice_majorminor, 1);
        return PTR_ERR(buzzerDevice_class);
    }
    /**< Try to create device */
    if (IS_ERR(dev_ret = device_create(buzzerDevice_class, NULL,
                                       buzzerDevice_majorminor, NULL,
                                       DEVICE_NAME))) {
        class_destroy(buzzerDevice_class);
        unregister_chrdev_region(buzzerDevice_majorminor, 1);
        return PTR_ERR(dev_ret);
    }

    /**< Initialize device */
    cdev_init(&c_dev, &buzzerDevice_fops); /**< Map device functions */
    c_dev.owner = THIS_MODULE;

    /**< Try to add a char device to the system */
    if ((ret = cdev_add(&c_dev, buzzerDevice_majorminor, 1)) < 0) {
        printk(KERN_NOTICE "Error %d adding device", ret);
        device_destroy(buzzerDevice_class, buzzerDevice_majorminor);
        class_destroy(buzzerDevice_class);
        unregister_chrdev_region(buzzerDevice_majorminor, 1);
        return ret;
    }

    /**< Get GPIO handle remapped to virtual address 
     * ioremap() function is used to map the physical addres of an I/O 
     * device to the kernel virtual address. Kernel creates a page table i.e
     * mapping of virtual address to the physical address requested.
     */
    s_pGpioRegisters = (SGPIORegister *)ioremap(GPIO_BASE, sizeof(SGPIORegister));

    /**< Set timer callback */
    timer_setup(&timer, timer_callback, 0);

    /**< Set as input */
    GPIO_function_select(s_pGpioRegisters, buzzerGpioPin, GPIO_OUTPUT);
    GPIO_write(s_pGpioRegisters,buzzerGpioPin,0);

    return 0;
}

/**
 * @brief Cleanup module
 */
static void __exit buzzerModule_exit(void) {
	
    /**< Set as input */
    GPIO_function_select(s_pGpioRegisters, buzzerGpioPin,GPIO_INPUT);

    /**< Unmap virtual address from page table */
    iounmap(s_pGpioRegisters);

    /**< Cleanup device: reverse init operations */
    cdev_del(&c_dev);
    device_destroy(buzzerDevice_class, buzzerDevice_majorminor);
    class_destroy(buzzerDevice_class);
    unregister_chrdev_region(buzzerDevice_majorminor, 1);
}

/**< Register initialization and cleanup functions */
module_init(buzzerModule_init);
module_exit(buzzerModule_exit);

