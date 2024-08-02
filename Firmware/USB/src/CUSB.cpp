#include "CUSB.h"
#include <iostream>
#include <cstring>
#include <sys/mount.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * @brief Construct a new CUSB object
 */
CUSB::CUSB()
{
    m_MountFolder = "/media/usb";                                            /** Folder where the USB will be mounted */
    this->m_Dir = opendir(m_MountFolder.c_str());
    if (!this->m_Dir)                                                        /* If the folder doesn't exist, create it */
        mkdir(m_MountFolder.c_str(), 777);
    else
        closedir(this->m_Dir);
    this->m_udev = udev_new();                                               /* Create the udev object */
    this->m_IsMounted = false;                                               /* Set the USB as not mounted */
    firstMount();                                                           /* Check if the usb is already plugged*/

    /* Prepare the udev monitor */
    m_Monitor = udev_monitor_new_from_netlink(this->m_udev, "udev");          /* Create a monitor */
    udev_monitor_filter_add_match_subsystem_devtype(m_Monitor,"block", NULL);/* Only include devices that have the subsystem attribute set to 'block'. */
    udev_monitor_enable_receiving(m_Monitor);                                /* Enable receiving messages from the kernel */
    m_fd = udev_monitor_get_fd(m_Monitor);                                    /* Get the file descriptor */
}

/**
 * @brief Destroy the CUSB object
 */
CUSB::~CUSB()
{
    udev_unref(this->m_udev);                                                /* Free the udev object */     
}

/**
 * @brief Check if exist a USB plugged
 * @details This function checks if exist a USB plugged and calls the mount function
 */
void CUSB::firstMount()
{
    struct udev_device *device;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *dev_list_entry;
    enumerate = udev_enumerate_new(this->m_udev);                            /* Create a list of the devices*/
    udev_enumerate_add_match_subsystem(enumerate, "block");                 /* Only include devices that have the subsystem attribute set to 'block'. */
    udev_enumerate_scan_devices(enumerate);                                 /* Scan the system and create a list of devices in 'enumerate'. */
    devices = udev_enumerate_get_list_entry(enumerate);                     /* Get the list entry */
    udev_list_entry_foreach(dev_list_entry, devices)                        /* For each item enumerated*/
    {
        const char *path;
        path = udev_list_entry_get_name(dev_list_entry);                    /* Get the filename */
        device = udev_device_new_from_syspath(this->m_udev, path);           /* Get the udev device */
        m_DeviceNode = udev_device_get_devnode(device);                      /* Get the device node */
        if (strstr(m_DeviceNode.c_str(), "/dev/sd") != NULL)                 /* If the device node contains "sd" */
            USBmount();
    }
}

/**
 * @brief Mounts the USB device
 * @details This function mounts the USB device to the folder /media/usb
 */
void CUSB::USBmount()
{
    /**< Create folder where the USB will be mounted */
    std::string folder(this->m_MountFolder + this->m_DeviceNode.substr(this->m_DeviceNode.find_last_of("/")));
    this->m_Dir = opendir(folder.c_str());                                   /**< Check if the folder exists */
    if (!this->m_Dir)                                                        /**< If the folder doesn't exist, create it */
        mkdir(folder.c_str(), 777);
    else
        closedir(this->m_Dir);
    if(mount(this->m_DeviceNode.c_str(), folder.c_str(), "vfat", MS_MGC_VAL, NULL) == -1) 
        rmdir(folder.c_str());                                                  
    else
        m_IsMounted = true;                                                  /**< Set the flag to true */

}
        

/**
 * @brief Unmounts the USB device
 * @details This function unmounts the USB device from the folder /media/usb
 */
void CUSB::USBumount()
{
    
    std::string folder(this->m_MountFolder + this->m_DeviceNode.substr(this->m_DeviceNode.find_last_of("/")));
    this->m_Dir = opendir(folder.c_str());
    if(this->m_Dir)                                                             /**< If the folder exists */
    {
        closedir(this->m_Dir);                                                  /**< Close the folder */
        umount(folder.c_str());                                                 /**< Unmount the USB */
        rmdir(folder.c_str());                                                  /**< Delete the folder */
        m_IsMounted = false;                                                    /**< Set the flag to false */
    }
}

/**
 * @brief Monitors the USB device
 * @details This function monitors the USB device and calls the mount and unmount functions 
 * @return std::string Device node
 */
std::string CUSB::monitor()
{   
    fd_set fds; 
    FD_ZERO(&fds);
    FD_SET(m_fd, &fds);
    int ret = select(m_fd+1, &fds, NULL, NULL, NULL);                           /**< Wait for an event */
    if (ret > 0 && FD_ISSET(m_fd, &fds))                                        /**< If there is an event */
    {
        this->m_Device = udev_monitor_receive_device(m_Monitor);                /**< Get the device */
        if (this->m_Device)                                                     /**< If there is a device */
        {
            const char *action = udev_device_get_action(this->m_Device);        /**< Get the action */
            m_DeviceNode = udev_device_get_devnode(this->m_Device);             /**< Get the device node */
            if (strcmp(action, "add") == 0)                                     /**< If the action is add, mount the USB */
                USBmount();
            else if (strcmp(action, "remove") == 0)                             /**< If the action is remove, unmount the USB */
                USBumount();
            udev_device_unref(this->m_Device);                                  /**< Unref the device */
            return m_DeviceNode;                                                /**< Return the device node */
        }
    }
    return "";
}

/**
 * @brief Checks if the USB device is mounted
 * @return true 
 * @return false 
 */
bool CUSB::isMounted()
{
    return this->m_IsMounted;    
}
