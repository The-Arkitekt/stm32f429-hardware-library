
#include "gpio_alt_funcs.h"
#include "gpio.h"

bool gpio_is_alt_func_valid(const gpio_port_enum port, const gpio_pin_enum pin, const gpio_alternate_function_enum alt_func, bool* const is_valid);

bool gpio_set_config(const gpio_port_enum port, const gpio_pin_enum pin, const gpio_port_config_interface_t* const gpio_config_struct)
{
	bool success = true;
	if ((0U == gpio_config_struct) || (GPIO_PORT_MAX_VALUE == port))
	{
		success = false;
	}
	else
	{
		uint32_t volatile tmp_reg = 0U;
		gpio_port_reg_t volatile * const registers_ptr = GPIO_REGS[(uint8_t)port];

		// Set GPIO mode
		tmp_reg = registers_ptr->mode;
		tmp_reg &= ~(GPIO_MODE_MSK << ((uint8_t)pin << 1U));
		tmp_reg |= ((uint32_t)gpio_config_struct->mode << ((uint8_t)pin << 1U));
		registers_ptr->mode = tmp_reg;

		if (registers_ptr->mode != GPIO_MODE_ANALOG)
		{
			// Set Pull up / Pull down register
			tmp_reg = registers_ptr->pullUpDown;
			tmp_reg &= ~(GPIO_PULL_MSK << ((uint8_t)pin << 1U));
			tmp_reg |= ((uint32_t)gpio_config_struct->pullUpDown << ((uint8_t)pin << 1U));
			registers_ptr->pullUpDown = tmp_reg;

			if (registers_ptr->mode != GPIO_MODE_INPUT)
			{
				// Set Output Type
				tmp_reg = registers_ptr->outputType;
				tmp_reg &= ~(GPIO_OUTPUT_TYPE_MSK << (uint8_t)pin);
				tmp_reg |= ((uint32_t)gpio_config_struct->outputType << (uint8_t)pin);
				registers_ptr->outputType = tmp_reg;

				// Set Output Speed
				tmp_reg = registers_ptr->outputSpeed;
				tmp_reg &= ~(GPIO_OUTPUT_SPEED_MSK << ((uint8_t)pin << 1U));
				tmp_reg |= ((uint32_t)gpio_config_struct->outputSpeed << ((uint8_t)pin << 1U));
				registers_ptr->outputSpeed = tmp_reg;

				if (register_ptr->mode == GPIO_MODE_ALTERNATE)
				{
					// Check alt func validity for this port pin combination
					bool isAltFuncValid = false;
					if (!gpio_is_alt_func_valid(port, pin, gpio_config_struct->altFunc, &isAltFuncValid) ||
						!isAltFuncValid)
					{
						success = false
					}
					else
					{
						uint8_t altFuncRegIndex    = (uint8_t)gpio_config_struct->altFunc >> GPIO_ALT_FUNC_INDEX_DECODE_SHFT_AMT;
						uint8_t altFuncNumber      = (uint8_t)gpio_config_struct->altFunc >> GPIO_ALT_FUNC_DECODE_SHFT_AMT;
						uint8_t altFuncBitShiftAmt = (altFuncNumber & GPIO_ALT_FUNC_POSITION_MSK) << GPIO_ALT_FUNC_BIT_SHFT_MULTIPLIER;

						tmp_reg = registers_ptr->alternateFunction[altFuncRegIndex];
						tmp_reg &= ~(GPIO_ALT_FUNC_MSK << altFuncBitShiftAmt);
						tmp_reg |= altFuncNumber << altFuncBitShiftAmt;
						registers_ptr->alternateFunction[altFuncRegIndex] = tmp_reg;
					}
				}
			}
		}
	}

	return success;
}







bool gpio_get_config(const gpio_port_enum port, const gpio_pin_enum pin, const gpio_port_config_interface_t* const gpio_config_struct);

bool gpio_get_pin_state(const gpio_port_enum port, const gpio_pin_enum pin);
void gpio_set_pin_state(const gpio_port_enum port, const gpio_pin_enum pin);










bool gpio_is_alt_func_valid(const gpio_port_enum port, const gpio_pin_enum pin, const gpio_alternate_function_enum alt_func, bool* const is_valid)
{
	bool success = false;
	if ((GPIO_PORT_MAX_VALUE != port) && (alt_func != GPIO_AF_INV) && (0U != is_valid))
	{
		const gpio_valid_alt_funcs_t* const port_validity = GPIO_ALT_FUNCS[(uint8_t)port];
		(*is_valid) = (alt_func == port_validity->valid_alt_functions[(uint8_t)pin][(uint8_t)(alt_func) >> GPIO_ALT_FUNC_DECODE_SHFT_AMT]);

		success = true;
	}

	return success;
}
