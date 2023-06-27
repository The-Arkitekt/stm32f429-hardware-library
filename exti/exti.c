#include "exti.h"

void EXTI_set_interrupt_source(const EXTI_LINE_ENUM exti_line, const Boolean set)
{
	if (set == TRUE)
	{
		(*__EXTI_IMR) |= (WORD_TYPE)exti_line;
	}
	else
	{
		(*__EXTI_IMR) &= ~((WORD_TYPE)exti_line);
	}
}

void EXTI_set_event_source(const EXTI_LINE_ENUM exti_line, const Boolean set)
{
	if (set == TRUE)
	{
		(*__EXTI_EMR) |= (WORD_TYPE)exti_line;
	}
	else
	{
		(*__EXTI_EMR) &= ~((WORD_TYPE)exti_line);
	}
}

void EXTI_set_rising_trigger(const EXTI_LINE_ENUM exti_line, const Boolean enable)
{
	if (enable == TRUE)
	{
		(*__EXTI_RTSR) |= (WORD_TYPE)exti_line;
	}
	else
	{
		(*__EXTI_RTSR) &= ~((WORD_TYPE)exti_line);
	}
}

void EXTI_set_falling_trigger(const EXTI_LINE_ENUM exti_line, const Boolean enable)
{
	if (enable == TRUE)
	{
		(*__EXTI_FTSR) |= (WORD_TYPE)exti_line;
	}
	else
	{
		(*__EXTI_FTSR) &= ~((WORD_TYPE)exti_line);
	}
}

void EXTI_trigger_interrupt_event(const EXTI_LINE_ENUM exti_line)
{
	(*__EXTI_SWIER) |= (WORD_TYPE)exti_line;
}

Boolean EXTI_pending_request_exists(const EXTI_LINE_ENUM exti_line)
{
	Boolean request_pending = FALSE;

	if ((exti_line & (*__EXTI_PR)) != 0U)
	{
		request_pending = TRUE;
	}

	return request_pending;
}

void EXTI_clear_pending_request(const EXTI_LINE_ENUM exti_line)
{
	// request is cleared by setting bit to 1
	(*__EXTI_PR) |= (WORD_TYPE)exti_line;
}
