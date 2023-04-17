#ifndef STM32F429_GPIO_DEF_H
#define STM32F429_GPIO_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32.h"

// custom types for type safety
typedef GPIO_TypeDef * GPIO_PORT_TYPE;

typedef enum GpioPortSelect{
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

// Pin State values
typedef enum GpioPinState{
	GPIO_PINSTATE_RESET = 0U,
	GPIO_PINSTATE_SET,
	GPIO_PINSTATE_UNKNOWN
}GpioPinState;

typedef enum GpioModeSelect{
	GPIO_MODESELECT_INPUT = 0U,  /* !< Input Floating Mode     */
	GPIO_MODESELECT_OUTPUT,      /* !< Output General Purpose  */
	GPIO_MODESELECT_ALT ,		 /* !< Alternate Mode          */
	GPIO_MODESELECT_ANALOG       /* !< Analog Mode             */

}GpioModeSelect;

typedef enum GpioAltModeSelect{

	/**
	 * These modes will be different for each port-pin combo
	 * Some will not be valid for port-pin and will have noe
	 * effect if set
	 */
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

typedef enum GpioOTypeSelect{
	GPIO_OTYPESELECT_PP = 0U,	/* !< Output Push-Pull  */
	GPIO_OTYPESELECT_OD   		/* !< Output Open-Drain */
}GpioOTypeSelect;

typedef enum GpioSpeedSelect{
	GPIO_SPEEDSELECT_FREQ_LOW = 0U,
	GPIO_SPEEDSELECT_FREG_MED,
	GPIO_SPEEDSELECT_HIGH,
	GPIO_SPEEDSELECT_FREQ_VERY_HIGH,
}GpioSpeedSelect;


typedef enum GpioPullSelect{
	GPIO_PULLSELECT_NO_PULL = 0U,
	GPIO_PULLSELECT_PULL_UP,
	GPIO_PULLSELECT_PULL_DOWN,
}GpioPullSelect;

typedef struct GpioConfigStruct{
	GpioPortSelect    port;
	GpioPinSelect     pin;
	GpioModeSelect    mode;
	GpioAltModeSelect altMode;
	GpioOTypeSelect   oType;
	GpioSpeedSelect   speed;
	GpioPullSelect    pull;
}GpioConfigStruct;

#ifdef __cplusplus
}
#endif


#endif //STM32F429_GPIO_DEF_H