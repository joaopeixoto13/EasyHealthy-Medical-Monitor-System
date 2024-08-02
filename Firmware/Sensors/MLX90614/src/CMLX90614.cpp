#include <iostream>
#include "CMLX90614.h"
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <unistd.h>

#define ITERATIONS 200
#define MIN_TEMP 35.0
#define MAX_TEMP 45.0
#define ESTABILIZATION_ERROR 0.025

/**
 * @brief Construct a new CMLX90614 object
 */
CMLX90614::CMLX90614() 
{
    m_path = "/sys/bus/iio/devices/iio:device" + std::to_string(m_iSensorCount-1);
    system("modprobe mlx90614");
    usleep(10000);
    /* Callibration */
    m_offset = 3.5;
}

/**
 * @brief Destroy the CMLX90614 object
 */
CMLX90614::~CMLX90614()
{
    system("rmmod mlx90614");
}

/**
 * @brief Read the sensor
 * @details Read the sensor and return the object temperature
 * @return int Temperature
 */
float CMLX90614::readData()
{
    std::ifstream data(m_path + "/in_temp_object_raw");
    std::cout << m_path << std::endl;
    std::string line;
    float temp = 0.0;
    float temp_aux = 0.0;
    float temp_sum = 0.0;
    float temp_prev = 0.0;
    int nsamples = 0;

    while(temp < MIN_TEMP || temp > MAX_TEMP || (fabs(temp_prev - temp) > ESTABILIZATION_ERROR))
    {
        if (data.is_open())
        {
            getline(data, line);
            data.close();
            temp_aux = std::stoi(line);
            temp_aux = temp_aux * 0.02 - 273.15 + m_offset;
            temp_sum += temp_aux;
            if (++nsamples == ITERATIONS)
            {
                temp_prev = temp;
                temp = temp_sum / ITERATIONS;
                temp_sum = 0.0;
                nsamples = 0;
            }
        }
        else
            return SENSOR_ERROR;
        data.open(m_path + "/in_temp_object_raw");
    }
    return temp;
}
