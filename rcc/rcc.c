#include "rcc.h"

void RCC_set_AHB1_clock_enable(const RCC_AHB1_FIELDS_ENUM peripheral,
							   const RCC_AHB1ENR_VALUE_ENUM value)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(RCC + __RCC_AHB1ENR_OFFSET);

	// Clear and set the desired field
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(peripheral);
	tmp |= (peripheral & value);
	(*register_ptr) = tmp;
}
