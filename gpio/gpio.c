#include "gpio.h"

void gpioEnable(const GpioPortSelect portSelect){
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN << (BYTE_TYPE)portSelect);
}

void gpioDisable(const GpioPortSelect portSelect){
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN << (BYTE_TYPE)portSelect);
}

void gpioWrite(const GpioPortSelect portSelect, const GpioPinSelect pinSelect, const Boolean value){
	gpioEnable(portSelect);
	GPIO_TypeDef* const port = GPIO_PORTS[(BYTE_TYPE)portSelect];

	// set bit BSRR
	if (value == TRUE){
		port->BSRR |= (GPIO_BSRR_BS0 << (BYTE_TYPE)pinSelect);
	}
	else{
		port->BSRR |= (GPIO_BSRR_BR0 << (BYTE_TYPE)pinSelect);
	}
}

Boolean gpioRead(const GpioPortSelect portSelect, const GpioPinSelect pinSelect){
	gpioEnable(portSelect);
	GPIO_TypeDef* const port = GPIO_PORTS[(BYTE_TYPE)portSelect];

	// check if bit for the pinSelect is set
	WORD_TYPE pinMask = (GPIO_IDR_ID0 << (BYTE_TYPE)pinSelect);
	if ((port->IDR & pinMask) == pinMask){
		return TRUE;
	}
	// The bit is not set
	return FALSE;
}

void gpioInit(const GpioConfigStruct gpioConfig){

	// Enable GPIO Peripheral clock
	gpioEnable(gpioConfig.port);

	// get port struct
	GPIO_TypeDef* const port = GPIO_PORTS[(BYTE_TYPE)(gpioConfig.port)];

	WORD_TYPE tmp         = 0U;
	BYTE_TYPE bitPosition = 0U;
	// clear and set MODER
	tmp = port->MODER;
	// shift left 1 = multiply by 2
	bitPosition = (BYTE_TYPE)(gpioConfig.pin) << 1U;
	tmp &= ~(GPIO_MODER_MODER0 << bitPosition);
	tmp |= ((BYTE_TYPE)(gpioConfig.mode) << bitPosition);
	port->MODER = tmp;

	// Handle alt mode if mode is Alternate
	if (gpioConfig.mode == GPIO_MODESELECT_ALT){
		if ((BYTE_TYPE)(gpioConfig.pin) < NUM_PINS_PER_AFR_REG){
			tmp = port->AFR[0];
			// shift left 2 = multiply by 4
			bitPosition = (BYTE_TYPE)(gpioConfig.pin) << 2U;
			tmp &= ~(GPIO_AFRL_AFSEL0 << bitPosition);
			tmp |= ((BYTE_TYPE)(gpioConfig.altMode) << bitPosition);
			port->AFR[0] = tmp;
		}
		else{
			tmp = port->AFR[1];
			bitPosition = ((BYTE_TYPE)(gpioConfig.pin) - NUM_PINS_PER_AFR_REG) << 2U;
			tmp &= ~(GPIO_AFRH_AFSEL8 << bitPosition);
			tmp |= ((BYTE_TYPE)(gpioConfig.altMode) << bitPosition);
			port->AFR[1] = tmp;
		}
	}

	// clear and set OType
	tmp = port->OTYPER;
	tmp &= ~(GPIO_OTYPER_OT0 << (BYTE_TYPE)(gpioConfig.pin));
	tmp |= ((BYTE_TYPE)(gpioConfig.oType) << (BYTE_TYPE)(gpioConfig.pin));
	port->OTYPER = tmp;

	// clear and set OSPEEDR
	tmp = port->OSPEEDR;
	bitPosition = (BYTE_TYPE)(gpioConfig.pin) << 1U;
	tmp &= ~(GPIO_OSPEEDR_OSPEED0 << bitPosition);
	tmp |= ((BYTE_TYPE)(gpioConfig.speed) << bitPosition);
	port->OSPEEDR = tmp;

	// clear and set PUPDR
	tmp = port->PUPDR;
	bitPosition = (BYTE_TYPE)(gpioConfig.pin) << 1U;
	tmp &= ~(GPIO_PUPDR_PUPD0 << bitPosition);
	tmp |= ((BYTE_TYPE)(gpioConfig.pull) << bitPosition);
	port->PUPDR = tmp;
}

void gpioDeInit(const GpioPortSelect portSelect, const GpioPinSelect pinSelect){
	
	// Enable GPIO Peripheral clock
	gpioEnable(portSelect);

	GPIO_TypeDef* const port = GPIO_PORTS[(BYTE_TYPE)portSelect];
	BYTE_TYPE bitPosition = (BYTE_TYPE)pinSelect << 1U;

	// clear MODER
	port->MODER &= ~(GPIO_MODER_MODER0 << bitPosition);

	// clear OSPEEDR
	port->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED0 << bitPosition);

	// clear PUPDR
	port->PUPDR &= ~(GPIO_PUPDR_PUPD0 << bitPosition);

	// clear OType
	bitPosition = (BYTE_TYPE)pinSelect;
	port->OTYPER &= ~(GPIO_OTYPER_OT0 << bitPosition);
}
