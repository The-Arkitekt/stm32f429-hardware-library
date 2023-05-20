#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "extiTypes.h"

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
