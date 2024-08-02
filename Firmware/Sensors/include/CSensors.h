#ifndef CSENSORS_H
#define CSENSORS_H

#define SENSOR_ERROR -1

/**
 * @brief Class to manage the sensors
 */
class CSensors
{
    protected:
        static int m_iSensorCount;                  /**< Number of sensors */
    public:
        CSensors();                                 /**< Constructor */
        ~CSensors();                                /**< Destructor */          
        virtual float readData() = 0;               /**< Read the sensor data */
        virtual void selectDataToRead(int);         /**< Select the data to read */
};

#endif