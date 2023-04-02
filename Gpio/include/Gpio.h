#ifndef GPIO_H
#define GPIO_H

#include "gpioDef.h"

namespace STM32f429{

namespace GPIO{

class Gpio {
public:
	/**
	 * Constructor
	 * 	- Defaults mode as output
	 * 	- Defaults speed as fast
	 * 	- Defaults pull as pull up
	 */
	Gpio();

	/**
	 * Getters
	 */
	PortSelect  getPort()  const {return m_port;};
	PinSelect   getPin()   const {return m_pin;};
	ModeSelect  getMode()  const {return m_mode;};
	OTypeSelect getOType() const {return m_oType;};
	SpeedSelect getSpeed() const {return m_speed;};
	PullSelect  getPull()  const {return m_pull;};

	bool isInitialized() const {return m_initialized;};
	/**
	 * Setters
	 */
	void setPort (const PortSelect&  port);
	void setPin  (const PinSelect&   pin);
	void setMode (const ModeSelect&  mode);
	void setOType(const OTypeSelect& oType);
	void setSpeed(const SpeedSelect& speed);
	void setPull (const PullSelect&  pull);

	void gpioWrite(const PinState) const;
	PinState gpioRead() const;

	/**
	 * Initialize the GPIO pin
	 */
	void init();

	/**
	 * deInitialize the GPIO so it is no longer useable until initialized again
	 */
	void deInit();

private:
	PortSelect  m_port;
	PinSelect   m_pin;
	ModeSelect  m_mode;
	OTypeSelect m_oType;
	SpeedSelect m_speed;
	PullSelect  m_pull;
	bool        m_initialized;
};

}

}

#endif //GPIO_H
