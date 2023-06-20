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
static WORD_TYPE* const __RCC_AHB1ENR = (WORD_TYPE*)0x40023830UL;	//!< Enable the clock for AHB1 peripherals
static WORD_TYPE* const __RCC_APB2ENR = (WORD_TYPE*)0x40023844UL;   //!< Enable the clock for APB2 peripherals

/**
 * AHB1 REGISTERS
 *
 * 	- masks used to set or clear AHB1 bits in all AHB1 registers
 * 	- Only care about the bits related to peripherals used in this library
 */
typedef enum RCC_AHB1_FIELDS_ENUM
{
	RCC_AHB1_GPIOA = 0x1UL,		//!< mask of GPIOA bitfield
	RCC_AHB1_GPIOB = 0x2UL,		//!< mask of GPIOB bitfield
	RCC_AHB1_GPIOC = 0x4UL, 	//!< mask of GPIOC bitfield
	RCC_AHB1_GPIOD = 0x8UL,		//!< mask of GPIOD bitfield
	RCC_AHB1_GPIOE = 0x10UL,	//!< mask of GPIOE bitfield
	RCC_AHB1_GPIOF = 0x20UL,	//!< mask of GPIOF bitfield
	RCC_AHB1_GPIOG = 0x40UL,	//!< mask of GPIOG bitfield
	RCC_AHB1_GPIOH = 0x80UL,	//!< mask of GPIOH bitfield
	RCC_AHB1_GPIOI = 0x100UL,	//!< mask of GPIOI bitfield
	RCC_AHB1_GPIOJ = 0x200UL,	//!< mask of GPIOJ bitfield
	RCC_AHB1_GPIOK = 0x400UL,	//!< mask of GPIOK bitfield

	RCC_AHB1_DMA1  = 0x200000U,	//!< mask of DMA1 bitfield
	RCC_AHB1_DMA2  = 0x400000U,	//!< mask of DMA2 bitfield
}RCC_AHB1_FIELDS_ENUM;

/**
 * APB2 REGISTERS
 *
 * 	- masks used to set or clear APB2 bits in all AHB1 registers
 * 	- Only care about the bits related to peripherals used in this library
 */
typedef enum RCC_APB2_FIELDS_ENUM
{
	RCC_APB2_SYSCFG = 0x4000UL	//!< mask of SYSCFG bitfield
}RCC_APB2_FIELDS_ENUM;

/**
 * Enable the clock for the given AHB1 peripheral
 */
void RCC_enable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral);

/**
 * Disable the clock for the given AHB1 peripheral
 */
void RCC_disable_AHB1(const RCC_AHB1_FIELDS_ENUM peripheral);

/**
 * Enable the clock for the given APB2 peripheral
*/
void RCC_enable_APB2(const RCC_APB2_FIELDS_ENUM peripheral);

/**
 * Disavle the clock for the given APB2 peripheral
*/
void RCC_disable_APB2(const RCC_APB2_FIELDS_ENUM peripheral);

#ifdef __cplusplus
}
#endif

#endif //RCC_H
