#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "register.h"
#include "boolean.h"

/**
 * EXTI interrupt request selection
 */
typedef enum ExtiIrqSelect{
	EXTI_IRQSELECT_0 = 0U,	
	EXTI_IRQSELECT_1,
	EXTI_IRQSELECT_2,
	EXTI_IRQSELECT_3,
	EXTI_IRQSELECT_4,
	EXTI_IRQSELECT_9_5,
	EXTI_IRQSELECT_15_10
}ExtiIrqSelect;

/**
 * Number of EXTI IRQs
*/
#ifndef NUM_EXTI_IRQS
	#define NUM_EXTI_IRQS 7U
#endif //NUM_EXTI_IRQS

/**
 * Array of IRQ numbers in vector table
*/
static const IRQn_Type EXTI_IRQ_NUMS[NUM_EXTI_IRQS] = {
	EXTI0_IRQn, EXTI1_IRQn, EXTI2_IRQn, EXTI3_IRQn,
	EXTI4_IRQn, EXTI9_5_IRQn, EXTI15_10_IRQn
};

/**
 * EXTI source line enum
 * 	The RTSR register masks are used here but the RTSR and FTSR are masks are the same
*/
typedef enum ExtiLineSelect{
	EXTI_LINESELECT_NONE = 0U,
	EXTI_LINESELECT_0,
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

/**
 * Set interrupt mask for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param value The boolean value to set
*/
void setExtiLineInterruptMask(const ExtiLineSelect extiLine, const Boolean value);

/**
 * Read interrupt mask for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param out The Boolean pointer to be set with register value
*/
void readExtiLineInterruptMask(const ExtiLineSelect extiLine, Boolean* const out);

/**
 * Set event mask for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param value The boolean value to set
*/
void setExtiLineEventMask(const ExtiLineSelect extiLine, const Boolean value);

/**
 * Read event mask for given EXTI line
 * @param extiLine The EXTI line to read
 * @param out The Boolean pointer to be set with register value
*/ 
void readExtiLineEventMask(const ExtiLineSelect extiLine, Boolean* const out);

/**
 * Set rising trigger enable field for given EXTI line
 * @param extiLine The Exti Line to be modified
 * @param value The boolean value to set
*/
void setExtiLineRisingTrigger(const ExtiLineSelect extiLine, const Boolean value);

/**
 * Read rising trigger enable field for given EXTI line
 * @param extiLine The EXTI line to read
 * @param out The Boolean pointer to be set with register value
*/
void readExtiLineRisingTrigger(const ExtiLineSelect extiLine, Boolean* const out);

/**
 * Set falling trigger enable field for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param value The boolean value to set
*/
void setExtiLineFallingTrigger(const ExtiLineSelect extiLine, const Boolean value);

/**
 * Read falling trigger enable field for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param out The Boolean pointer to be set with register value
*/
void readExtiLineFallingTrigger(const ExtiLineSelect extiLine, Boolean* const out);

/**
 * Trigger an Interrupt request on a given EXTI line
 * @param extiLine The EXTI line to check
*/
void requestExtiLineInterrupt(const ExtiLineSelect extiLine);

/**
 * Check if an interrupt request is pending on a given EXTI line
 * @param extiLine The EXTI line to check
 * @return True if request is pending, false otherwise
*/
Boolean isExtiLineInterruptRequestPending(const ExtiLineSelect extiLine);

/**
 * Clear the pending interrupt request on a given EXTI line
 * @param extiLine The EXTI line to clear
*/
void clearPendingExtiLineInterruptRequest(const ExtiLineSelect extiLine);

/**
 * Enable the given EXTI interrupt request
 * @param irqSelect The IRQ to enable 
*/
void enableExtiIrq(const ExtiIrqSelect irqSelect);

/**
 * Disable the given EXTI interrupt request
 * @param irqSelect THe IRQ to disable
*/
void disableExtiIrq(const ExtiIrqSelect irqSelect);

#ifdef __cplusplus
}
#endif

#endif //EXTI_H
