#ifndef GPIO_DEF_H
#define GPIO_DEF_H

/**
 * All definitions are coming for HAL for now
 *
 * If HAL is no longer used, this file will have it's own definitions
 */

#include "stm32f429xx.h"
#include "stdint.h"

namespace STM32f429{

namespace GPIO{

// custom types for type safety
typedef GPIO_TypeDef * PORT_TYPE;
typedef uint32_t       CLK_ENABLE_MASK_TYPE;

// constants
const uint8_t NUM_PORTS  = 11U;

// Port Address constants

typedef enum{
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

const PORT_TYPE PORTS[NUM_PORTS] = {
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOI,
	GPIOJ,
	GPIOK
};

const CLK_ENABLE_MASK_TYPE CLK_ENABLE_MASKS[NUM_PORTS] = {
	RCC_AHB1ENR_GPIOAEN,
	RCC_AHB1ENR_GPIOBEN,
	RCC_AHB1ENR_GPIOCEN,
	RCC_AHB1ENR_GPIODEN,
	RCC_AHB1ENR_GPIOEEN,
	RCC_AHB1ENR_GPIOFEN,
	RCC_AHB1ENR_GPIOGEN,
	RCC_AHB1ENR_GPIOHEN,
	RCC_AHB1ENR_GPIOIEN,
	RCC_AHB1ENR_GPIOJEN,
	RCC_AHB1ENR_GPIOKEN
};

typedef enum{
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
	PIN_15,
	PIN_ALL
}PinSelect;

// Pin State values
typedef enum
{
	RESET = 0U,
	SET
}PinState;



typedef enum{
	INPUT = 0U,  /* !< Input Floating Mode     */
	OUTPUT,      /* !< Output General Purpose  */
	ALTERNATE,   /* !< Alternate Function Mode */
	ANALOG       /* !< Analog Mode             */
}ModeSelect;

typedef enum{
	PP = 0U,	/* !< Output Push-Pull  */
	OD   		/* !< Output Open-Drain */
}OTypeSelect;

typedef enum{
	FREQ_LOW = 0U,
	FREG_MED,
	FREQ_HIGH,
	FREQ_VERY_HIGH,
}SpeedSelect;

typedef enum{
	NO_PULL = 0U,
	PULL_UP,
	PULL_DOWN,
}PullSelect;

}

}

#endif //GPIO_DEF_H
