#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

/**
 * Address constants
*/
static const uint32_t GPIO_A_BASE_ADDR = 0x40020000U;
static const uint32_t GPIO_B_BASE_ADDR = 0x40020400U;
static const uint32_t GPIO_C_BASE_ADDR = 0x40020800U;
static const uint32_t GPIO_D_BASE_ADDR = 0x40020C00U;
static const uint32_t GPIO_E_BASE_ADDR = 0x40021000U;
static const uint32_t GPIO_F_BASE_ADDR = 0x40021400U;
static const uint32_t GPIO_G_BASE_ADDR = 0x40021800U;
static const uint32_t GPIO_H_BASE_ADDR = 0x40021C00U;
static const uint32_t GPIO_I_BASE_ADDR = 0x40022000U;
static const uint32_t GPIO_J_BASE_ADDR = 0x40022400U;
static const uint32_t GPIO_K_BASE_ADDR = 0x40022800U;

/**
 * Preprocessor defines used for array initialization
 */
#ifndef NUM_GPIO_PORTS
#define NUM_GPIO_PORTS 11U
#endif //NUM_GPIO_PORTS

#ifndef NUM_GPIO_ALT_FUNC_REGS
#define NUM_GPIO_ALT_FUNC_REGS 2U
#endif //NUM_GPIO_ALT_FUNC_REGS

/**
 * Enum Definitions
 */
typedef enum
{
	GPIO_PORT_A = 0U,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D,
	GPIO_PORT_E,
	GPIO_PORT_F,
	GPIO_PORT_G,
	GPIO_PORT_H,
	GPIO_PORT_I,
	GPIO_PORT_J,
	GPIO_PORT_K,
}gpio_port_enum;

/**
 * Bit Mask Constants
 */

/**
 * Interface Struct Definitions
 */

/**
 * Register Struct Definitions
 */
typedef struct
{
	uint32_t mode;
	uint32_t outputType;
	uint32_t outputSpeed;
	uint32_t pullUpDown;
	uint32_t inputData;
	uint32_t outputData;
	uint32_t bitSetReset;
	uint32_t configurationLock;
	uint32_t alternateFunction[NUM_GPIO_ALT_FUNC_REGS]
}gpio_reg_t;

/**
 * Register Pointer Constants
 */
static gpio_reg_t volatile * const GPIO_REGS[NUM_GPIO_PORTS] =
{
	(gpio_reg_t*)GPIO_A_BASE_ADDR,
	(gpio_reg_t*)GPIO_B_BASE_ADDR,
	(gpio_reg_t*)GPIO_C_BASE_ADDR,
	(gpio_reg_t*)GPIO_D_BASE_ADDR,
	(gpio_reg_t*)GPIO_E_BASE_ADDR,
	(gpio_reg_t*)GPIO_F_BASE_ADDR,
	(gpio_reg_t*)GPIO_G_BASE_ADDR,
	(gpio_reg_t*)GPIO_H_BASE_ADDR,
	(gpio_reg_t*)GPIO_I_BASE_ADDR,
	(gpio_reg_t*)GPIO_J_BASE_ADDR,
	(gpio_reg_t*)GPIO_K_BASE_ADDR,
};


/**
 * Function Prototypes
 */

#ifdef __cplusplus
}
#endif

#endif //GPIO_H

