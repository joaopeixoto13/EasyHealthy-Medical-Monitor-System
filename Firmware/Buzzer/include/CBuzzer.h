#ifndef CBUZZER_H
#define CBUZZER_H

/**
 * @brief Buzzer class
 */
class CBuzzer
{
public:
    CBuzzer(const char* path);      /**< Constructor */
    ~CBuzzer();                     /**< Destructor */
    void beep(int millis);          /**< Turn on the buzzer during millis miliseconds*/
    void turnOn();                  /**< Turn on the buzzer */
    void turnOff();                 /**< Turn off the buzzer */
};
#endif
