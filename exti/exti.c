#include "exti.h"
#include "null.h"

void setExtiLineInterruptMask(const BYTE_TYPE extiLine, const Boolean value)
{
	if (extiLine <= EXTI_LINE_MAX)
	{
		WORD_TYPE tmp = EXTI->IMR;
		tmp &= ~(1U << (BYTE_TYPE)extiLine);
		tmp |= ((BYTE_TYPE)value << (BYTE_TYPE)extiLine);

		EXTI->IMR = tmp;
	}
}

Boolean readExtiLineInterruptMask(const BYTE_TYPE extiLine, Boolean* const out)
{	
	Boolean success = FALSE;
	if ((extiLine <= EXTI_LINE_MAX) && (out != NULL))
	{
		(*out) = (((EXTI->IMR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
		success = TRUE;
	}

	return success;
}

void setExtiLineEventMask(const BYTE_TYPE extiLine, const Boolean value)
{
	if (extiLine <= EXTI_LINE_MAX)
	{
		WORD_TYPE tmp = EXTI->EMR;
		tmp &= ~(1U << (BYTE_TYPE)extiLine);
		tmp |= ((BYTE_TYPE)value << (BYTE_TYPE)extiLine);
		
		EXTI->EMR = tmp;
	}
}

Boolean readExtiLineEventMask(const BYTE_TYPE extiLine, Boolean* const out)
{
	Boolean success = FALSE;
	if ((extiLine <= EXTI_LINE_MAX) && (out != NULL))
	{
		(*out) = (((EXTI->EMR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
		success = TRUE;
	}

	return success;
}

void setExtiLineTrigger(const BYTE_TYPE extiLine, const ExtiLineTriggerSelect trigger,
					    const Boolean value)
{
	if (extiLine <= EXTI_LINE_MAX)
	{
		if (trigger == EXTI_FALLING_TRIGGER)
		{
			(EXTI->FTSR)  |= (1U << (BYTE_TYPE)extiLine);
		}
		else
		{
			(EXTI->RTSR) |= (1U << (BYTE_TYPE)extiLine);
		}
	}
}

Boolean readExtiLineTrigger(const BYTE_TYPE extiLine, const ExtiLineTriggerSelect trigger, Boolean* const out)
{
	Boolean success = FALSE;
	if ((extiLine <= EXTI_LINE_MAX) && (out != NULL))
	{
		if (trigger == EXTI_FALLING_TRIGGER)
		{
			(*out) = (((EXTI->FTSR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;

		}
		else
		{
			(*out) = (((EXTI->RTSR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
		}

		success = TRUE;
	}

	return success;
}

void requestExtiLineInterrupt(const BYTE_TYPE extiLine)
{
	if (extiLine <= EXTI_LINE_MAX)
	{
		EXTI->SWIER |= (1U << (BYTE_TYPE)extiLine);
	}
}

Boolean isExtiLineInterruptRequestPending(const BYTE_TYPE extiLine, Boolean* const out)
{
	Boolean success = FALSE;
	if ((extiLine <= EXTI_LINE_MAX) && (out != NULL))
	{
		(*out) = (((EXTI->PR >> (BYTE_TYPE)extiLine) & 1U) == 1U) ? TRUE : FALSE;
		success = TRUE;
	}

	return success;
}

void clearPendingExtiLineInterruptRequest(const BYTE_TYPE extiLine)
{
	if (extiLine <= EXTI_LINE_MAX)
	{
		// The pending request bit is cleared by setting it to 1
		EXTI->PR |= (1U << (BYTE_TYPE)extiLine);
	}
}

void enableExtiIrq(const ExtiIrqSelect irqSelect){
	NVIC_EnableIRQ(EXTI_IRQ_NUMS[(BYTE_TYPE)irqSelect]);
}

void disableExtiIrq(const ExtiIrqSelect irqSelect){
	NVIC_DisableIRQ(EXTI_IRQ_NUMS[(BYTE_TYPE)irqSelect]);
}