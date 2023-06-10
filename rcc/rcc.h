#ifndef RCC_H
#define RCC_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "register.h"

/**
 * RCC
 */
static const WORD_TYPE RCC = 0x40023800U;	//!< Address of RCC

/**
 * RCC REGISTER OFFSETS
 *
 * 	- Only care about registers related to peripherals used in this library
 */
static const BYTE_TYPE __RCC_AHB1ENR_OFFSET = 0x30U;	//!< Enable the clock for AHB1 peripherals

/**
 * AHB1 REGISTERS
 *
 * 	- masks used to set or clear AHB1 bits in all AHB1 registers
 * 	- Only care about the bits related to peripherals used in this library
 */
typedef enum RCC_AHB1_FIELDS_ENUM
{
	RCC_AHB1_DMA1 = 0x200000U,	//!< mask of DMA1 bitfield
	RCC_AHB1_DMA2 = 0x400000U,	//!< mask of DMA2 bitfield
}RCC_AHB1_FIELDS_ENUM;

typedef enum RCC_AHB1ENR_VALUE_ENUM
{
	// DMA 1 clock enable
	RCC_AHB1ENR_DMA1_DISABLE = 0U,				//!< Disable the clock for the DMA1 peripheral
	RCC_AHB1ENR_DMA1_ENABLE = RCC_AHB1_DMA1,	//!< Enable the clock for the DMA1 peripheral

	// DMA 2 clock enable
	RCC_AHB1ENR_DMA2_DISABLE = 0U,				//!< Disable the clock for the DMA2 peripheral
	RCC_AHB1ENR_DMA2_ENABLE  = RCC_AHB1_DMA2,	//!< Enable the clock for the DMA2 peripheral
}RCC_AHB1ENR_VALUE_ENUM;

void RCC_set_AHB1_clock_enable(const RCC_AHB1_FIELDS_ENUM peripheral,
							   const RCC_AHB1ENR_VALUE_ENUM value);

#ifdef __cplusplus
}
#endif

#endif //RCC_H
