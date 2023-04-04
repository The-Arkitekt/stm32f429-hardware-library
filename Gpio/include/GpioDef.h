#ifndef GPIO_DEF_H
#define GPIO_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

/**
 * All definitions are coming for HAL for now
 *
 * If HAL is no longer used, this file will have it's own definitions
 */
#include "stm32f429xx.h"
#include "stdint.h"

// custom types for type safety
typedef GPIO_TypeDef * PORT_TYPE;
typedef uint32_t       PORT_BASE_TYPE;

typedef enum PortSelect{
	PORT_A = 0U,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F,
	PORT_G,
	PORT_H,
	PORT_I,
	PORT_J,
	PORT_K
}PortSelect;

typedef enum PinSelect{
	PIN_0 = 0U,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}PinSelect;

// Pin State values
typedef enum PinState{
	RESET = 0U,
	SET
}PinState;

typedef enum ModeSelect{
	INPUT = 0U,  /* !< Input Floating Mode     */
	OUTPUT,      /* !< Output General Purpose  */
	ALTERNATE,   /* !< Alternate Function Mode */
	ANALOG       /* !< Analog Mode             */
}ModeSelect;

typedef enum OTypeSelect{
	PP = 0U,	/* !< Output Push-Pull  */
	OD   		/* !< Output Open-Drain */
}OTypeSelect;

typedef enum SpeedSelect{
	FREQ_LOW = 0U,
	FREG_MED,
	FREQ_HIGH,
	FREQ_VERY_HIGH,
}SpeedSelect;


typedef enum PullSelect{
	NO_PULL = 0U,
	PULL_UP,
	PULL_DOWN,
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


#endif //GPIO_DEF_H
