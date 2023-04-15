/*
 * Gpio.c
 *
 *  Created on: Mar 19, 2023
 *      Author: architect
 */

#include "CommonDef.h"
#include "Gpio.h"
#include "BitManipulation.h"

void GpioEnable(const GpioPortSelect port){
	setWordBits(1U, port, &(RCC->AHB1ENR));
}

void GpioDisable(const GpioPortSelect port){
	clearWordBits(1U, port, &(RCC->AHB1ENR));
}

ReturnCode GpioWrite(const GpioPortSelect port, const GpioPinSelect pin, const GpioPinState value){

	GpioEnable(port);
	GPIO_PORT_TYPE portType = getPortType(port);
	if (port == NULL){
		return RETURNCODE_NULL_POINTER;
	}

	// set bit BSRR
	if (value == GPIO_PINSTATE_SET){
		setWordBits(1U, pin, &(portType->BSRR));
	}
	else if (value == GPIO_PINSTATE_RESET){
		setWordBits(1U, pin + HALF_WORD_SIZE, &(portType->BSRR));
	}
	else {
		return RETURNCODE_INVALID_INPUT;
	}

    return RETURNCODE_SUCCESS;
}

ReturnCode GpioRead(const GpioPortSelect port, const GpioPinSelect pin, GpioPinState* const pinState){

	GpioEnable(port);
	GPIO_PORT_TYPE portType = getPortType(port);
	if (port == NULL){
		(*pinState) = RETURNCODE_UNKNOWN;
		return RETURNCODE_NULL_POINTER;
	}

	if (checkWordBits(portType->IDR, 1U, pin) == 1){
		(*pinState) =  GPIO_PINSTATE_SET;
	}
	else{
		(*pinState) = GPIO_PINSTATE_RESET;
	}

	return RETURNCODE_SUCCESS;
}

ReturnCode GpioInit(const GpioStruct gpio){

	// Enable GPIO Peripheral clock
	GpioEnable(gpio.port);

	// get port struct
	GPIO_PORT_TYPE port = getPortType(gpio.port);
	if (port == NULL){
		return RETURNCODE_NULL_POINTER;
	}

	// clear and set MODER
	clearWordBits(0b11, 2*gpio.pin, &(port->MODER));
	setWordBits(gpio.mode, 2*gpio.pin, &(port->MODER));

	// clear and set OType
	clearWordBits(0b1, gpio.pin, &(port->OTYPER));
	setWordBits(gpio.oType, gpio.pin, &(port->OTYPER));

	// clear and set OSPEEDR
	clearWordBits(0b11, 2*gpio.pin, &(port->OSPEEDR));
	setWordBits(gpio.speed, 2*gpio.pin, &(port->OSPEEDR));

	// clear and set PUPDR
	clearWordBits(0b11, 2*gpio.pin, &(port->PUPDR));
	setWordBits(gpio.pull, 2*gpio.pin,  &(port->PUPDR));

	return RETURNCODE_SUCCESS;
}

ReturnCode GpioDeInit(const GpioStruct gpio){

	GPIO_PORT_TYPE port = getPortType(gpio.port);
	if (port == NULL){
		return RETURNCODE_NULL_POINTER;
	}

	// clear MODER
	clearWordBits(0b11, 2*gpio.pin, &(port->MODER));

	// clear OType
	clearWordBits(1U, gpio.pin, &(port->OTYPER));

	// clear OSPEEDR
	clearWordBits(0b11, 2*gpio.pin, &(port->OSPEEDR));

	// clear PUPDR
	clearWordBits(0b11, 2*gpio.pin, &(port->PUPDR));

	return RETURNCODE_SUCCESS;
}

GPIO_PORT_TYPE getPortType(GpioPortSelect port){

	return (GPIO_PORT_TYPE)(GPIOA_BASE + (port * (GPIOB_BASE - GPIOA_BASE)));
}
