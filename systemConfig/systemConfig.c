#include "systemConfig.h"

void setSystemConfigMemoryRemap(const SystemConfigMemoryRemapFieldSelect field, const BYTE_TYPE value)
{
	BitFieldDetails fieldDetails = SYSCFG_MEMRMP_FIELD_DETAILS[(BYTE_TYPE)field];

	if (value <= fieldDetails.maxValidValue)
	{
		WORD_TYPE tmp = SYSCFG->MEMRMP;
		tmp &= ~(fieldDetails.mask << fieldDetails.position);
		tmp |= (value << fieldDetails.position);

		SYSCFG->MEMRMP;
	}
}

BYTE_TYPE readSystemConfigMemoryRemap(const SystemConfigMemoryRemapFieldSelect field)
{
	WORD_TYPE tmp = SYSCFG->MEMRMP >> SYSCFG_MEMRMP_FIELD_DETAILS[(BYTE_TYPE)field].position;
	BYTE_TYPE out = tmp & SYSCFG_MEMRMP_FIELD_DETAILS[(BYTE_TYPE)field].mask;
	return out;
}

void setSystemConfigPeripheralMode(const SystemConfigPeripheralModeFieldSelect field, 
								   const Boolean value)
{
	if (value == TRUE)
	{
		SYSCFG->PMC &= ~(1U << SYSCFG_PMC_FIELD_POS[(BYTE_TYPE)field]);
	}
	else
	{
		SYSCFG->PMC |= (1U << SYSCFG_PMC_FIELD_POS[(BYTE_TYPE)field]);
	}
}

Boolean readSystemConfigPeripheralMode(const SystemConfigPeripheralModeFieldSelect field)
{
	return (((SYSCFG->PMC >> SYSCFG_PMC_FIELD_POS[(BYTE_TYPE)field]) & 1U) == 1U) ? TRUE : FALSE;
}

void setSystemExternalInterruptSource(const GpioPortSelect port, const BYTE_TYPE pin)
{
	if (pin <= GPIO_PIN_MAX)
	{
		BYTE_TYPE extiRegisterIndex = pin / SYSCFG_EXTICRx_PINS_PER_REGISTER;
		BYTE_TYPE pos = SYSCFG_EXTICRx_BITS_PER_PIN * (pin - (SYSCFG_EXTICRx_PINS_PER_REGISTER * extiRegisterIndex));

		WORD_TYPE tmp = SYSCFG->EXTICR[extiRegisterIndex];
		tmp &= ~(SYSCFG_EXTICRx_FIELD_MASK << pos);
		tmp |= (pin << pos);

		SYSCFG->EXTICR[extiRegisterIndex];
	}
}

Boolean readSystemExternalInterruptSource(const BYTE_TYPE pin, GpioPortSelect* const out)
{
	Boolean success = FALSE;
	if ((out != NULL) && (pin <= GPIO_PIN_MAX))
	{
		BYTE_TYPE extiRegisterIndex = pin / SYSCFG_EXTICRx_PINS_PER_REGISTER;
		BYTE_TYPE pos = SYSCFG_EXTICRx_BITS_PER_PIN * (pin - (SYSCFG_EXTICRx_PINS_PER_REGISTER * extiRegisterIndex));

		BYTE_TYPE extiPortValue = ((SYSCFG->EXTICR[extiRegisterIndex] >> pos) && SYSCFG_EXTICRx_FIELD_MASK);
		if (extiPortValue <= GPIO_PORT_MAX)
		{
			(*out) = (GpioPortSelect)extiPortValue;
			success = TRUE;
		}
		
	}

	return success;
}

void enableSystemConfig()
{
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
}

void disableSystemConfig()
{
	RCC->APB2ENR &= ~(RCC_APB2ENR_SYSCFGEN);
}