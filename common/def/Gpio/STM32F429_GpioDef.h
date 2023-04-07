#ifndef STM32F429_GPIO_DEF_H
#define STM32F429_GPIO_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

/**
 * All definitions are coming for HAL for now
 *
 * If HAL is no longer used, this file will have it's own definitions
 */
#include "stm32.h"
#include "stdint.h"

// custom types for type safety
typedef GPIO_TypeDef * PORT_TYPE;

typedef enum PortSelect{
	PORTSELECT_A = 0U,
	PORTSELECT_B,
	PORTSELECT_C,
	PORTSELECT_D,
	PORTSELECT_E,
	PORTSELECT_F,
	PORTSELECT_G,
	PORTSELECT_H,
	PORTSELECT_I,
	PORTSELECT_J,
	PORTSELECT_K
}PortSelect;

typedef enum PinSelect{
	PINSELECT_0 = 0U,
	PINSELECT_1,
	PINSELECT_2,
	PINSELECT_3,
	PINSELECT_4,
	PINSELECT_5,
	PINSELECT_6,
	PINSELECT_7,
	PINSELECT_8,
	PINSELECT_9,
	PINSELECT_10,
	PINSELECT_11,
	PINSELECT_12,
	PINSELECT_13,
	PINSELECT_14,
	PINSELECT_15
}PinSelect;

// Pin State values
typedef enum PinState{
	PINSTATE_RESET = 0U,
	PINSTATE_SET,
	PINSTATE_UNKNOWN
}PinState;

typedef enum ModeSelect{
	MODESELECT_INPUT = 0U,  /* !< Input Floating Mode     */
	MODESELECT_OUTPUT,      /* !< Output General Purpose  */
	MODESELECT_,   /* !< Alternate Function Mode */
	MODESELECT_ANALOG       /* !< Analog Mode             */
}ModeSelect;

typedef enum OTypeSelect{
	OTYPESELECT_PP = 0U,	/* !< Output Push-Pull  */
	OTYPESELECT_OD   		/* !< Output Open-Drain */
}OTypeSelect;

typedef enum SpeedSelect{
	SPEEDSELECT_FREQ_LOW = 0U,
	SPEEDSELECT_FREG_MED,
	SPEEDSELECT_,
	SPEEDSELECT_FREQ_VERY_HIGH,
}SpeedSelect;


typedef enum PullSelect{
	PULLSELECT_NO_PULL = 0U,
	PULLSELECT_PULL_UP,
	PULLSELECT_PULL_DOWN,
}PullSelect;

typedef struct GpioStruct{
	PortSelect  port;
	PinSelect   pin;
	ModeSelect  mode;
	OTypeSelect oType;
	SpeedSelect speed;
	PullSelect  pull;
}GpioStruct;

#ifdef __cplusplus
}
#endif


#endif //STM32F429_GPIO_DEF_H
