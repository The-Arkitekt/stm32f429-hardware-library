#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "BitManipulation.h"
#include "ReturnCodesDef.h"
#include "GpioDef.h"
#include "ExtiDef.h"

/*
 * Interrupt Functions
 */
void ExtiInterruptInit(const ExtiConfigStruct exti);
void ExtiInterruptDeinit(const ExtiConfigStruct exti);

void ExtiResetInterrupt(const ExtiLineSelect line);

/*
 *
 * Event Functions
 */
void ExtiEventInit(const ExtiConfigStruct exti);
void ExtiEventDeinit(const ExtiConfigStruct exti);

/*
 * For both
 */
void ExtiTrigger(const ExtiLineSelect line);
void enableExtiIrq(const ExtiIrqSelect irq);
void disableExtiIrq(const ExtiIrqSelect irq);

#ifdef __cplusplus
}
#endif

#endif //EXTI_H
