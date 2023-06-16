#ifndef RCC_H
#define RCC_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "register.h"

/**
 * RCC REGISTERS
 *
 * 	- Pointers to specific RCC registers
 */
static const WORD_TYPE* __RCC_AHB1ENR = 0x40023830UL;	//!< Enable the clock for AHB1 peripherals

/**
 * AHB1 REGISTERS
 *
 * 	- masks used to set or clear AHB1 bits in all AHB1 registers
 * 	- Only care about the bits related to peripherals used in this library
 */
typedef enum RCC_AHB1_FIELDS_ENUM
{
	RCC_AHB1_GPIOA = 0x1U,		//!< mask of GPIOA bitfield
	RCC_AHB1_GPIOB = 0x2U,		//!< mask of GPIOB bitfield
	RCC_AHB1_GPIOC = 0x4U, 		//!< mask of GPIOC bitfield
	RCC_AHB1_GPIOD = 0x8U,		//!< mask of GPIOD bitfield
	RCC_AHB1_GPIOE = 0x10U,		//!< mask of GPIOE bitfield
	RCC_AHB1_GPIOF = 0x20U,		//!< mask of GPIOF bitfield
	RCC_AHB1_GPIOG = 0x40U,		//!< mask of GPIOG bitfield
	RCC_AHB1_GPIOH = 0x80U,		//!< mask of GPIOH bitfield
	RCC_AHB1_GPIOI = 0x100U,	//!< mask of GPIOI bitfield
	RCC_AHB1_GPIOJ = 0x200U,	//!< mask of GPIOJ bitfield
	RCC_AHB1_GPIOK = 0x400U,	//!< mask of GPIOK bitfield

	RCC_AHB1_DMA1  = 0x200000U,	//!< mask of DMA1 bitfield
	RCC_AHB1_DMA2  = 0x400000U,	//!< mask of DMA2 bitfield
}RCC_AHB1_FIELDS_ENUM;

/**
 * Enable the clock for the given AHB1 peripheral
 */
void RCC_enable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral);

/**
 * Disable the clock for the given AHB1 peripheral
 */
void RCC_disable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral);

#ifdef __cplusplus
}
#endif

#endif //RCC_H
