#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "Gpio.h"

/**
 * SYSCFG MEM_RMP register MEM_MODE field selection enum
 * 	Controls the memory internal mapping at address 0x0
*/
typedef enum SysCfgMemRmpMemModeSelect{
	SYSCFG_MEMRMP_MEMMODE_MAINFLASH = 0U,	/* !< Main flash memory mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_SYSFLASH,			/* !< System flash memory mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_FMC,				/* !< FMC Bank1 (NOR/PSRAM 1 and 2) mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_SRAM,				/* !< Embedded SRAM (SRAM1) mapped at 0x0 */
	SYSCFG_MEMRMP_MEMMODE_FMC_SDRAM			/* !< FMC/SDRAM Bank 1 mapped at 0x0 */
}SysCfgMemRmpMemModeSelect;

/**
 * SYSCFG EXTICRx register selection enum
 * 	Each register Selects source input for the some EXTIx external interrupt
*/
typedef enum SysCfgExtiCrSelect{
	SYSCFG_EXTICR_1 = 0U,		/* !< Sets source for EXTI0 - EXTI3 */
	SYSCFG_EXTICR_2,			/* !< Sets source for EXTI4 - EXTI7 */
	SYSCFG_EXTICR_3,			/* !< Sets source for EXTI8 - EXTI11 */
	SYSCFG_EXTICR_4				/* !< Sets source for EXTI12 - EXTI15 */
}SysCfgExtiCrSelect;

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
void sysCfgMemRmpSetSwap(const Boolean value);						/* !< SWP_FMC bit field */
void sysCfgMemRmpSetFbMode(const Boolean value );  					/* !< FB_MODE bit field */
void sysCfgMemRmpSetMemMode(const SysCfgMemRmpMemModeSelect value)	/* !< MEM_MODE bit field */
//@}

//@{
/**
 * Set value of bitfield in PMC register
 * @param value The value used to set the bitfield
 */
void sysCfgPmcSetEthernet(const Boolean value);		/* !< MII_RMII_SEL bit field */
vois sysCfgPmcSetAdcDc2(const Boolean value);	    /* !< ADCxDC@ bit field*/

/**
 * Set value of bitfield in EXTICRx register
 * @param extiCr The EXTI_CR register to be set
 * @param port The port to be set as the source 
 * @param value If True, the port is set as source, else the port is removed as source
 */
void sysCfgSetExti(const SysCfgExtiCrSelect extiCr, const GpioPortSelect port, Boolean value);

#ifdef __cplusplus
}
#endif

#endif //SYSTEM_CONFIG_H
