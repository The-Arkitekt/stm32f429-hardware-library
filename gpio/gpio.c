#include "gpio.h"

void GPIO_set_mode(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_MODE_ENUM mode)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port | __GPIO_x_MODER_OFFSET);

	// clear and set the bits
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(__GPIO_MODE_MSK << ((BYTE_TYPE)pin << 1U));
	tmp |= ((WORD_TYPE)mode << ((BYTE_TYPE)pin << 1U));
	(*register_ptr) = tmp;
}

void GPIO_set_output_type(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_OUTPUT_TYPE_ENUM o_type)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port + __GPIO_x_OTYPER_OFFSET);

	// clear and set the bits
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(__GPIO_OTYPE_MSK << (BYTE_TYPE)pin);
	tmp |= ((WORD_TYPE)o_type << (BYTE_TYPE)pin);
	(*register_ptr) = tmp;
}

void GPIO_set_output_speed(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_OUTPUT_SPEED_ENUM o_speed)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port + __GPIO_x_OSPEEDR_OFFSET);

	// clear and set the bits
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(__GPIO_OSPEED_MSK << ((BYTE_TYPE)pin << 1U));
	tmp |= ((WORD_TYPE)o_speed << ((BYTE_TYPE)pin << 1U));
	(*register_ptr) = tmp;
}

void GPIO_set_pull(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_PULL_ENUM pull)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port + __GPIO_x_PUPDR_OFFSET);

	// clear and set the bits
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(__GPIO_PUPDR_MSK << ((BYTE_TYPE)pin << 1U));
	tmp |= ((WORD_TYPE)pull << ((BYTE_TYPE)pin << 1U));
	(*register_ptr) = tmp;
}

Boolean GPIO_get_pin_data(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port + __GPIO_x_IDR_OFFSET);

	// Get bit value for given pin
	return ((((*register_ptr) & (1U << (BYTE_TYPE)pin)) != 0U) ? TRUE : FALSE);
}

void GPIO_set_pin_data(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const Boolean data)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port + __GPIO_x_BSRR_OFFSET);

	// Set bit
	if (data == TRUE)
	{
		(*register_ptr) |= (1U << (BYTE_TYPE)pin);
	}
	else
	{
		(*register_ptr) |= (0x10000 << (BYTE_TYPE)pin);
	}
}

void GPIO_set_alt_function(const GPIO_PORT_ENUM port, const GPIO_PIN_ENUM pin, const GPIO_ALT_FUNC_ENUM alt_func)
{
	// Get pointer to register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)port + __GPIO_x_AFR_OFFSET[(((BYTE_TYPE)pin >> 3U) & 1U)]);

	// Clear and set the bits
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(__GPIO_ALT_FUNK_MSK << (((BYTE_TYPE)pin & 0x7U) << 2U));
	tmp |= ((WORD_TYPE)alt_func << (((BYTE_TYPE)pin & 0x7U) << 2U));
	(*register_ptr) = tmp;
}

