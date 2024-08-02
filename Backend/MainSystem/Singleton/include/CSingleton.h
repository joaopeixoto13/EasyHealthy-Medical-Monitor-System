#ifndef CSINGLETON_H
#define CSINGLETON_H

#include "CUsers.h"
#include "CEventFSM.h"
#include "CMAX30102.h"
#include "CMLX90614.h"
#include "CBuzzer.h"

/**
 * @brief Singleton class
 * @note Singleton is a creational design pattern, which ensures that only one object 
 * of its kind exists and provides a single point of access to it for any other code.
 */
class Singleton
{
    private:
        static Singleton* instance;                     /**< Handler (Only One Instance) */
        Singleton();                                    /**< Class Constructor (Private) */
        CEventFSM fsm;                                  /**< Event Driven State Machine */
        CUsers users;                                   /**< Users in the system */
        CMAX30102 max30102;                             /**< MAX30102 Sensor */
        CMLX90614 mlx90614;                             /**< MLX90614 Sensor */
        CBuzzer buzzer;                                 /**< Buzzer */

    public:
        static Singleton* getInstance();                /**< Get the Instance */
        static void reset();                            /**< Reset the Handler */

        CEventFSM& getFSM() { return fsm; };            /**< Get the FSM Handler */
        CUsers& getUsers() { return users; };           /**< Get the Users Handler */
        CMAX30102& getMAX30102() { return max30102; };  /**< Get the MAX30102 Handler */
        CMLX90614& getMLX90614() { return mlx90614; };  /**< Get the MLX90614 Handler */
        CBuzzer& getBuzzer() { return buzzer; };        /**< Get the Buzzer Handler */  
};

#endif