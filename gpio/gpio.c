
#include "gpio_alt_funcs.h"
#include "gpio.h"

bool gpio_is_alt_func_valid(const gpio_port_enum port, const gpio_pin_enum pin, const gpio_alternate_function_enum alt_func, bool* const is_valid);












bool gpio_is_alt_func_valid(const gpio_port_enum port, const gpio_pin_enum pin, const gpio_alternate_function_enum alt_func, bool* const is_valid)
{
	bool success = false;
	if ((GPIO_PORT_MAX_VALUE != port) && (GPIO_PIN_MAX_VALUE != pin) && (alt_func != GPIO_AF_INV) && (0U != is_valid))
	{
		const gpio_valid_alt_funcs_t* const port_validity = GPIO_ALT_FUNCS[(uint8_t)port];
		(*is_valid) = (alt_func == port_validity->valid_alt_functions[(uint8_t)pin][(uint8_t)(alt_func) >> GPIO_ALT_FUNC_DECODE_SHFT_AMT]);

		success = true;
	}

	return success;
}
