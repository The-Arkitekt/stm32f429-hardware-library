#include "exti.h"

exti_status_enum exti_set_config(const exti_line_enum line, const exti_interface_t* const exti_config_struct)
{
	exti_status_enum return_val = EXTI_STATUS_SUCCESS;
	uint32_t volatile tmp_reg = 0U;

	if (0U == exti_config_struct)
	{
		return_val = EXTI_STATUS_NULL_POINTER_EXCEPTION;
	}
	else
	{
		// Configure rising trigger
		tmp_reg = EXTI_REG->risingTriggerSelect;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= ((exti_config_struct->risingTriggerEnable) && (exti_config_struct->enable)) ? (uint32_t)line : 0U;
		EXTI_REG->risingTriggerSelect = tmp_reg;

		// Configure falling trigger
		tmp_reg = EXTI_REG->fallingTriggerSelect;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= ((exti_config_struct->fallingTriggerEnable) && (exti_config_struct->enable)) ? (uint32_t)line : 0U;
		EXTI_REG->fallingTriggerSelect = tmp_reg;

		// Configure Interrupt mask
		tmp_reg = EXTI_REG->interruptMask;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= ((exti_config_struct->type == EXTI_INTERRUPT) && (exti_config_struct->enable)) ? (uint32_t)line : 0U;
		EXTI_REG->interruptMask = tmp_reg;

		// Configure event mask
		tmp_reg = EXTI_REG->eventMask;
		tmp_reg &= ~((uint32_t)line);
		tmp_reg |= ((exti_config_struct->type == EXTI_EVENT) && (exti_config_struct->enable)) ? (uint32_t)line : 0U;
		EXTI_REG->eventMask = tmp_reg;
	}

	return return_val;
}


