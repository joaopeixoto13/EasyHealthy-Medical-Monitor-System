#include "CMAX30102.h"
#include "CHeartBeat.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <unistd.h>


/**
 * @brief DC component of a vector
 * @param v vector
 * @return float DC component
 */
float dcComponent(std::vector<int> v)
{
    float sum = 0.0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum / v.size();
}

/**
 * @brief AC component of a vector
 * @param v 
 * @return float AC component
 */
float acComponent(std::vector<int> v)
{
    int max = v[0];
    int min = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
            max = v[i];
        else if (v[i] < min)
            min = v[i];
    }
    return fabs(max - min);
}

/**
 * @brief Construct a new CMAX30102 object
 * @details The default data to read is the heartbeat rate
 */
CMAX30102::CMAX30102()
{
    system("modprobe max30102");
    usleep(10000);
    m_path = "/sys/bus/iio/devices/iio:device" + std::to_string(m_iSensorCount-1);
    system(("echo 1 > " + m_path + "/scan_elements/in_intensity_red_en").c_str());
    system(("echo 1 > " + m_path + "/scan_elements/in_intensity_ir_en").c_str());
    m_data = ::HEART_RATE;
}

/**
 * @brief Destroy the CMAX30102 object
 */
CMAX30102::~CMAX30102()
{
    system("rmmod max30102");
}

/**
 * @brief Read the sensor
 * @return int result of the read 
 */
float CMAX30102::readData()
{
    /**< Get data for 8 seconds*/
    system(("echo 1 > " + m_path + "/buffer/enable").c_str());
    system(("timeout 10 cat /dev/" + m_path.substr(m_path.find_last_of("/")+1, m_path.size()) + " > /tmp/max30102_data").c_str());
    system(("echo \"0\" > " + m_path + "/buffer/enable").c_str());
    std::ifstream fdata("/tmp/max30102_data", std::ios::binary);
    std::vector<int> ir;
    std::vector<int> red;
    
    /**< Parse the IR and RED values from the file*/
    while(1)
    {
        std::vector<char> buffer(8);
        fdata.read(buffer.data(), buffer.size());
        if (fdata.gcount() == 8)
        {
            ir.push_back((buffer[2]) | (buffer[1] << 8) | ((buffer[0]& 3) << 16) );
            red.push_back((buffer[6]) | (buffer[5]<<8) | ((buffer[4]& 3) << 16) );
        }
        else
            break;
    }
    /**< Check if data was read with sucess*/
    if(ir.size () == 0)
        return SENSOR_ERROR;
    fdata.close();

    /**< Calculate the heart rate or the SPO2*/
    if (m_data == MAX30102Data_t::HEART_RATE)
    {
        float delta = 10.0/ir.size();
        int beatCount = 0;
        float time = 0.0, lastTime = 0.0, ttime = 0.0;
        CHeartBeat hb;
        for(int i = 0; i < ir.size(); i++)
        {
            if (hb.checkForBeat(ir[i]))             /**< Check for HeartBeat*/
            {
                beatCount++;
                time = i*delta - lastTime;
                ttime += time;
                lastTime = i*delta;        
            }                        
        }
        
        float bpm = 60.0 / (ttime / (float)beatCount);
        std::cout << bpm << std::endl;
        if (bpm > 200.0 || bpm < 40.0)              /**< Check if the BPM is in the range*/
            return SENSOR_ERROR;
        return bpm;                                 /**< Calculate BPM*/
    }
    else if (m_data == MAX30102Data_t::SPO2)
    {
        float spo2, ac_ir, ac_red, dc_ir, dc_red, ratio;

        /**Calculate AC and DC components of the values*/
        dc_ir = dcComponent(ir);               
        dc_red = dcComponent(red);              
        ac_ir = acComponent(ir);                
        ac_red = acComponent(red);

        ratio = (ac_red/dc_red)/(ac_ir/dc_ir);          /**< Calculate the ratio*/
        spo2 = 110 - 25*ratio;                          /**< Calculate the SPO2*/
        if(spo2 > 100 || spo2 < 50)                     /**< Check if the SPO2 is in the range*/         
            return SENSOR_ERROR;
        return spo2;
    }
    return SENSOR_ERROR;
}


/**
 * @brief Select the data to read(heart rate or SPO2)
 * @param measurement 
 */
void CMAX30102::selectDataToRead(int data)
{
    this->m_data = (MAX30102Data_t)data;
}
