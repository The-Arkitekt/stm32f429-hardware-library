#include "gpio.h"

GPIO_TypeDef* getGpioPort(const GpioPortSelect portSelect)
{
	return (GPIO_TypeDef*)(GPIOA_BASE + ((BYTE_TYPE)portSelect * (GPIOB_BASE - GPIOA_BASE)));
}

void setGpioConfig(GPIO_TypeDef* portPtr, const GpioPinSelect pin,
				   const GpioConfigSelect configSelect, const BYTE_TYPE value)
{
	if ((portPtr != NULL) && (value <= GPIO_CONFIG_MAX[(BYTE_TYPE)configSelect]))
	{
		WORD_TYPE* configPtr = NULL;
		Boolean alternateHigh = FALSE;

		switch(configSelect)
		{
			case GPIO_MODE:
				configPtr = &(portPtr->MODER);
				break;
			case GPIO_OUTPUT_TYPE:
				configPtr = &(portPtr->OTYPER);
				break;
			case GPIO_OUTPUT_SPEED:
				configPtr = &(portPtr->OSPEEDR);
				break;
			case GPIO_PULL_UP_DOWN:
				configPtr = &(portPtr->PUPDR);
				break;
			case GPIO_ALTERNATE_FUNCTION:
				if ((BYTE_TYPE)pin < NUM_PINS_PER_AFR_REG)
				{
					configPtr = &(portPtr->AFR[0U]);
				}
				else
				{
					configPtr = &(portPtr->AFR[1U]);
					alternateHigh = TRUE;
				}
				break;
		}

		WORD_TYPE tmp = (*configPtr);
		BYTE_TYPE pos = (BYTE_TYPE)pin * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];
		
		// Pos needs to be modified if AFRH register
		if (alternateHigh == TRUE)
		{
			pos = ((BYTE_TYPE)pin - NUM_PINS_PER_AFR_REG) * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];
		}

		tmp &= ~(GPIO_CONFIG_MAX[(BYTE_TYPE)configSelect] << pos);
		tmp |= (value << pos);

		(*configPtr) = tmp;			
	}
}

Boolean readGpioConfig(const GPIO_TypeDef* portPtr, const GpioPinSelect pin,
					   const GpioConfigSelect configSelect, BYTE_TYPE* const out)
{
	Boolean success = FALSE;
	if ((portPtr != NULL) && (out != NULL))
	{
		WORD_TYPE configRegister;
		Boolean alternateHigh = FALSE;

		switch(configSelect)
		{
			case GPIO_MODE:
				configRegister = portPtr->MODER;
				break;
			case GPIO_OUTPUT_TYPE:
				configRegister = portPtr->OTYPER;
				break;
			case GPIO_OUTPUT_SPEED:
				configRegister = portPtr->OSPEEDR;
				break;
			case GPIO_PULL_UP_DOWN:
				configRegister = portPtr->PUPDR;
				break;
			case GPIO_ALTERNATE_FUNCTION:
				if ((BYTE_TYPE)pin < NUM_PINS_PER_AFR_REG)
				{
					configRegister = portPtr->AFR[0U];
				}
				else
				{
					configRegister = portPtr->AFR[1U];
					alternateHigh = TRUE;
				}
				break;			
		}

		BYTE_TYPE pos = (BYTE_TYPE)pin * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];
		
		// Pos needs to be modified if AFRH register
		if (alternateHigh == TRUE)
		{
			pos = ((BYTE_TYPE)pin - NUM_PINS_PER_AFR_REG) * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];
		}

		configRegister = configRegister >> pos;
		(*out) = (BYTE_TYPE)(configRegister & GPIO_CONFIG_MAX[(BYTE_TYPE)configSelect]);

		success = TRUE;
	}

	return success;
}

void setGpioPinValue(GPIO_TypeDef* const portPtr, const GpioPinSelect pin,
				     const Boolean value)
{
	if (portPtr != NULL)
	{
		if (value == TRUE)
		{
			portPtr->BSRR |= (1U << (BYTE_TYPE)pin);
		}
		else
		{
			portPtr->BSRR |= (1U << (BYTE_TYPE)pin + NUM_GPIO_PINS_PER_PORT);	
		}
	}
}

Boolean readGpioPinValue(const GPIO_TypeDef* const portPtr, const GpioPinSelect pin,
						 Boolean* const out)
{
	Boolean success = FALSE;
	if ((portPtr != NULL) && (out != NULL))
	{
		if (((portPtr->IDR >> (BYTE_TYPE)pin) && 1U) == 1U)
		{
			(*out) = TRUE;
		}
		else
		{
			(*out) = FALSE;
		}

		success = TRUE;
	}

	return success;
}