#include "rcc.h"

void RCC_enable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral)
{
	(*__RCC_AHB1ENR) |= (WORD_TYPE)peripheral;
}

void RCC_disable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral)
{
	(*__RCC_AHB1ENR) &= ~((WORD_TYPE)peripheral);
}
