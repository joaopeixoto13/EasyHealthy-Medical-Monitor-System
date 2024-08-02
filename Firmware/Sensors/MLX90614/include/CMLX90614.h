#ifndef CMLX90614_H
#define CMLX90614_H
#include "CSensors.h"
#include <string>

/**
 * @brief Class to manage the MLX90614 sensor
 */
class CMLX90614 : public CSensors
{
    std::string m_path;                 /**< Path to the sensor mount folder*/
    float m_offset;                     /**< Offset to the sensor */
    public:
        CMLX90614();                    /**< Constructor */
        ~CMLX90614();                   /**< Destructor */
        float readData();               /**< Read the sensor data */
};
#endif
