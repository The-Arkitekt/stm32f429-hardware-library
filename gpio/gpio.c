#include "gpio.h"

//TODO: refactor without stm32fwhatever.h file and using masks for enum values

void GPIO_enable(const GpioPort port)
{
	BYTE_TYPE pos = (port - GPIO_PORT_A) / (GPIO_PORT_B - GPIO_PORT_A);
	RCC->AHB1ENR |= (1U << pos);
}

void GPIO_disable(const GpioPort port)
{
	BYTE_TYPE pos = (port - GPIO_PORT_A) / (GPIO_PORT_B - GPIO_PORT_A);
	RCC->AHB1ENR &= ~(1U << pos);
}

void GPIO_set_config(const GpioConfigStruct gpioConfig)
{
	GPIO_TypeDef* gpio       = (GPIO_TypeDef*)(gpioConfig.port);
	BYTE_TYPE twoBitPosition = 2 * gpioConfig.pin;
	WORD_TYPE tmp            = 0U;

	if (gpioConfig.mode != GPIO_MODE_INVALID)
	{
		tmp = gpio->MODER;
		tmp &= ~(3U << twoBitPosition);
		tmp |= (gpioConfig.mode << twoBitPosition);
		gpio->MODER = tmp;
	}

	if (gpioConfig.altFunc != GPIO_ALT_INVALID)
	{		
		if (gpioConfig.altFunc < GPIO_ALT_8)
		{
			tmp = gpio->AFR[0U];
			tmp &= ~(15U << (4U * gpioConfig.pin));
			tmp |= (gpioConfig.altFunc << (4U * gpioConfig.pin));
			gpio->AFR[0U] = tmp;
		}
		else
		{
			tmp = gpio->AFR[1U];
			tmp &= ~(15U << gpioConfig.pin);
			tmp |= (gpioConfig.altFunc << gpioConfig.pin);
			gpio->AFR[1U] = tmp;
		}
	}

	if (gpioConfig.oType != GPIO_OUTPUT_INVALID)
	{
		tmp = gpio->OTYPER;
		tmp &= ~(1U << gpioConfig.pin);
		tmp |= (gpioConfig.oType << gpioConfig.pin);
		gpio->OTYPER = tmp;
	}

	if (gpioConfig.oSpeed != GPIO_SPEED_INVALID)
	{
		tmp = gpio->OSPEEDR;
		tmp &= ~(3U << twoBitPosition);
		tmp |= (gpioConfig.oSpeed << twoBitPosition);
		gpio->OSPEEDR = tmp;
	}

	if (gpioConfig.pull != GPIO_PULL_INVALID)
	{
		tmp = gpio->PUPDR;
		tmp &= ~(3U << twoBitPosition);
		tmp |= (gpioConfig.pull << twoBitPosition);
		gpio->PUPDR = tmp;
	}
}

void GPIO_set_pin_state(const GpioPort port, const GpioPin pin, const GpioPinState state)
{
	if ((port != GPIO_PORT_INVALID) && (pin != GPIO_PIN_INVALID) && (state != GPIO_PINSTATE_INVALID))
	{
		BYTE_TYPE pos = (state == GPIO_PINSTATE_SET) ? pin : (pin + 16U);
		GPIO_TypeDef* gpio = (GPIO_TypeDef*)port;

		gpio->BSRR |= (1U << pos);
	}
}

GpioPinState GPIO_get_pin_state(const GpioPort port, const GpioPin pin)
{
	GpioPinState out = GPIO_PINSTATE_INVALID;
	if ((port != GPIO_PORT_INVALID) && (pin != GPIO_PIN_INVALID))
	{
		GPIO_TypeDef* gpio = (GPIO_TypeDef*)port;
		out = ((gpio->IDR & (1U << pin)) != 0U) ? GPIO_PINSTATE_SET : GPIO_PINSTATE_RESET;
	}
	return out;
}
