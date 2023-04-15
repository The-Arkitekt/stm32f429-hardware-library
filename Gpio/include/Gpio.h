#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "BitManipulation.h"
#include "ReturnCodesDef.h"
#include "GpioDef.h"

void GpioEnable(const GpioPortSelect port);
void GpioDisable(const GpioPortSelect port);

ReturnCode GpioWrite(const GpioPortSelect port, const GpioPinSelect pin, const GpioPinState PinState);
ReturnCode GpioRead(const GpioPortSelect port, const GpioPinSelect pin, GpioPinState* const pinState);

/**
 * Initialize the GPIO pin
 */
ReturnCode GpioInit(const GpioStruct gpio);

/**
 * deInitialize the GPIO so it is no longer useable until initialized again
 */
ReturnCode GpioDeInit(const GpioStruct gpio);

GPIO_PORT_TYPE getPortType(GpioPortSelect portNum);

#ifdef __cplusplus
}
#endif

#endif //GPIO_H
