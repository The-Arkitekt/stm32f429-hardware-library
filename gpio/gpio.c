#include "gpio.h"

GPIO_TypeDef* const getGpioPort(const GpioPortSelect portSelect)
{
	return (GPIO_TypeDef*)(GPIOA_BASE + ((BYTE_TYPE)portSelect * (GPIOB_BASE - GPIOA_BASE)));
}

void setGpioConfig(GPIO_TypeDef* portPtr, const BYTE_TYPE pin,
				   const GpioConfigSelect configSelect, const BYTE_TYPE value)
{
	if ((portPtr != NULL) && (value <= GPIO_CONFIG_MAX[(BYTE_TYPE)configSelect]) &&
		(pin <= GPIO_PIN_MAX))
	{
		WORD_TYPE* configPtr = NULL;
		BYTE_TYPE pos = pin * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];

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
				if (pin < NUM_PINS_PER_AFR_REG)
				{
					configPtr = &(portPtr->AFR[0U]);
				}
				else
				{
					configPtr = &(portPtr->AFR[1U]);
					pos = (pin - NUM_PINS_PER_AFR_REG) * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];
				}
				break;
		}

		WORD_TYPE tmp = (*configPtr);
		tmp &= ~(GPIO_CONFIG_MAX[(BYTE_TYPE)configSelect] << pos);
		tmp |= (value << pos);

		(*configPtr) = tmp;			
	}
}

Boolean readGpioConfig(const GPIO_TypeDef* portPtr, const BYTE_TYPE pin,
					   const GpioConfigSelect configSelect, BYTE_TYPE* const out)
{
	Boolean success = FALSE;
	if ((portPtr != NULL) && (out != NULL) && (pin <= GPIO_PIN_MAX))
	{
		WORD_TYPE configRegister;
		BYTE_TYPE pos = pin * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];


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
				if (pin < NUM_PINS_PER_AFR_REG)
				{
					configRegister = portPtr->AFR[0U];
				}
				else
				{
					configRegister = portPtr->AFR[1U];
					pos = (pin - NUM_PINS_PER_AFR_REG) * GPIO_CONFIG_BITS_PER_PIN[(BYTE_TYPE)configSelect];

				}
				break;			
		}

		configRegister >>= pos;
		(*out) = (BYTE_TYPE)(configRegister & GPIO_CONFIG_MAX[(BYTE_TYPE)configSelect]);

		success = TRUE;
	}

	return success;
}

void setGpioPinValue(GPIO_TypeDef* const portPtr, const BYTE_TYPE pin,
				     const Boolean value)
{
	if ((portPtr != NULL) && (pin <= GPIO_PIN_MAX))
	{
		if (value == TRUE)
		{
			portPtr->BSRR |= (1U << pin);
		}
		else
		{
			portPtr->BSRR |= (1U << pin + NUM_GPIO_PINS_PER_PORT);	
		}
	}
}

Boolean readGpioPinValue(const GPIO_TypeDef* const portPtr, const BYTE_TYPE pin,
						 Boolean* const out)
{
	Boolean success = FALSE;
	if ((portPtr != NULL) && (out != NULL) && (pin <= GPIO_PIN_MAX))
	{
		(*out) = (((portPtr->IDR >> pin) && 1U) == 1U) ? TRUE : FALSE;
		success = TRUE;
	}

	return success;
}

void gpioEnable(const GpioPortSelect port)
{
	RCC->AHB1ENR |= (1U << (BYTE_TYPE)port);
}

void gpioDisable(const GpioPortSelect port)
{
	RCC->AHB1ENR &= ~(1U << (BYTE_TYPE)port);
}