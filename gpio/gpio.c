#include "gpio.h"

void gpioEnable(const GpioPortSelect port){
	RCC->AHB1ENR |= (1U << (BYTE_TYPE)port);
}

void gpioDisable(const GpioPortSelect port){
	RCC->AHB1ENR &= ~(1U << (BYTE_TYPE)port);
}

void gpioWrite(const GpioPortSelect port, const GpioPinSelect pin, const GpioPinState value){
	GpioEnable(port);
	GPIO_TypeDef* const portType = GPIO_PORTS[(BYTE_TYPE)port];

	// set bit BSRR
	if (value == GPIO_PINSTATE_SET){
		portType->BSRR |= (1U << (BYTE_TYPE)pin);
	}
	else if (value == GPIO_PINSTATE_RESET){
		portType->BSRR |= (1U << ((BYTE_TYPE)pin + GPIO_BSRR_BR0_Pos));
	}
}

GpioPinState gpioRead(const GpioPortSelect port, const GpioPinSelect pin){
	GpioEnable(port);
	GPIO_TypeDef* portType = (GPIO_TypeDef*)GPIO_PORT_ADDRS[(BYTE_TYPE)port];

	WORD_TYPE pinMask = (1U << (BYTE_TYPE)pin);
	if ((portType->IDR & pinMask) == pinMask){
		return GPIO_PINSTATE_SET
	}
	else{
		return GPIO_PINSTATE_RESET;
	}
}

void gpioInit(const GpioConfigStruct gpioConfig){

	// Enable GPIO Peripheral clock
	GpioEnable(gpioConfig.port);

	// get port struct
	GPIO_TypeDef* port = (GPIO_TypeDef*)GPIO_PORT_ADDRS[(BYTE_TYPE)gpioConfig.port];

	WORD_TYPE tmp         = 0U;
	BYTE_TYPE bitPosition = 0U;
	// clear and set MODER
	tmp = port->MODER;
	bitPosition = (BYTE_TYPE)(gpioConfig.pin) * 2U;
	tmp &= ~(3U << bitPosition);
	tmp |= ((BYTE_TYPE)(gpioConfig.mode) << bitPosition)
	port->MODER = tmp;

	// Handle alt mode if mode is Alternate
	if (gpio.mode == GPIO_MODESELECT_ALT){
		if ((BYTE_TYPE)(gpioConfig.pin) < 8U){
			tmp = port->AFR[0];
			bitPosition = ((BYTE_TYPE)(gpioConfig.pin) - 8U) * 4U;
			tmp &= ~(0xFU << bitPosition);
			tmp |= ((BYTE_TYPE)(gpioConfig.altMode) << bitPosition);
			port->AFR[0] = tmp;
		}
		else{
			tmp = port->AFR[1];
			bitPosition = (BYTE_TYPE)(gpioConfig.pin) * 4U;
			tmp &= ~(0xFU << bitPosition);
			tmp |= ((BYTE_TYPE)(gpioConfig.altMode) << bitPosition);
			port->AFR[1] = tmp;
		}
	}

	// clear and set OType
	tmp = port->OTYPER;
	tmp &= ~(1U << (BYTE_TYPE)(gpioConfig.pin));
	tmp |= ((BYTE_TYPE)(gpioConfig.oType) << (BYTE_TYPE)(gpioConfig.pin))
	port->OTYPER = tmp;

	// clear and set OSPEEDR
	tmp = port->OSPEEDR;
	bitPosition = (BYTE_TYPE)(gpioConfig.pin) * 2U;
	tmp &= ~(3U << bitPosition);
	tmp |= ((BYTE_TYPE)(gpioConfig.speed) << bitPosition);
	port->OSPEEDR = tmp;

	// clear and set PUPDR
	tmp = port->PUPDR;
	bitPosition = (BYTE_TYPE)(gpioConfig.pin) * 2U;
	tmp &= ~(3U << bitPosition);
	tmp |= ((BYTE_TYPE)(gpioConfig.pull) << bitPosition);
	port->PUPDR = tmp;
}

void gpioDeInit(const GpioPortSelect port, const GpioPinSelect pin){

	GPIO_TypeDef* port = (GPIO_TypeDef*)GPIO_PORT_ADDRS[(BYTE_TYPE)port];
	WORD_TYPE twoBitClearPinMask = ~(3U << ((BYTE_TYPE)(pin) * 2U));

	// clear MODER
	port->MODER &= twoBitClearPinMask;

	// clear OType
	port->OTYPER &= ~(1U << (BYTE_TYPE)(pin));

	// clear OSPEEDR
	port->OSPEEDR &= twoBitClearPinMask;

	// clear PUPDR
	port->PUPDR &= twoBitClearPinMask;
}
