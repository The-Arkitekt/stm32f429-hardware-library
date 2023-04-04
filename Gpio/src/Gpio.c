/*
 * Gpio.c
 *
 *  Created on: Mar 19, 2023
 *      Author: architect
 */

#include "Gpio.h"
#include "Common.h"

void GpioWrite(const GpioStruct gpio, const PinState value){

	PORT_TYPE port = getPortType(gpio.port);

	if (value == RESET)
		port->BSRR |= generate32BitMask(0x1, gpio.pin + 16U);
	else if (value == SET){
		port->BSRR |= generate32BitMask(0x1, gpio.pin);
	}
}

PinState GpioRead(const GpioStruct gpio){

	PORT_TYPE port = getPortType(gpio.port);

	if ((port->IDR) & generate32BitMask(0x1, gpio.pin))
		return SET;
	else
		return RESET;
}

void GpioInit(const GpioStruct gpio){

	PORT_TYPE port = getPortType(gpio.port);

	uint32_t halfWordClearMask = generate32BitMask(0x3UL, gpio.pin);
	uint32_t wordClearMask     = generate32BitMask(0x3UL, 2*gpio.pin);

	// Enable GPIO Peripheral clock
	RCC->AHB1ENR |= generate32BitMask(0x1UL, gpio.port);

	// clear and set MODER
	port->MODER &= ~(wordClearMask);
	port->MODER |= generate32BitMask(gpio.mode, 2*gpio.pin);

	// clear and set OType
	port->OTYPER &= ~(halfWordClearMask);
	port->OTYPER |= generate32BitMask(gpio.oType, gpio.pin);

	// clear and set OSPEEDR
	port->OSPEEDR &= ~(wordClearMask);
	port->OSPEEDR |= generate32BitMask(gpio.speed, 2*gpio.pin);

	// clear and set PUPDR
	port->PUPDR &= ~(wordClearMask);
	port->PUPDR |= generate32BitMask(gpio.pull, 2*gpio.pin);
}

void GpioDeInit(const GpioStruct gpio){

	PORT_TYPE port = getPortType(gpio.port);

	uint32_t halfWordClearMask = generate32BitMask(0x3UL, gpio.pin);
	uint32_t wordClearMask     = generate32BitMask(0x3UL, 2*gpio.pin);

	// Disable GPIO Peripheral clock
	RCC->AHB1ENR &= ~(generate32BitMask(0x1UL, gpio.port));

	// clear MODER
	port->MODER &= ~(wordClearMask);

	// clear OType
	port->OTYPER &= ~(halfWordClearMask);

	// clear OSPEEDR
	port->OSPEEDR &= ~(wordClearMask);

	// clear PUPDR
	port->PUPDR &= ~(wordClearMask);
}

PORT_TYPE getPortType(uint32_t port){
	return (PORT_TYPE)(GPIOA_BASE + (port * (GPIOB_BASE - GPIOA_BASE)));
}
