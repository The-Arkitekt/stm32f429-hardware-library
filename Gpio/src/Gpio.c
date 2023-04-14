/*
 * Gpio.c
 *
 *  Created on: Mar 19, 2023
 *      Author: architect
 */

#include "CommonDef.h"
#include "Gpio.h"
#include "BitManipulation.h"

ReturnCode GpioWrite(const GpioStruct gpio, const GpioPinState value){

	GPIO_PORT_TYPE port = getPortType(gpio.port);
	if (port == NULL){
		return RETURNCODE_NULL_POINTER;
	}

	// set bit BSRR
	if (value == GPIO_PINSTATE_SET){
		setWordBits(1U, gpio.pin, &(port->BSRR));
	}
	else if (value == GPIO_PINSTATE_RESET){
		setWordBits(1U, gpio.pin + HALF_WORD_SIZE, &(port->BSRR));
	}
	else {
		return RETURNCODE_INVALID_INPUT;
	}

    return RETURNCODE_SUCCESS;
}

ReturnCode GpioRead(const GpioStruct gpio, GpioPinState* const pinState){

	GPIO_PORT_TYPE port = getPortType(gpio.port);
	if (port == NULL){
		(*pinState) = RETURNCODE_UNKNOWN;
		return RETURNCODE_NULL_POINTER;
	}

	if (checkWordBits(port->IDR, 1U, gpio.pin) == 1){
		(*pinState) =  GPIO_PINSTATE_SET;
	}
	else{
		(*pinState) = GPIO_PINSTATE_RESET;
	}

	return RETURNCODE_SUCCESS;
}

ReturnCode GpioInit(const GpioStruct gpio){

	// Enable GPIO Peripheral clock
	if (RCC == NULL){
		return RETURNCODE_NULL_POINTER;
	}

	setWordBits(1U, gpio.port, &(RCC->AHB1ENR));

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

	// Disable GPIO Peripheral clock
	clearWordBits(1U, gpio.port, &(RCC->AHB1ENR));

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
