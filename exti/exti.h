#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "boolean.h"

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

/**
 * EXTI source line enum
 * 	The RTSR register masks are used here but the RTSR and FTSR are masks are the same
*/
typedef enum ExtiLineSelect{
	EXTI_LINESELECT_0  = EXTI_RTSR_TR0,
	EXTI_LINESELECT_1  = EXTI_RTSR_TR1,
	EXTI_LINESELECT_2  = EXTI_RTSR_TR2,
	EXTI_LINESELECT_3  = EXTI_RTSR_TR3,
	EXTI_LINESELECT_4  = EXTI_RTSR_TR4,
	EXTI_LINESELECT_5  = EXTI_RTSR_TR5,
	EXTI_LINESELECT_6  = EXTI_RTSR_TR6,
	EXTI_LINESELECT_7  = EXTI_RTSR_TR7,
	EXTI_LINESELECT_8  = EXTI_RTSR_TR8,
	EXTI_LINESELECT_9  = EXTI_RTSR_TR9,
	EXTI_LINESELECT_10 = EXTI_RTSR_TR10,
	EXTI_LINESELECT_11 = EXTI_RTSR_TR11,
	EXTI_LINESELECT_12 = EXTI_RTSR_TR12,
	EXTI_LINESELECT_13 = EXTI_RTSR_TR13,
	EXTI_LINESELECT_14 = EXTI_RTSR_TR14,
	EXTI_LINESELECT_15 = EXTI_RTSR_TR15,
	EXTI_LINESELECT_16 = EXTI_RTSR_TR16,
	EXTI_LINESELECT_17 = EXTI_RTSR_TR17,
	EXTI_LINESELECT_18 = EXTI_RTSR_TR18,
	EXTI_LINESELECT_19 = EXTI_RTSR_TR19,
	EXTI_LINESELECT_20 = EXTI_RTSR_TR20,
	EXTI_LINESELECT_21 = EXTI_RTSR_TR21,
	EXTI_LINESELECT_22 = EXTI_RTSR_TR22
}ExtiLineSelect;

/**
 * Struct used to configure EXTI line
*/
typedef struct ExtiConfigStruct{
	ExtiLineSelect line;
	Boolean risingTrigger;
	Boolean fallingTrigger;
}ExtiConfigStruct;

//@{
/**
 * Initialize functions
 * @param exti The configuration struct used to set triggers
 */
void extiInterruptInit(const ExtiConfigStruct exti);
void extiEventInit(const ExtiConfigStruct exti);
//@}

//@{
/**
 * De Initialize functions
 * @param line The exti line to de initialize
*/
void extiInterruptDeinit(const ExtiLineSelect line);
void extiEventDeinit(const ExtiLineSelect line);
//@}

/**
 * Resets the interrupt flag
 * @param line The exti line to be reset
*/
void extiResetInterrupt(const ExtiLineSelect line);

/**
 * Trigger the specified exti line
 * 	works for interrupt and event
 * @param line The exti line to be triggered
*/
void extiTrigger(const ExtiLineSelect line);

//@{
/**
 * Control whether the Exti interrupt is enabled/disabled
 * @param irq The IRQ to be enabled/disabled
*/
void enableExtiIrq(const ExtiIrqSelect irq);
void disableExtiIrq(const ExtiIrqSelect irq);
//@}

#ifdef __cplusplus
}
#endif

#endif //EXTI_H
