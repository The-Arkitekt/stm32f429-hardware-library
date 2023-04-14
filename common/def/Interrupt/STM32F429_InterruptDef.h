#ifndef STM32F429_INTERRUPT_H
#define STM32F429_INTERRUPT_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32.h"

/**
 * External Interrupt Event Registers
 */
typedef	EXTI_TypeDef * EXTI_TYPE;

/**
 * Interrupt positions
 */
typedef IRQn_Type INTERRUPT_POS_TYPE;



#ifdef __cplusplus
}
#endif

#endif //STM32F429_INTERRUPT_H
