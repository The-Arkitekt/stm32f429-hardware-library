#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "register.h"

/**
 * SYSCFG REGISTERS
 * 
 * 	- Pointers to specific System Configuration registers
 * 	- SYSCFG base address = 0x4001 3800
 * 	- Only including registers needed for this library
*/
WORD_TYPE* const __SYSCFG_EXTICR_REGISTERS[4U] = 
{
	(WORD_TYPE*)0x40013808UL,	//!< SYSCFG_EXTICR1 register address
	(WORD_TYPE*)0x4001380CUL,	//!< SYSCFG_EXTICR2 register address
	(WORD_TYPE*)0x40013810UL,	//!< SYSCFG_EXTICR3 register address
	(WORD_TYPE*)0x40023814UL	//!< SYSCFG_EXTICR4 register address
};

/**
 * EXTI LINE 
 * 	
 * 	- Only including EXTI lines that are related to SYSCFG
*/
typedef enum SYSCFG_EXTI_LINE_ENUM
{
	SYSCFG_EXTI_LINE_0 = 0U,
	SYSCFG_EXTI_LINE_1,
	SYSCFG_EXTI_LINE_2,
	SYSCFG_EXTI_LINE_3,
	SYSCFG_EXTI_LINE_4,
	SYSCFG_EXTI_LINE_5,
	SYSCFG_EXTI_LINE_6,
	SYSCFG_EXTI_LINE_7,
	SYSCFG_EXTI_LINE_8,
	SYSCFG_EXTI_LINE_9,
	SYSCFG_EXTI_LINE_10,
	SYSCFG_EXTI_LINE_11,
	SYSCFG_EXTI_LINE_12,
	SYSCFG_EXTI_LINE_13,
	SYSCFG_EXTI_LINE_14,
	SYSCFG_EXTI_LINE_15
}SYSCFG_EXTI_LINE_ENUM;
static const BYTE_TYPE __SYSCFG_EXTI_MSK = SYSCFG_EXTI_LINE_15;

/**
 * GPIO PORT
*/
typedef enum SYSCFG_GPIO_PORT_ENUM
{
	SYSCFG_GPIO_PORT_A = 0U,
	SYSCFG_GPIO_PORT_B,
	SYSCFG_GPIO_PORT_C,
	SYSCFG_GPIO_PORT_D,
	SYSCFG_GPIO_PORT_E,
	SYSCFG_GPIO_PORT_F,
	SYSCFG_GPIO_PORT_G,
	SYSCFG_GPIO_PORT_H,
	SYSCFG_GPIO_PORT_I,
	SYSCFG_GPIO_PORT_J,
	SYSCFG_GPIO_PORT_K
}SYSCFG_GPIO_PORT_ENUM;

/**
 * Set the source gpio port as input for given EXTI line
 * 
 * 	- EXTI line corresponds to pin number
 * 	- Only one port can have a given pin number as interrupt/event source 
 *    at a time
 * 	- EX: setting GPIOA and EXTI line 3 means that GPIO port A pin 3
 * 		  is an EXTI interrupt/event source and no other port can have
 *        pin 3 as an interrupt/event source
 */
void SYSCFG_set_EXTI_source(const SYSCFG_EXTI_LINE_ENUM exti, const SYSCFG_GPIO_PORT_ENUM gpio);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //SYSTEM_CONFIG_H