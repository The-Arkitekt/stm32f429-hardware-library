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
static const WORD_TYPE SYSCFG_BASE_ADDR = SYSCFG_BASE;

// Position in the RCC->APB2ENR register to enable the preipheral clock
const BYTE_TYPE SYSCFG_RCC_POS = 14U;

/**
 * Memory Mapping Selection
 *
 * sets which memory is mapped at address 0x0
 */
static const BYTE_TYPE SYSCFG_SWP_FMC_POS  = 10U;
static const BYTE_TYPE SYSCFG_FB_MODE_POS  = 8U;
static const BYTE_TYPE SYSCFG_MEM_MODE_POS = 0U;
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
typedef enum SysCfgExtiCr{
	SYSCFG_EXTI_CR1 = 0U,
	SYSCFG_EXTI_CR2,
	SYSCFG_EXTI_CR3,
	SYSCFG_EXTI_CR4
}SysCfgExtiCr;

// Mapping of GPIO pin to CR registers
static const SysCfgExtiCr SYSCFG_EXTI_CR_REGS[NUM_GPIO_PINS] = {
		SYSCFG_EXTI_CR1,
		SYSCFG_EXTI_CR1,
		SYSCFG_EXTI_CR1,
		SYSCFG_EXTI_CR1,
		SYSCFG_EXTI_CR2,
		SYSCFG_EXTI_CR2,
		SYSCFG_EXTI_CR2,
		SYSCFG_EXTI_CR2,
		SYSCFG_EXTI_CR3,
		SYSCFG_EXTI_CR3,
		SYSCFG_EXTI_CR3,
		SYSCFG_EXTI_CR3,
		SYSCFG_EXTI_CR4,
		SYSCFG_EXTI_CR4,
		SYSCFG_EXTI_CR4,
		SYSCFG_EXTI_CR4
};



#ifdef __cplusplus
}
#endif

#endif //STM32F4_SYSTEM_CONFIG_DEF_H
