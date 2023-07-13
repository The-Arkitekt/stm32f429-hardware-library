#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * Constant Definitions
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

static const uint8_t GPIO_ALT_FUNC_DECODE_SHFT_AMT = 4U;
/**
 * Indexing Enum Definitions
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
	GPIO_PORT_MAX_VALUE
}gpio_port_enum;

typedef enum
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
	GPIO_PIN_15,
	GPIO_PIN_MAX_VALUE
}gpio_pin_enum;

typedef enum
{
	GPIO_ALT_FUNC_REGISTER_LOW = 0U,
	GPIO_ALT_FUNC_REGISTER_HIGH,
	GPIO_ALT_FUNCTION_REGISTER_MAX_VALUE
}gpio_alt_function_register_enum;

/**
 * Bit Mask Enum Definitions
*/
typedef enum
{
	GPIO_MODE_INPUT     = 0U,
	GPIO_MODE_OUTPUT    = 0x1U,
	GPIO_MODE_ALTERNATE = 0x2U,
	GPIO_MODE_ANALOG    = 0x3U,
}gpio_mode_enum;

typedef enum
{
	GPIO_OUTPUT_PUSH_PULL  = 0U,
	GPIO_OUTPUT_OPEN_DRAIN = 0x1U
}gpio_output_type_enum;

typedef enum
{
	GPIO_OUTPUT_SPEED_LOW       = 0U,
	GPIO_OUTPUT_SPEED_MED       = 0x1U,
	GPIO_OUTPUT_SPEED_HIGH      = 0x2U,
	GPIO_OUTPUT_SPEED_VERY_HIGH = 0x3U,
}gpio_output_speed_enum;

typedef enum
{
	GPIO_NO_PULL            = 0U,
	GPIO_PULL_UP            = 0x1U,
	GPIO_PULL_DOWN          = 0x2U,
	GPIO_PULL_RESERVED_MASK = 0x3U
}gpio_pull_up_down_enum;

typedef enum
{
	//AF0: SYS functions

	//AF1: TIM 1/2 functions

	//AF2: TIM 3/4/5 functions

	//AF3: TIM 8/9/10/11 functions

	//AF4: I2C 1/2/3 functions

	//AF5: SPI 1/2/3/4/5/6 functions

	//AF6: SPI 2/3, SAI 1 functions

	//AF7: SPI 3, USART 1/2/3 functions

	//AF8: USART 6, UART 4/5/7/8 functions

	//AF9: CAN 1/2, TIM 12/13/14, LCD functions

	//AF10: OTG2_HS, OTG1_FS functions

	//AF11: ETH functions

	//AF12: FMC, SDIO, OTG2_FS functions

	//AF13: DCMI functions

	//AF14: LCD functions

	//AF15: SYS functions
	GPIO_AF_EVENT_OUT = 0xF0U,

	GPIO_AF_INV
}gpio_alternate_function_enum;

/**
 * Interface Struct Definitions
 */
typedef struct
{
	gpio_mode_enum         mode;
	gpio_output_type_enum  outputType;
	gpio_output_speed_enum outputSpeed;
	gpio_pull_up_down_enum pullUpDown;
}gpio_port_config_interface_t;

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
	uint32_t alternateFunction[GPIO_ALT_FUNCTION_REGISTER_MAX_VALUE];
}gpio_port_reg_t;

/**
 * Register Pointer Constants
 */
static gpio_port_reg_t volatile * const GPIO_REGS[GPIO_PORT_MAX_VALUE] =
{
	(gpio_port_reg_t*)GPIO_A_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_B_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_C_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_D_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_E_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_F_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_G_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_H_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_I_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_J_BASE_ADDR,
	(gpio_port_reg_t*)GPIO_K_BASE_ADDR
};

/**
 * Function Prototypes
 */


#ifdef __cplusplus
}
#endif

#endif //GPIO_H

