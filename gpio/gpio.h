#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "boolean.h"
#include "register.h"

/**
 * GPIO port selection
*/
typedef enum GpioPortSelect
{
	GPIO_PORTSELECT_A = 0U,
	GPIO_PORTSELECT_B,
	GPIO_PORTSELECT_C,
	GPIO_PORTSELECT_D,
	GPIO_PORTSELECT_E,
	GPIO_PORTSELECT_F,
	GPIO_PORTSELECT_G,
	GPIO_PORTSELECT_H,
	GPIO_PORTSELECT_I,
	GPIO_PORTSELECT_J,
	GPIO_PORTSELECT_K
}GpioPortSelect;

/**
 * Max port number 
*/
static const BYTE_TYPE GPIO_PORT_MAX = 10U;

/**
 * GPIO max pin value
*/
static const BYTE_TYPE GPIO_PIN_MAX = 15U;

/**
 * Number of GPIO pins per port
*/
#ifndef NUM_GPIO_PINS_PER_PORT
	#define NUM_GPIO_PINS_PER_PORT 16U
#endif //NUM_GPIO_PINS_PER_PORT

/**
 * Valid GPIOx_MODER bitfield values
 * 
 * 	MODERy:
 * 		0: Input (reset)
 * 		1: General purpose output mode
 * 		2: Alternate function mode
 * 		3: Analog mode
*/

/**
 * Valid GPIOx_OTYPER bitfield values
 * 
 * 	OTy: 
 * 		0: Output push-pull
 * 		1: Output open-drain
*/

/**
 * Valid GPIOx_OSPEEDR bitfield values
 * 	
 * 	OSPEEDRy:
 * 		0: Low speed
 * 		1: Medium speed
 * 		2: High speed
 * 		3: Very high speed
*/

/**
 * Valid GPIOx_PUPDR bitfield values
 * 
 * 	PUPDRy:
 * 		0: No pull-up, pull-down
 * 		1: Pull-up
 * 		2: Pull-down
 * 		3: reserved (no effect)
*/

/**
 * Valid GPIOx_AFRL / GPIOx_AFRH bitfield values
 * 
 * 	AFRL/AFRH:
 * 		value based on pin value [0-15]
*/
static const BYTE_TYPE NUM_PINS_PER_AFR_REG = 8U;

/**
 * GPIO configuration selection
*/
typedef enum GpioConfigSelect
{
	GPIO_MODE = 0U,				//!< (GPIOx_MODER) The mode of a gpio pin
	GPIO_OUTPUT_TYPE,			//!< (GPIOx_OTYPER) The output type of a gpio pin
	GPIO_OUTPUT_SPEED,			//!< (GPIOx_OSPEEDR) The output speed of a gpio pin
	GPIO_PULL_UP_DOWN,			//!< (GPIOx_PUPDR) The pull up/down resistor setting of a gpio pin
	GPIO_ALTERNATE_FUNCTION		//!< (GPIOx_AFRL / GPIOx_AFRH) The alternate function setting of a gpio pin
}GpioConfigSelect;

/**
 * The number of configuration selections
*/
#ifndef NUM_CONFIG_SELECTS
	#define NUM_CONFIG_SELECTS 5U
#endif //NUM_CONFIG_SELECTS

/**
 * Map GPIO configuration type to bits per pin in it's 
 * respective register
*/
static const BYTE_TYPE GPIO_CONFIG_BITS_PER_PIN[NUM_CONFIG_SELECTS] = 
{
	2U, 1U, 2U, 2U, 4U
};

/**
 * Map GPIO configuration type to max valid value
*/
static const BYTE_TYPE GPIO_CONFIG_MAX[NUM_CONFIG_SELECTS] =
{
	3U, 1U , 3U, 2U, 15U
};

/**
 * Get GPIO Port type from GPIO port type selection
 * @param portSelect The GPIO port selection
 * @return A GPIO Port Typedef pointer
*/
GPIO_TypeDef* getGpioPort(const GpioPortSelect portSelect);

/**
 * Set a configuration for a GPIO pin
 * @param portPtr The port to write to
 * @param pin The pin to configure
 * @param configSelect The configuration type to be set
 * @param value The value to set for the given configuration
*/
void setGpioConfig(GPIO_TypeDef* portPtr, const BYTE_TYPE pin,
				   const GpioConfigSelect configSelect, const BYTE_TYPE value);

/**
 * Read a configuration for GPIO pin
 * @param portPtr The port to read from
 * @param pin The pin to read from
 * @param configSelect The configuration type to read
 * @param[out] out The current pin configuration value
 * @return True if successful, false otherwise
*/
Boolean readGpioConfig(const GPIO_TypeDef* portPtr, const BYTE_TYPE pin,
					   const GpioConfigSelect configSelect, BYTE_TYPE* const out);

/**
 * Set GPIO pin output value
 * @param portPtr The port to write to
 * @param pin The pin to set
 * @param value The boolean value to set
*/
void setGpioPinValue(GPIO_TypeDef* const portPtr, const BYTE_TYPE pin,
				     const Boolean value);

/**
 * Get GPIO pin input value
 * @param portPtr The port to read from
 * @param pin The pin to be read
 * @param[out] out The current pin input value
 * @return True if successful, false otherwise
*/
Boolean readGpioPinValue(const GPIO_TypeDef* const portPtr, const BYTE_TYPE pin,
						 Boolean* const out);

/**
 * Enable RCC clock for GPIO port
 * @param port The port to enable
*/
void gpioEnable(const GpioPortSelect port);

/**
 * Disable RCC clock for GPIO port
 * @param port The port to disable
*/
void gpioDisable(const GpioPortSelect port);

#ifdef __cplusplus
}
#endif

#endif //GPIO_H
 