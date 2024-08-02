#include "CSingleton.h"

/**
 * @brief Initialize the instance to nullptr
 */
Singleton* Singleton::instance = nullptr;

/**
 * @brief Construct a new Singleton object
 */
Singleton::Singleton()
    : buzzer("/root/EasyHealthy/DeviceDrivers/buzzer.ko")
{ }

/**
 * @brief Get the unique instance 
 * @return Singleton* 
 */
Singleton* Singleton::getInstance()
{
    if (instance == nullptr)
        instance = new Singleton();
    return instance;
}

/**
 * @brief Reset function
 */
void Singleton::reset()
{
    instance = Singleton::getInstance();
}