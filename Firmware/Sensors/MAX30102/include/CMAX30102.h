#ifndef CMAX30102_H
#define CMAX30102_H
#include "CSensors.h"
#include <string>


/**
 * @brief Type of data that is possible ro read
 */
typedef enum MAX30102EData
{
    HEART_RATE,
    SPO2,
} MAX30102Data_t;


/**
 * @brief Class to manage the MAX30102 sensor
 */
class CMAX30102 : public CSensors
{
    std::string m_path;                     /**< Path to the sensor mount folder*/
    MAX30102Data_t m_data;                  /**< Data to read */
    public:
        CMAX30102();                        /**< Constructor */
        ~CMAX30102();                       /**< Destructor */
        float readData();                   /**< Read the sensor data */
        void selectDataToRead(int);         /**< Select the data to read */
};
#endif
