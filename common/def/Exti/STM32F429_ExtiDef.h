#ifndef STM32F429_EXTI_H
#define STM32F429_EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32.h"
#include "CommonDef.h"

/**
 * External Interrupt Event Registers
 *
 * typedef struct
 *	{
 *	  __IO uint32_t IMR;    !< EXTI Interrupt mask register,            Address offset: 0x00
 *	  __IO uint32_t EMR;    !< EXTI Event mask register,                Address offset: 0x04
 *	  __IO uint32_t RTSR;   !< EXTI Rising trigger selection register,  Address offset: 0x08
 *	  __IO uint32_t FTSR;   !< EXTI Falling trigger selection register, Address offset: 0x0C
 *	  __IO uint32_t SWIER;  !< EXTI Software interrupt event register,  Address offset: 0x10
 *	  __IO uint32_t PR;     !< EXTI Pending register,                   Address offset: 0x14
 *	} EXTI_TypeDef;
 *
 */
typedef	EXTI_TypeDef * EXTI_TYPE;

static const WORD_TYPE EXTI_BASE_ADDR = EXTI_BASE;

/**
 * Interrupt positions Enum
 */
typedef enum ExtiIrqSelect{
	EXTI_IRQSELECT_0     = EXTI0_IRQn,
	EXTI_IRQSELECT_1     = EXTI1_IRQn,
	EXTI_IRQSELECT_2     = EXTI2_IRQn,
	EXTI_IRQSELECT_3     = EXTI3_IRQn,
	EXTI_IRQSELECT_4     = EXTI4_IRQn,
	EXTI_IRQSELECT_9_5   = EXTI9_5_IRQn,
	EXTI_IRQSELECT_15_10 = EXTI15_10_IRQn
}ExtiIrqSelect;

typedef enum ExtiLineSelect{
	EXTI_LINESELECT_0 = 0U,
	EXTI_LINESELECT_1,
	EXTI_LINESELECT_2,
	EXTI_LINESELECT_3,
	EXTI_LINESELECT_4,
	EXTI_LINESELECT_5,
	EXTI_LINESELECT_6,
	EXTI_LINESELECT_7,
	EXTI_LINESELECT_8,
	EXTI_LINESELECT_9,
	EXTI_LINESELECT_10,
	EXTI_LINESELECT_11,
	EXTI_LINESELECT_12,
	EXTI_LINESELECT_13,
	EXTI_LINESELECT_14,
	EXTI_LINESELECT_15,
	EXTI_LINESELECT_16,
	EXTI_LINESELECT_17,
	EXTI_LINESELECT_18,
	EXTI_LINESELECT_19,
	EXTI_LINESELECT_20,
	EXTI_LINESELECT_21,
	EXTI_LINESELECT_22
}ExtiLineSelect;

typedef struct ExtiConfigStruct{
	ExtiLineSelect line;
	Boolean risingTrigger;
	Boolean fallingTrigger;
}ExtiConfigStruct;

#ifdef __cplusplus
}
#endif

#endif //STM32F429_EXTI_H
