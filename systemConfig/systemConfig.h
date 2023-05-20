#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "systemConfigTypes.h"

/**
 * This constant is calculated using the following formula
 * 	num_gpio_pins / ((log_2(num_gpio_ports) * num_gpio_pins) / (bits_per_register / 2))
*/
static const BYTE_TYPE NUM_PINS_PER_CR_REG = 4U;

//@{
/**
 * Enable/Disable SysCfg peripheral
*/
void sysCfgEnable();
void sysCfgDisable();
//@}

//@{
/**
 * Set value of bitfield in MEMRMP register
 * @param value The value used to set the bitfield
 */
void sysCfgMemRmpSetSwap(const Boolean value);						    /* !< SWP_FMC bit field */
void sysCfgMemRmpSetFbMode(const Boolean value);  					    /* !< FB_MODE bit field */
void sysCfgMemRmpSetMemMode(const SysCfgMemoryRemapModeSelect value);   /* !< MEM_MODE bit field */
//@}

//@{
/**
 * Set value of bitfield in PMC register
 * @param value The value used to set the bitfield
 */
void sysCfgPmcSetEthernet(const Boolean value);		                         	    /* !< MII_RMII_SEL bit field */
void sysCfgPmcSetAdcDc2(const SysCfgPmcAdcDc2Select position, const Boolean value); /* !< ADCxDC@ bit field*/

/**
 * Set value of bitfield in EXTICRx register
 * @param portSelect The source port 
 * @param pinSelect THe pin to be set as the source
 * @param value If True, the pin is set as source, else the pin is removed as source
 */
void sysCfgSetExti(const GpioPortSelect portSelect, const GpioPinSelect pinSelect, const Boolean value);

#ifdef __cplusplus
}
#endif

#endif //SYSTEM_CONFIG_H
