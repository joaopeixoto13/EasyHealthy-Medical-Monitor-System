#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include "CBuzzer.h"
#include <string>

/**
 * @brief Construct a CBuzzer object
 */
CBuzzer::CBuzzer(const char* path)
{
    std::string strPath = path;
    std::string strPathBuzzer = "insmod " + strPath;
    system(strPathBuzzer.c_str());
}

/**
 * @brief Destroy the CBuzzer object 
 */
CBuzzer::~CBuzzer()
{
    system("rmmod buzzer");
}

/**
 * @brief Turn on the buzzer for a given time
 * @param millis Time in milliseconds
 */
void CBuzzer::beep(int millis)
{
    char str[50];
    sprintf(str, "echo 1 %d > /dev/buzzer0", millis);
    system(str);
}

/**
 * @brief Turn on the buzzer
 */
void CBuzzer::turnOn()
{
    system("echo 1 > /dev/buzzer0");
}

/**
 * @brief Turn off the buzzer
 */
void CBuzzer::turnOff()
{
    system("echo 0 > /dev/buzzer0");
}
