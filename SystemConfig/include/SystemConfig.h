#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "CommonDef.h"
#include "ReturnCodesDef.h"
#include "GpioDef.h"
#include "SystemConfigDef.h"

/**
 * Memory Mapping functions
 */
// set and reset FMC memory mapping swap
void SysCfgSetSwap();
void SysCfgResetSwap();

// set and reset Flash Bank mode
void SysCfgSetFbMode();
void SysCfgResetFbMode();

// set memory mapping mode
void SysCfgMemMapSetMode(SysCfgMemMapMode mode);

/**
 * Peripheral mode configuration functions
 */
// Ethernet PHY interface selection
void SysCfgSelectEthInterface(SysCfgEthInterface interface);

/**
 * External Interrupt Configuration
 */
ReturnCode SysCfgEnableExti(SysCfgExtiCr controlRegister, GpioPortSelect port, GpioPinSelect pin);
ReturnCode SysCfgDisableExti(SysCfgExtiCr controlRegister, GpioPortSelect port, GpioPinSelect pin);

Boolean isValidExtiPin(SysCfgExtiCr controlRegister, GpioPinSelect pin);

#ifdef __cplusplus
}
#endif

#endif //SYSTEM_CONFIG_H
