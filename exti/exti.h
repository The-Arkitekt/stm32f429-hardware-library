#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif


#include "register.h"
#include "boolean.h"

/**
 * EXTI interrupt request selection
 */
typedef enum ExtiIrqSelect
{
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
static const IRQn_Type EXTI_IRQ_NUMS[NUM_EXTI_IRQS] = 
{
	EXTI0_IRQn, EXTI1_IRQn, EXTI2_IRQn, EXTI3_IRQn,
	EXTI4_IRQn, EXTI9_5_IRQn, EXTI15_10_IRQn
};

/**
 * EXTI line Maximum value
*/
static const BYTE_TYPE EXTI_LINE_MAX = 22U;

/**
 * EXTI Trigger type selection
*/
typedef enum ExtiLineTriggerSelect
{
	EXTI_FALLING_TRIGGER = 0U,
	EXTI_RISING_TRIGGER		
}ExtiLineTriggerSelect;

/**
 * Set interrupt mask for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param value The boolean value to set
*/
void setExtiLineInterruptMask(const BYTE_TYPE extiLine, const Boolean value);

/**
 * Read interrupt mask for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param[out] out The interrupt mask value
 * @return True if successful, false otherwise
*/
Boolean readExtiLineInterruptMask(const BYTE_TYPE extiLine, Boolean* const out);

/**
 * Set event mask for given EXTI line
 * @param extiLine The EXTI line to be modified
 * @param value The boolean value to set
*/
void setExtiLineEventMask(const BYTE_TYPE extiLine, const Boolean value);

/**
 * Read event mask for given EXTI line
 * @param extiLine The EXTI line to read
 * @param [out] out The event mask value
 * @return True if successful, false otherwise
*/ 
Boolean readExtiLineEventMask(const BYTE_TYPE extiLine, Boolean* const out);

/**
 * Set trigger enable field for given EXTI line
 * @param extiLine The Exti Line to be modified
 * @param trigger Either Falling edge or Rising edge
 * @param value The boolean value to set
*/
void setExtiLineTrigger(const BYTE_TYPE extiLine, const ExtiLineTriggerSelect trigger, 
					    const Boolean value);

/**
 * Read trigger enable field for given EXTI line
 * @param extiLine The EXTI line to read
 * @param trigger Either Falling edge or Rising edge
 * @param[out] out The enable field value
 * @return True if successful, false otherwise
*/
Boolean readExtiLineTrigger(const BYTE_TYPE extiLine, const ExtiLineTriggerSelect trigger, 
							Boolean* const out);

/**
 * Trigger an Interrupt request on a given EXTI line
 * @param extiLine The EXTI line to check
*/
void requestExtiLineInterrupt(const BYTE_TYPE extiLine);

/**
 * Check if an interrupt request is pending on a given EXTI line
 * @param extiLine The EXTI line to check
 * @param[out] out The value of the interrupt request bit
 * @return True if successful, false otherwise
*/
Boolean isExtiLineInterruptRequestPending(const BYTE_TYPE extiLine, Boolean* const out);

/**
 * Clear the pending interrupt request on a given EXTI line
 * @param extiLine The EXTI line to clear
*/
void clearPendingExtiLineInterruptRequest(const BYTE_TYPE extiLine);

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
