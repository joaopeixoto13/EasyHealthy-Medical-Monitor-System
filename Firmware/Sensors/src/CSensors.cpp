#include <iostream>
#include "CSensors.h"
#include <unistd.h>


/**
 * @brief Count the number of sensors
 */
int CSensors::m_iSensorCount = 0;

/**
 * @brief Construct a new CSensors object
 * @details Instanciate the modules to i2c communication
 */
CSensors::CSensors()
{
    if (m_iSensorCount == 0)
    {
        system("rmmod i2c_bcm2835");
        system("rmmod max30102");
        system("rmmod mlx90614");
        sleep(1);
        system("modprobe i2c-dev");
        system("modprobe i2c-bcm2835");
        sleep(1);
        system("rmmod max30102");
        system("rmmod mlx90614");
        sleep(1);
    }
    m_iSensorCount++;
}

/**
 * @brief Destroy CSensors object
 * @details Remove the modules to i2c communication
 */
CSensors::~CSensors()
{
    m_iSensorCount--;
    if (m_iSensorCount == 0)
    {
        system("rmmod i2c_bcm2835");
        system("rmmod i2c_dev");
    }
}

/**
 * @brief Select the data to read
 * @details Select the data to read from the sensor
 * @param data Data to read
*/
void CSensors::selectDataToRead(int)
{
}
