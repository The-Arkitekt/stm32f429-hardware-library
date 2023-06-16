#include "nvic.h"

void NVIC_enable_IRQ(const INTERRUPT_VECTOR_ENUM irq)
{
	(*__NVIC_ISER[((WORD_TYPE)irq) >> 5UL]) |= (WORD_TYPE)(1UL << (((WORD_TYPE)irq) & 0x1FUL));
}

void NVIC_disable_IRQ(const INTERRUPT_VECTOR_ENUM irq)
{
	(*__NVIC_ICER[((WORD_TYPE)irq) >> 5UL]) &= (WORD_TYPE)(1UL << (((WORD_TYPE)irq) & 0x1FUL));
}


