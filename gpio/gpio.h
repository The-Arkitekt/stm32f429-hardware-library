#ifndef GPIO_HH
#define GPIO_HH

#ifdef __cplusplus
	extern "C" {
#endif

#include "register.h"
#include "Boolean.h"

/**
 * GPIO PORT REGISTERS
 *
 * 	- Base address of the GPIO port registers
 */
typedef enum GPIO_PORT_ENUM
{
	GPIO_A = 0UL,
	GPIO_B = 0x40020400UL,
	GPIO_C = 0x40020800UL,
	GPIO_D = 0x40020C00UL,
	GPIO_E = 0x40021000UL,
	GPIO_F = 0x40021400UL,
	GPIO_G = 0x40021800UL,
	GPIO_H = 0x40021C00UL,
	GPIO_I = 0x40022000UL,
	GPIO_J = 0x40022400UL,
	GPIO_K = 0x40022800UL
}GPIO_PORT_ENUM;

/**
 * GPIO PORT REGISTER OFFSETS
 *
 * 	- Add to GPIO_x address to get specific register address
 */
static const BYTE_TYPE __GPIO_x_MODER_OFFSET   = 0UL;	 //!< Gpio pin mode register
static const BYTE_TYPE __GPIO_x_OTYPER_OFFSET  = 0x04UL; //!< Gpio pin output type register
static const BYTE_TYPE __GPIO_x_OSPEEDR_OFFSET = 0x08UL; //!< Gpio pin output speed register
static const BYTE_TYPE __GPIO_x_PUPDR_OFFSET   = 0x0CUL; //!< Gpio pin pull up/dwn register
static const BYTE_TYPE __GPIO_x_IDR_OFFSET     = 0x10UL; //!< Gpio pin input data register
static const BYTE_TYPE __GPIO_x_BSRR_OFFSET    = 0x18UL; //!< Gpio set/reset register
static const BYTE_TYPE __GPIO_x_AFR_OFFSET[2U] =
{
	0x20UL, //!< Gpio alternate function low register  (ports 0-7)
	0x24UL  //!< Gpio alternate function high register (ports 8-15)
};

/**
 * GPIO PINS
 *
 * 	- Masks used to set or clear register bits
 */
typedef enum GPIO_PIN_ENUM
{
	GPIO_PIN_0 = 0U,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
}GPIO_PIN_ENUM;

/**
 * GPIO MODES
 *
 * 	- Masks used to set mode of Gpio pin
 */
typedef enum GPIO_MODE_ENUM
{
	GPIO_MODE_INPUT  = 0U,
	GPIO_MODE_OUTPUT = 0x1U,
	GPIO_MODE_ALT    = 0x2U,
	GPIO_MODE_ANALOG = 0x3UL
}GPIO_MODE_ENUM;
static const BYTE_TYPE __GPIO_MODE_MSK = (BYTE_TYPE)GPIO_MODE_ANALOG;


/**
 * GPIO OUTPUT TYPES
 *
 * 	- Masks used to set output type of Gpio pin
 */
typedef enum GPIO_OUTPUT_TYPE_ENUM
{
	GPIO_OUTPUT_PP = 0U,			   //!< Push-Pull
	GPIO_OUTPUT_OD = 0x1UL  //!< Open-Drain
}GPIO_OUTPUT_TYPE_ENUM;
static const BYTE_TYPE __GPIO_OTYPE_MSK = (BYTE_TYPE)GPIO_OUTPUT_OD;


/**
 * GPIO OUTPUT SPEED
 *
 * 	- Masks used to set output speed of Gpio pin
 */
typedef enum GPIO_OUTPUT_SPEED_ENUM
{
	GPIO_SPEED_LOW       = 0U,
	GPIO_SPEED_MED       = 0x1U,
	GPIO_SPEED_HIGH 	 = 0x2U,
	GPIO_SPEED_VERY_HIGH = 0x3UL
}GPIO_OUTPUT_SPEED_ENUM;
static const BYTE_TYPE __GPIO_OSPEED_MSK = (BYTE_TYPE)GPIO_SPEED_VERY_HIGH;


/**
 * GPIO PULL UP/DOWN
 *
 * 	- Masks used to set pull up/dwn on a pin
 */
typedef enum GPIO_PULL_ENUM
{
	GPIO_NO_PULL   = 0U,
	GPIO_PULL_UP   = 0x1U,
	GPIO_PULL_DOWN = 0x2U
}GPIO_PULL_ENUM;
static const BYTE_TYPE __GPIO_PUPDR_MSK = 0x3UL;


/**
 * GPIO ALTERNATE FUNCTIONS
 *
 * 	- Masks used to set Alternate function
 * 	- Only has effect if Alt mode is selected
 */
typedef enum GPIO_ALT_FUNC_ENUM
{
	GPIO_ALT_0 = 0U,
	GPIO_ALT_1,
	GPIO_ALT_2,
	GPIO_ALT_3,
	GPIO_ALT_4,
	GPIO_ALT_5,
	GPIO_ALT_6,
	GPIO_ALT_7,
	GPIO_ALT_8,
	GPIO_ALT_9,
	GPIO_ALT_10,
	GPIO_ALT_11,
	GPIO_ALT_12,
	GPIO_ALT_13,
	GPIO_ALT_14,
	GPIO_ALT_15
}GPIO_ALT_FUNC_ENUM;
static const BYTE_TYPE __GPIO_ALT_FUNK_MSK = (BYTE_TYPE)GPIO_ALT_15;



/**
 * Set mode of given GPIO
 */
void GPIO_set_mode(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_MODE_ENUM mode);

/**
 * Set output type of given GPIO
 */
void GPIO_set_output_type(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_OUTPUT_TYPE_ENUM o_type);

/**
 * Set output speed of given GPIO
 */
void GPIO_set_output_speed(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_OUTPUT_SPEED_ENUM o_dpeed);

/**
 * Set GPIO pull-up/pull-down
 */
void GPIO_set_pull(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_PULL_ENUM pull);

/**
 * Get GPIO pin input data
 */
Boolean GPIO_get_pin_data(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin);

/**
 * Set GPIO pin data
 */
void GPIO_set_pin_data(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const Boolean data);

/**
 * Set GPIO Alternat Function
 */
void GPIO_set_alt_function(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_ALT_FUNC_ENUM alt_func);

#ifdef __cplusplus
}
#endif

#endif //GPIO_HH
 
