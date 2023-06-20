#include "syscfg.h"

void SYSCFG_set_EXTI_source(const SYSCFG_EXTI_LINE_ENUM exti, const SYSCFG_GPIO_PORT_ENUM gpio)
{
	// Clear and set register
	WORD_TYPE tmp = (*__SYSCFG_EXTICR_REGISTERS[((WORD_TYPE)exti & 0x3UL)]);
	tmp &= ~(__SYSCFG_EXTI_MSK << (((WORD_TYPE)exti & 0x3UL) << 2));
	tmp |= ((BYTE_TYPE)gpio << (((WORD_TYPE)exti & 0x3UL) << 2));
	(*__SYSCFG_EXTICR_REGISTERS[((WORD_TYPE)exti & 0x3UL)]) = tmp;
}