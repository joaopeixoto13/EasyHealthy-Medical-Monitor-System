#ifndef CUSB_H
#define CUSB_H
#include <string>
#include <libudev.h>
#include <sys/types.h>
#include <dirent.h>


/**
 * @brief The CUSB class
 * @details This class is used to mount and unmount USB devices.
 */
class CUSB
{
    std::string m_MountFolder;           /**< Folder where the USB will be mounted */
    std::string m_DeviceNode;            /**< Device node */
    struct udev *m_udev;                 /**< The udev object */
    struct udev_device *m_Device;        /**< The device object */
    struct udev_monitor *m_Monitor;      /**< The monitor object */
    int m_fd;                            /**< File descriptor */
    DIR *m_Dir;                          /**< Directory */
    bool m_IsMounted;                    /**< USB mounted flag */
    private:
        void USBmount();
        void USBumount();
    public:
        CUSB();
        ~CUSB();
        void firstMount();
        std::string monitor();
        bool isMounted();
};


#endif