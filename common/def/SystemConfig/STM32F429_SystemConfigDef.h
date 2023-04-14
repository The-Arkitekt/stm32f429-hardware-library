#ifndef STM32F4_SYSTEM_CONFIG_H
#define STM32F$_SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32.h"

/**
 * SYSCFG registers definition
 */
typedef SYSCFG_TypeDef * SYSCFG_TYPE;

/**
 * SYSCFG registers location
 *
 * There is only one set of SYSCFG registers
 */
const SYSCFG_TYPE SYSCFG_REG = SYSCFG_BASE;

/**
 * Ethernet Interface selection
 */
typedef enum SysCfgEthInterface{
	SYSCFG_ETHINT_MII = 0U,
	SYSCFG_ETHINT_RMII_PHY
}SysCfgEthInterface;

/**
 * Memory Mapping Selection
 *
 * sets which memory is mapped at address 0x0
 */
typedef enum SysCfgMemMapMode{
	SYSCFG_MEMMAP_MODE_MAIN_FLASH = 0U,
	SYSCFG_MEMMAP_MODE_SYS_FLASH,
	SYSCFG_MEMMAP_MODE_FMC_1,
	SYSCFG_MEMMAP_MODE_SRAM,
	SYSCFG_MAMMAP_MODE_FMC_SDRAM
}SysCfgMemMapMode;

/**
 * External Interrupt Configuration Registers
 */
typedef enum SysCfgExtiCr{
	SYSCFG_EXTI_CR1 = 0U,
	SYSCFG_EXTI_CR2,
	SYSCFG_EXTI_CR3,
	SYSCFG_EXTI_CR4
}SysCfgExtiCr;


#ifdef __cplusplus
}
#endif

#endif //STM32F4_SYSTEM_CONFIG_DEF_H
