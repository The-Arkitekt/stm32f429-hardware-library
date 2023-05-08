#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "gpio.h"
#include "register.h"

/**
 * SYSCFG MEM_RMP register MEM_MODE field selection enum
 * 	Controls the memory internal mapping at address 0x0
*/
typedef enum SysCfgMemoryRemapModeSelect{
	SYSCFG_MEMRMP_MEMMODE_MAINFLASH = 0U,	/* !< Main flash memory mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_SYSFLASH,			/* !< System flash memory mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_FMC,				/* !< FMC Bank1 (NOR/PSRAM 1 and 2) mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_SRAM,				/* !< Embedded SRAM (SRAM1) mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_FMC_SDRAM			/* !< FMC/SDRAM Bank 1 mapped at 0x0 */
}SysCfgMemoryRemapModeSelect;

/**
 * SYSCFG PMC register ADCxDC2 field selection enum
 * Refer to AN4073 on how to use this bit. 
 * Note: These bits can be set only if the following conditions are met:
 *	- ADC clock higher or equal to 30 MHz.
 *	- Only one ADCxDC2 bit must be selected if ADC conversions do not start 
 *		at the same time and the sampling times differ. 
 *	- These bits must not be set when the ADCDC1 bit is set in PWR_CR 
 *		register.
*/
typedef enum SysCfgPmcAdcDc2Select{
	SYSCFG_PMC_ADCDC2_ADC1  = SYSCFG_PMC_ADC1DC2_Pos,
	SYSCFG_PMC_ADCDC2_ADC2  = SYSCFG_PMC_ADC2DC2_Pos,
	SYSCFG_PMC_ADCDC2_ADC3  = SYSCFG_PMC_ADC3DC2_Pos
}SysCfgPmcAdcDc2Select;

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
void sysCfgMemRmpSetMemMode(const SysCfgMemoryRemapModeSelect position, 
							const Boolean value); 						/* !< MEM_MODE bit field */
//@}

//@{
/**
 * Set value of bitfield in PMC register
 * @param value The value used to set the bitfield
 */
void sysCfgPmcSetEthernet(const Boolean value);		       /* !< MII_RMII_SEL bit field */
void sysCfgPmcSetAdcDc2(const SysCfgPmcAdcDc2Select value); /* !< ADCxDC@ bit field*/

/**
 * Set value of bitfield in EXTICRx register
 * @param portSelect The source port 
 * @param pinSelect THe pin to be set as the source
 * @param value If True, the pin is set as source, else the pin is removed as source
 */
void sysCfgSetExti(const GpioPortSelect portSelect, const GpioPinSelect pinSelect, Boolean value);

#ifdef __cplusplus
}
#endif

#endif //SYSTEM_CONFIG_H
