#include "rcc.h"

void RCC_enable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral)
{
	(*__RCC_AHB1ENR) |= (WORD_TYPE)peripheral;
}

void RCC_disable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral)
{
	(*__RCC_AHB1ENR) &= ~((WORD_TYPE)peripheral);
}

void RCC_enable_APB2(const RCC_APB2_FIELDS_ENUM peripheral)
{
	(*__RCC_APB2ENR) |= (WORD_TYPE)peripheral;
}

void RCC_disable_APB2(const RCC_APB2_FIELDS_ENUM peripheral)
{
	(*__RCC_APB2ENR) &= ~((WORD_TYPE)peripheral);
}
