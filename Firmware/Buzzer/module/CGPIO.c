#include "CGPIO.h"
#include <linux/module.h>

/**
 * @brief Sets the function of the GPIO
 * @param GpioRegister Pointer to a GpioRegister struct
 * @param GPIO Pin nr 
 * @param functionCode Code to set 
 */
void GPIO_function_select(SGPIORegister * GpioRegister,int GPIO, EFunctionCode functionCode)
{
    int registerIndex = GPIO / 10;
    int bit = (GPIO % 10) * 3;
    unsigned oldValue = GpioRegister->GPFSEL[registerIndex];
    unsigned mask = 0b111 << bit;

    GpioRegister->GPFSEL[registerIndex] =
        (oldValue & ~mask) | ((functionCode << bit) & mask);
}

/**
 * @brief Write an value to one pin
 * @param GpioRegister Pointer to a GpioRegister struct
 * @param GPIO Pin nr
 * @param outputValue Logical value
 */
void GPIO_write(SGPIORegister * GpioRegister,int GPIO, int outputValue)
{
    if (outputValue)
        GpioRegister->GPSET[GPIO / 32] = (1 << (GPIO % 32));
    else
        GpioRegister->GPCLR[GPIO / 32] = (1 << (GPIO % 32)); 
}

/**
 * @brief Read the value from one pin
 * @param GpioRegister Pointer to a GpioRegister struct
 * @param GPIO Pin nr
 * @return int Value read from the pin
 */
int GPIO_read(SGPIORegister * GpioRegister,int GPIO)
{
    return (GpioRegister->GPLEV[GPIO / 32] & (1 << (GPIO % 32))) & 1;
}
