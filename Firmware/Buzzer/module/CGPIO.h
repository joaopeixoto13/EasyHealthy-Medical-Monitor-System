#ifndef CGPIO_H
#define CGPIO_H
#include <linux/types.h>

/**
 * @brief GPIO class definition
 * @details Provides a set of functions to manage the GPIO
 */
#define BCM2708_PERI_BASE       0xfe000000
#define GPIO_BASE (BCM2708_PERI_BASE + 0x200000)

/**
 * @brief GPIO pin mode enumerate
 */
typedef enum EFUNTCIONCODE
{
    GPIO_INPUT = 0,
    GPIO_OUTPUT = 1,
    GPIO_ALT0 = 4,
    GPIO_ALT1 = 5,
    GPIO_ALT2 = 6,
    GPIO_ALT3 = 7,
    GPIO_ALT4 = 3,
    GPIO_ALT5 = 2
} EFunctionCode;

/**
 * @brief GPIO Registers
 */
typedef struct GPIOREGISTER
{
    uint32_t GPFSEL[6];
    uint32_t Reserved1;
    uint32_t GPSET[2];
    uint32_t Reserved2;
    uint32_t GPCLR[2];
    uint32_t Reserved3;
    uint32_t GPLEV[2];
    uint32_t Reserved4;
    uint32_t GPEDS[2];
    uint32_t Reserved5;
    uint32_t GPREN[2];
    uint32_t Reserved6;
    uint32_t GPFEN[2];
    uint32_t Reserved7;
    uint32_t GPHEN[2];
    uint32_t Reserved8;
    uint32_t GPLEN[2];
    uint32_t Reserved9;
    uint32_t GPAREN[2];
    uint32_t Reserved10;
    uint32_t GPAFEN[2];
    uint32_t Reserved11;
    uint32_t GPPUD;
    uint32_t GPPUDCLK[2];
} SGPIORegister;

void GPIO_function_select(SGPIORegister * GpioRegister,int GPIO, EFunctionCode functionCode);
void GPIO_write(SGPIORegister * GpioRegister,int GPIO, int outputValue);
int GPIO_read(SGPIORegister * GpioRegister,int GPIO);

#endif
