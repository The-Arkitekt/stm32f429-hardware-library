#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "GpioDef.h"

void GpioWrite(const GpioStruct gpio, const PinState);
PinState GpioRead(const GpioStruct gpio);

/**
 * Initialize the GPIO pin
 */
void GpioInit(const GpioStruct gpio);

/**
 * deInitialize the GPIO so it is no longer useable until initialized again
 */
void GpioDeInit(const GpioStruct gpio);

PORT_TYPE getPortType(uint32_t port);

#ifdef __cplusplus
}
#endif

#endif //GPIO_H
