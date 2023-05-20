#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "gpioTypes.h"

/**
 * This constant is calculated using the following formula:
 * 	num_gpio_pins / ((log_2(num_AF_modes) * num_gpio_pins) / bits_per_register)
*/
static const BYTE_TYPE NUM_PINS_PER_AFR_REG = 8U;	/* !< The number of pins that are represented in each AFR register*/

//@{
/**
 * Gpio port disable/enable
 * @param portSelect The port to be disabled/enabled
*/
void gpioEnable(const GpioPortSelect portSelect);
void gpioDisable(const GpioPortSelect portSelect);
//@}

/**
 * Set digital output of given port-pin combination
 * @param portSelect The port name where the target pin is located
 * @param pinSelect The target pin number
 * @param value If True, set pin high, else set pin low
*/
void gpioWrite(const GpioPortSelect portSelect, const GpioPinSelect pinSelect, const Boolean value);

/**
 * Read current digital value of given port-pin combination
 * @param portSelect The port name where the target pin is located
 * @param pinSelect The target pin name
 * @return True if pin is high, False otherwise
*/
Boolean gpioRead(const GpioPortSelect portSelect, const GpioPinSelect pinSelect);

/**
 * Configure a given GPIO port
 * @param gpioConfig The GpioConfig struct used to configure the gpio
*/
void gpioConfigure(const GpioConfigStruct gpioConfig);

#ifdef __cplusplus
}
#endif

#endif //GPIO_H
