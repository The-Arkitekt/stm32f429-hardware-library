#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "BitManipulation.h"
#include "ReturnCodesDef.h"
#include "GpioDef.h"

ReturnCode GpioWrite(const GpioStruct gpio, const PinState);
ReturnCode GpioRead(const GpioStruct gpio, PinState* const pinState);

/**
 * Initialize the GPIO pin
 */
ReturnCode GpioInit(const GpioStruct gpio);

/**
 * deInitialize the GPIO so it is no longer useable until initialized again
 */
ReturnCode GpioDeInit(const GpioStruct gpio);

PORT_TYPE getPortType(PortSelect portNum);

#ifdef __cplusplus
}
#endif

#endif //GPIO_H
