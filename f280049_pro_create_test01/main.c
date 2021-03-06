#include "driverlib.h"
#include "device.h"
#include "f28004x_device.h"
void main(void)
{
    // Initialize device clock and peripherals
    Device_init();//test
    // Initialize GPIO and configure the GPIO pin as a push-pull output
    Device_initGPIO();
    GPIO_setPadConfig(DEVICE_GPIO_PIN_LED2, GPIO_PIN_TYPE_STD);
    GPIO_setDirectionMode(DEVICE_GPIO_PIN_LED2, GPIO_DIR_MODE_OUT);
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    Interrupt_initModule();
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    Interrupt_initVectorTable();
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    EINT;
    ERTM;
    // Loop Forever
    for(;;)
    {
        // Turn on LED
//        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 0);
        GpioDataRegs.GPBDAT.bit.GPIO34 = 0;
        // Delay for a bit.
        DEVICE_DELAY_US(50000);
        // Turn off LED
//        GPIO_writePin(DEVICE_GPIO_PIN_LED2, 1);
        GpioDataRegs.GPBDAT.bit.GPIO34 = 1;
        // Delay for a bit.
        DEVICE_DELAY_US(50000);
    }
}
