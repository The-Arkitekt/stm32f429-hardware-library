#include "exti.h"

void setExtiLineInterruptMask(const ExtiLineSelect extiLine, const Boolean value)
{
	WORD_TYPE tmp = EXTI->IMR;
	tmp &= ~(1U << (BYTE_TYPE)extiLine);
	tmp |= ((BYTE_TYPE)value << (BYTE_TYPE)extiLine);

	EXTI->IMR = tmp;
}

void readExtiLineInterruptMask(const ExtiLineSelect extiLine, Boolean* const out)
{
	if (out != NULL)
	{
		(*out) = (((EXTI->IMR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
	}
}

void setExtiLineEventMask(const ExtiLineSelect extiLine, const Boolean value)
{
	WORD_TYPE tmp = EXTI->EMR;
	tmp &= ~(1U << (BYTE_TYPE)extiLine);
	tmp |= ((BYTE_TYPE)value << (BYTE_TYPE)extiLine);
	
	EXTI->EMR = tmp;
}

void readExtiLineEventMask(const ExtiLineSelect extiLine, Boolean* const out)
{
	if (out != NULL)
	{
		(*out) = (((EXTI->EMR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
	}
}

void setExtiLineRisingTrigger(const ExtiLineSelect extiLine, const Boolean value)
{
	EXTI->RTSR |= (1U << (BYTE_TYPE)extiLine);
}

void readExtiLineRisingTrigger(const ExtiLineSelect extiLine, Boolean* const out)
{
	if (out != NULL)
	{
		(*out) = (((EXTI->RTSR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
	}
}

void setExtiLineFallingTrigger(const ExtiLineSelect extiLine, const Boolean value)
{
	EXTI->FTSR |= (1U << (BYTE_TYPE)extiLine);
}

void readExtiLineFallingTrigger(const ExtiLineSelect extiLine, Boolean* const out)
{
	if (out != NULL)
	{
		(*out) = (((EXTI->FTSR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
	}
}

void requestExtiLineInterrupt(const ExtiLineSelect extiLine)
{
	EXTI->SWIER |= (1U << (BYTE_TYPE)extiLine);
}

Boolean isExtiLineInterruptRequestPending(const ExtiLineSelect extiLine)
{
	Boolean ret = (((EXTI->PR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
	return ret;
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