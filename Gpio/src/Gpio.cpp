/*
 * Gpio.cpp
 *
 *  Created on: Mar 19, 2023
 *      Author: architect
 */
#include "Gpio.h"


namespace STM32f429{

namespace GPIO{

/**
 * Initialize member variables
 */
Gpio::Gpio() : m_initialized{false}
{}

void Gpio::setPort(const PortSelect& port){

	if(m_initialized)
		deInit();

	m_port = port;
}

void Gpio::setPin(const PinSelect& pin){

	if(m_initialized)
		deInit();

	m_pin = pin;
}

void Gpio::setMode(const ModeSelect& mode){

	if(m_initialized)
		deInit();

	m_mode = mode;
}

void Gpio::setOType(const OTypeSelect& oType){

	if(m_initialized)
		deInit();

	m_oType = oType;
}

void Gpio::setSpeed(const SpeedSelect& speed){

	if(m_initialized)
		deInit();

	m_speed = speed;
}

void Gpio::setPull(const PullSelect& pull){

	if(m_initialized)
		deInit();

	m_pull = pull;
}

void Gpio::gpioWrite(const PinState value) const{
	if (value == RESET)
		PORTS[m_port]->BSRR |= (0x1 << (uint8_t(m_pin)+16));
	else if (value == SET)
		PORTS[m_port]->BSRR |= (0x1 << uint8_t(m_pin));
}

PinState Gpio::gpioRead() const{
	uint32_t input = PORTS[m_port]->IDR;
	if (input & (0x1 << uint8_t(m_pin)))
		return SET;
	else
		return RESET;
}

void Gpio::init(){
	// Dont initialize if invalid or already initialized
	if(m_initialized){;
		return;
	}

	// Enable GPIO Peripheral clock
	RCC->AHB1ENR |= CLK_ENABLE_MASKS[m_port];

	// clear and set MODER
	PORTS[m_port]->MODER &= ~(0x3 << (2*uint8_t(m_pin)));
	PORTS[m_port]->MODER |= (uint32_t(m_mode) << (2*uint8_t(m_pin)));

	// clear and set OType
	PORTS[m_port]->OTYPER &= ~(0x1 << uint8_t(m_pin));
	PORTS[m_port]->OTYPER |= (uint32_t(m_oType) << uint8_t(m_pin));

	// clear and set OSPEEDR
	PORTS[m_port]->OSPEEDR &= ~(0x3 << (2*uint8_t(m_pin)));
	PORTS[m_port]->OSPEEDR |= (uint32_t(m_speed) << (2*uint8_t(m_pin)));

	// clear and set PUPDR
	PORTS[m_port]->PUPDR &= ~(0x3 << (2*uint8_t(m_pin)));
	PORTS[m_port]->PUPDR |= (uint32_t(m_pull) << (2*uint8_t(m_pin)));

	m_initialized = true;
}

void Gpio::deInit(){
	// dont deinitialize if not already initialized
	if(!m_initialized)
		return;

	// Disable GPIO Peripheral clock
	RCC->AHB1ENR &= ~(CLK_ENABLE_MASKS[m_port]);

	// clear MODER
	PORTS[m_port]->MODER &= ~(0x3 << (2*uint8_t(m_pin)));

	// clear OType
	PORTS[m_port]->OTYPER &= ~(0x1 << uint8_t(m_pin));

	// clear OSPEEDR
	PORTS[m_port]->OSPEEDR &= ~(0x3 << (2*uint8_t(m_pin)));

	// clear PUPDR
	PORTS[m_port]->PUPDR &= ~(0x3 << (2*uint8_t(m_pin)));

	m_initialized = false;
}

}

}

