#ifndef STM32F4_SYSTEM_CONFIG_H
#define STM32F$_SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "BitManipulationDef.h"
#include "GpioDef.h"
#include "stm32.h"

/**
 * SYSCFG registers definition
 */
typedef SYSCFG_TypeDef * SYSCFG_TYPE;
const WORD_TYPE SYSCONFIG_BASE = SYSCFG_BASE;

/**
 * Memory Mapping Selection
 *
 * sets which memory is mapped at address 0x0
 */
const BYTE_TYPE SYSCFG_SWP_FMC_POS  = 10U;
const BYTE_TYPE SYSCFG_FB_MODE_POS  = 8U;
const BYTE_TYPE SYSCFG_MEM_MODE_POS = 0U;
typedef enum SysCfgMemMapMode{
	SYSCFG_MEMMAP_MODE_MAIN_FLASH = 0U,
	SYSCFG_MEMMAP_MODE_SYS_FLASH,
	SYSCFG_MEMMAP_MODE_FMC_1,
	SYSCFG_MEMMAP_MODE_SRAM,
	SYSCFG_MAMMAP_MODE_FMC_SDRAM
}SysCfgMemMapMode;

/**
 * Ethernet Interface selection
 */
const BYTE_TYPE SYSCFG_ETH_SEL_POS = 23U;
typedef enum SysCfgEthInterface{
	SYSCFG_ETHINT_MII = 0U,
	SYSCFG_ETHINT_RMII_PHY
}SysCfgEthInterface;

/**
 * External Interrupt Configuration Registers
 */
const BYTE_TYPE EXTI_CR1_MIN_PIN = GPIO_PINSELECT_0;
const BYTE_TYPE EXTI_CR1_MAX_PIN = GPIO_PINSELECT_3;
const BYTE_TYPE EXTI_CR2_MIN_PIN = GPIO_PINSELECT_4;
const BYTE_TYPE EXTI_CR2_MAX_PIN = GPIO_PINSELECT_7;
const BYTE_TYPE EXTI_CR3_MIN_PIN = GPIO_PINSELECT_8;
const BYTE_TYPE EXTI_CR3_MAX_PIN = GPIO_PINSELECT_11;
const BYTE_TYPE EXTI_CR4_MIN_PIN = GPIO_PINSELECT_12;
const BYTE_TYPE EXTI_CR4_MAX_PIN = GPIO_PINSELECT_15;
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
