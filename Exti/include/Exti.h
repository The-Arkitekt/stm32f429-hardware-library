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
ReturnCode enableExtiIrq(const IRQ_TYPE irq);
ReturnCode disableExtiIrq(const IRQ_TYPE irq);

Boolean isValidExtiIrq(const IRQ_TYPE irq);
ReturnCode getExtiIrqType(const ExtiLineSelect line, IRQ_TYPE* const irq);

#ifdef __cplusplus
}
#endif

#endif //EXTI_H
