#include "exti.h"

exti_status_enum exti_set_config(const exti_line_enum line, const exti_interface_t* const exti_config_struct)
{
	exti_status_enum status = EXTI_STATUS_NULL_POINTER_EXCEPTION;

	if (0U != exti_config_struct)
	{
		status                    = EXTI_STATUS_SUCCESS;
		uint32_t volatile tmp_reg = 0U;

		// Configure rising trigger
		tmp_reg = EXTI_REG->risingTriggerSelect;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= (exti_config_struct->risingTriggerEnable) ? (uint32_t)line : 0U;
		EXTI_REG->risingTriggerSelect = tmp_reg;

		// Configure falling trigger
		tmp_reg = EXTI_REG->fallingTriggerSelect;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= (exti_config_struct->fallingTriggerEnable) ? (uint32_t)line : 0U;
		EXTI_REG->fallingTriggerSelect = tmp_reg;

		// Configure Interrupt mask
		tmp_reg = EXTI_REG->interruptMask;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= (exti_config_struct->mode == EXTI_MODE_INTERRUPT) ? (uint32_t)line : 0U;
		EXTI_REG->interruptMask = tmp_reg;

		// Configure event mask
		tmp_reg = EXTI_REG->eventMask;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= (exti_config_struct->mode == EXTI_MODE_EVENT) ? (uint32_t)line : 0U;
		EXTI_REG->eventMask = tmp_reg;
	}

	return status;
}

exti_status_enum exti_get_config_status(const exti_line_enum line, exti_interface_t* const exti_config_struct)
{
	exti_status_enum status = EXTI_STATUS_NULL_POINTER_EXCEPTION;

	if (0U != exti_config_struct)
	{
		status = EXTI_STATUS_SUCCESS;

		// Get rising trigger
		exti_config_struct->risingTriggerEnable = (((EXTI_REG->risingTriggerSelect) & (uint32_t)line) != 0U) ? true : false;

		// Get falling trigger
		exti_config_struct->fallingTriggerEnable = (((EXTI_REG->fallingTriggerSelect) & (uint32_t)line) != 0U) ? true : false;

		// Get Type
		if ((((EXTI_REG->interruptMask) & (uint32_t)line) == 0U) &&
			(((EXTI_REG->eventMask) & (uint32_t)line) == 0U))
		{
			exti_config_struct->mode = EXTI_MODE_DISABLED;
		}
		else if ((((EXTI_REG->interruptMask) & (uint32_t)line) != 0U) &&
				 (((EXTI_REG->eventMask) & (uint32_t)line) != 0U))
		{
			exti_config_struct->mode = EXTI_MODE_INVALID;
		}
		else if (((EXTI_REG->interruptMask) & (uint32_t)line) != 0U)
		{
			exti_config_struct->mode = EXTI_MODE_INTERRUPT;
		}
		else
		{
			exti_config_struct->mode = EXTI_MODE_EVENT;
		}
	}

	return status;
}
