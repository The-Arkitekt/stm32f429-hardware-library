#include "exti.h"

void setExtiLineInterruptMask(const ExtiLineSelect extiLine, const Boolean value)
{
	WORD_TYPE tmp = EXTI->IMR;
	tmp &= ~(1U << (BYTE_TYPE)extiLine);
	tmp |= ((BYTE_TYPE)value << (BYTE_TYPE)extiLine);

	EXTI->IMR = tmp;
}

Boolean readExtiLineInterruptMask(const ExtiLineSelect extiLine)
{
	return (((EXTI->IMR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
}

void setExtiLineEventMask(const ExtiLineSelect extiLine, const Boolean value)
{
	WORD_TYPE tmp = EXTI->EMR;
	tmp &= ~(1U << (BYTE_TYPE)extiLine);
	tmp |= ((BYTE_TYPE)value << (BYTE_TYPE)extiLine);
	
	EXTI->EMR = tmp;
}

Boolean readExtiLineEventMask(const ExtiLineSelect extiLine)
{
	return (((EXTI->EMR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
}

void setExtiLineRisingTrigger(const ExtiLineSelect extiLine, const Boolean value)
{
	EXTI->RTSR |= (1U << (BYTE_TYPE)extiLine);
}

Boolean readExtiLineRisingTrigger(const ExtiLineSelect extiLine)
{
	return (((EXTI->RTSR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
}

void setExtiLineFallingTrigger(const ExtiLineSelect extiLine, const Boolean value)
{
	EXTI->FTSR |= (1U << (BYTE_TYPE)extiLine);
}

Boolean readExtiLineFallingTrigger(const ExtiLineSelect extiLine)
{
	return (((EXTI->FTSR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
}

void requestExtiLineInterrupt(const ExtiLineSelect extiLine)
{
	EXTI->SWIER |= (1U << (BYTE_TYPE)extiLine);
}

Boolean isExtiLineInterruptRequestPending(const ExtiLineSelect extiLine)
{
	return (((EXTI->PR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
}

void clearPendingExtiLineInterruptRequest(const ExtiLineSelect extiLine)
{
	// The pending request bit is cleared by setting it to 1
	EXTI->PR |= (1U << (BYTE_TYPE)extiLine);
}

void enableExtiIrq(const ExtiIrqSelect irqSelect){
	NVIC_EnableIRQ(EXTI_IRQ_NUMS[(BYTE_TYPE)irqSelect]);
}

void disableExtiIrq(const ExtiIrqSelect irqSelect){
	NVIC_DisableIRQ(EXTI_IRQ_NUMS[(BYTE_TYPE)irqSelect]);
}