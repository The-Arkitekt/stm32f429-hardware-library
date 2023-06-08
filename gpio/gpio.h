#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

	//TODO: refactor without stm32fwhatever.h file and using masks for enum values

#include "stm32f429xx.h"
#include "register.h"
#include "Boolean.h"

typedef enum GpioPort
{
	GPIO_PORT_A = GPIOA_BASE,
	GPIO_PORT_B = GPIOB_BASE,
	GPIO_PORT_C = GPIOC_BASE,
	GPIO_PORT_D = GPIOD_BASE,
	GPIO_PORT_E = GPIOE_BASE,
	GPIO_PORT_F = GPIOF_BASE,
	GPIO_PORT_G = GPIOG_BASE,
	GPIO_PORT_H = GPIOH_BASE,
	GPIO_PORT_I = GPIOI_BASE,
	GPIO_PORT_J = GPIOJ_BASE,
	GPIO_PORT_K = GPIOK_BASE,
	GPIO_PORT_INVALID = 0U
}GpioPort;

typedef enum GpioPin
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
	GPIO_PIN_INVALID
}GpioPin;

typedef enum GpioPinState
{
	GPIO_PINSTATE_RESET = 0U,
	GPIO_PINSTATE_SET,
	GPIO_PINSTATE_INVALID
}GpioPinState;

typedef enum GpioMode
{
	GPIO_MODE_INPUT = 0U,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_ALT,
	GPIO_MODE_ANALOG,
	GPIO_MODE_INVALID
}GpioMode;

typedef enum GpioAltFunc
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
	GPIO_ALT_15,
	GPIO_ALT_INVALID
}GpioAltFunc;

typedef enum GpioOutputType
{
	GPIO_OUTPUT_PP = 0U,
	GPIO_OUTPUT_OD,
	GPIO_OUTPUT_INVALID
}GpioOutputType;

typedef enum GpioOutputSpeed
{
	GPIO_SPEED_LOW = 0U,
	GPIO_SPEED_MED,
	GPIO_SPEED_HIGH,
	GPIO_SPEED_VERY_HIGH,
	GPIO_SPEED_INVALID
}GpioOutputSpeed;

typedef enum GpioPull
{
	GPIO_NO_PULL = 0U,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN,
	GPIO_PULL_INVALID
}GpioPull;

typedef struct GpioConfigStruct
{	
	GpioPort        port;
	GpioPin         pin;
	GpioMode        mode;
	GpioAltFunc     altFunc;
	GpioOutputType  oType;
	GpioOutputSpeed oSpeed;
	GpioPull        pull;
}GpioConfigStruct;

static const GpioConfigStruct_default = 
{
	.port    = GPIO_PORT_INVALID,
	.PIN     = GPIO_PIN_INVALID,
	.mode    = GPIO_MODE_INVALID,
	.altFunc = GPIO_ALT_INVALID,
	.oType   = GPIO_OUTPUT_INVALID,
	.oSpeed  = GPIO_SPEED_INVALID,
	.pull    = GPIO_PULL_INVALID
}; 

void GPIO_enable(const GpioPort port);

void GPIO_disable(const GpioPort port);

void GPIO_set_config(const GpioConfigStruct gpio);

void GPIO_set_pin_state(const GpioPort port, const GpioPin pin, const GpioPinState state);

GpioPinState GPIO_get_pin_state(const GpioPort port, const GpioPin pin);

#ifdef __cplusplus
}
#endif

#endif //GPIO_H
 
