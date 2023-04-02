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
		PORTS[m_port]->BSRR |= BR_MASKS[m_pin];
	else if (value == SET)
		PORTS[m_port]->BSRR |= BS_MASKS[m_pin];
}

PinState Gpio::gpioRead() const{
	if ((PORTS[m_port]->IDR) & IDR_MASKS[m_pin])
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
	PORTS[m_port]->MODER &= ~(MODE_MASKS[m_pin]);
	PORTS[m_port]->MODER |= MODE_SELECT_MASKS[m_pin][m_mode];

	// clear and set OType
	PORTS[m_port]->OTYPER &= ~(O_TYPE_MASKS[m_pin]);
	PORTS[m_port]->OTYPER |= O_TYPE_SELECT_MASKS[m_pin][m_oType];

	// clear and set OSPEEDR
	PORTS[m_port]->OSPEEDR &= ~(SPEED_MASKS[m_pin]);
	PORTS[m_port]->OSPEEDR |= SPEED_SELECT_MASKS[m_pin][m_speed];

	// clear and set PUPDR
	PORTS[m_port]->PUPDR &= ~(PULL_MASKS[m_pin]);
	PORTS[m_port]->PUPDR |= PULL_SELECT_MASKS[m_pin][m_pull];

	m_initialized = true;
}

void Gpio::deInit(){
	// dont deinitialize if not already initialized
	if(!m_initialized)
		return;

	// Disable GPIO Peripheral clock
	RCC->AHB1ENR &= ~(CLK_ENABLE_MASKS[m_port]);

	// clear MODER
	PORTS[m_port]->MODER &= ~(MODE_MASKS[m_pin]);

	// clear OType
	PORTS[m_port]->OTYPER &= ~(O_TYPE_MASKS[m_pin]);

	// clear OSPEEDR
	PORTS[m_port]->OSPEEDR &= ~(SPEED_MASKS[m_pin]);

	// clear PUPDR
	PORTS[m_port]->PUPDR &= ~(PULL_MASKS[m_pin]);

	m_initialized = false;
}

}

}

