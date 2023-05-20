#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "boolean.h"
#include "register.h"

/**
 * GPIO port selection enum
 * 	Each enum maps to the memory address of the port registers
*/
typedef enum GpioPortSelect{
	GPIO_PORTSELECT_A = (WORD_TYPE)GPIOA_BASE,
	GPIO_PORTSELECT_B = (WORD_TYPE)GPIOB_BASE,
	GPIO_PORTSELECT_C = (WORD_TYPE)GPIOC_BASE,
	GPIO_PORTSELECT_D = (WORD_TYPE)GPIOD_BASE,
	GPIO_PORTSELECT_E = (WORD_TYPE)GPIOE_BASE,
	GPIO_PORTSELECT_F = (WORD_TYPE)GPIOF_BASE,
	GPIO_PORTSELECT_G = (WORD_TYPE)GPIOG_BASE,
	GPIO_PORTSELECT_H = (WORD_TYPE)GPIOH_BASE,
	GPIO_PORTSELECT_I = (WORD_TYPE)GPIOI_BASE,
	GPIO_PORTSELECT_J = (WORD_TYPE)GPIOJ_BASE,
	GPIO_PORTSELECT_K = (WORD_TYPE)GPIOK_BASE
}GpioPortSelect;

/**
 * GPIO pin selection enum
*/
typedef enum GpioPinSelect{
	GPIO_PINSELECT_0 = 0U,
	GPIO_PINSELECT_1,
	GPIO_PINSELECT_2,
	GPIO_PINSELECT_3,
	GPIO_PINSELECT_4,
	GPIO_PINSELECT_5,
	GPIO_PINSELECT_6,
	GPIO_PINSELECT_7,
	GPIO_PINSELECT_8,
	GPIO_PINSELECT_9,
	GPIO_PINSELECT_10,
	GPIO_PINSELECT_11,
	GPIO_PINSELECT_12,
	GPIO_PINSELECT_13,
	GPIO_PINSELECT_14,
	GPIO_PINSELECT_15
}GpioPinSelect;

/**
 * GPIO mode selection enum
*/
typedef enum GpioModeSelect{
	GPIO_MODESELECT_INPUT = 0U,  /* !< Input Floating Mode     */
	GPIO_MODESELECT_OUTPUT,      /* !< Output General Purpose  */
	GPIO_MODESELECT_ALT,		 /* !< Alternate Mode          */
	GPIO_MODESELECT_ANALOG       /* !< Analog Mode             */
}GpioModeSelect;

/**
 * GPIO alternate mode selection enum
 * 	These modes will be different for each port-pin combo
 * 	Some will not be valid for port-pin and will have no
 * 	effect if set
 */
typedef enum GpioAltModeSelect{
	GPIO_MODESELECT_AF_0 = 0U,
	GPIO_MODESELECT_AF_1,
	GPIO_MODESELECT_AF_2,
	GPIO_MODESELECT_AF_3,
	GPIO_MODESELECT_AF_4,
	GPIO_MODESELECT_AF_5,
	GPIO_MODESELECT_AF_6,
	GPIO_MODESELECT_AF_7,
	GPIO_MODESELECT_AF_8,
	GPIO_MODESELECT_AF_9,
	GPIO_MODESELECT_AF_10,
	GPIO_MODESELECT_AF_11,
	GPIO_MODESELECT_AF_12,
	GPIO_MODESELECT_AF_13,
	GPIO_MODESELECT_AF_14,
	GPIO_MODESELECT_AF_15
}GpioAltModeSelect;

/**
 * GPIO output type selection enum
*/
typedef enum GpioOTypeSelect{
	GPIO_OTYPESELECT_PP = 0U,	/* !< Output Push-Pull  */
	GPIO_OTYPESELECT_OD   		/* !< Output Open-Drain */
}GpioOTypeSelect;

/**
 * GPIO speed selection enum
*/
typedef enum GpioSpeedSelect{
	GPIO_SPEEDSELECT_FREQ_LOW = 0U,
	GPIO_SPEEDSELECT_FREG_MED,
	GPIO_SPEEDSELECT_HIGH,
	GPIO_SPEEDSELECT_FREQ_VERY_HIGH,
}GpioSpeedSelect;

/**
 * GPIO pull-up/pull-down resistor selection enum
*/
typedef enum GpioPullSelect{
	GPIO_PULLSELECT_NO_PULL = 0U,	/* !< output is floating */
	GPIO_PULLSELECT_PULL_UP,		/* !< output is pulled up to high */
	GPIO_PULLSELECT_PULL_DOWN,		/* !< output is pulled down to grd */
}GpioPullSelect;

/**
 * GPIO configuration struct
*/
typedef struct GpioConfigStruct{
	GpioPortSelect    port;			/* !< The target port name */
	GpioPinSelect     pin;			/* !< The target pin number */
	GpioModeSelect    mode;			/* !< The desired mode */
	GpioAltModeSelect altMode;		/* !< Only used if mode is set to alternate */
	GpioOTypeSelect   oType;		/* !< The desired output type */
	GpioSpeedSelect   speed;		/* !< The desired speed */
	GpioPullSelect    pull;			/* !< The desired output pull resistor */
}GpioConfigStruct;

#ifdef __cplusplus
}
#endif

#endif //GPIO_TYPES_H
