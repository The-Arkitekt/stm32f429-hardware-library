#ifndef NVIC
#define NVIC

#ifdef __cplusplus
	extern "C" {
#endif

#include "register.h"

/**
 * NVIC_BASE = 0xE000E100UL
 */

/**
 * Pointers to Interrupt Set Enable registers
 *
 * 	- each register is offset by 0x04 (32-bit)
 */
static WORD_TYPE* const __NVIC_ISER[8U] =
{
	0xE000E100U,	//!< ISER0 : interrupts[0,31]
	0xE000E104U,	//!< ISER1 : interrupts[32,63]
	0xE000E108U,	//!< ISER2 : interrupts[64,95]
	0xE000E10CU,	//!< ISER3 : interrupts[96,127]
	0xE000E110U,	//!< ISER4 : interrupts[128.159]
	0xE000E114U,	//!< ISER5 : interrupts[160,191]
	0xE000E118U,	//!< ISER6 : interrupts[192,223]
	0xE000E11CU  	//!< ISER7 : interrupts[224,239]
};

/**
 * Pointers to Interrupt Clear Enable registers
 *
 * 	- each register is offset by 0x04 (32-bit)
 */
static WORD_TYPE* const __NVIC_ICER[8U] =
{
	0xE000E180UL,	//!< ICER0 : interrupts[0,31]
	0xE000E184UL,	//!< ICER1 : interrupts[32,63]
	0xE000E188UL, 	//!< ICER2 : interrupts[64,95]
	0xE000E18CUL,	//!< ICER3 : interrupts[96,127]
	0xE000E190UL,	//!< ICER4 : interrupts[128,159]
	0xE000E194UL,	//!< ICER5 : interrupts[160,191]
	0xE000E198UL,	//!< ICER6 : interrupts[192,223]
	0xE000E19CUL	    //!< ICER7 : interrupts[224,239]
};


/**
 * Interrupt vector positions
 *
 * 	- Only including interrupts that are used in this library
 * 	- The priority of the interrupts is inverse to the position
 */
typedef enum INTERRUPT_VECTOR_ENUM
{
	// EXTI Interrupts
	EXTI0_INTERRUPT = 6UL,
	EXTI1_INTERRUPT = 7UL,
	EXTI2_INTERRUPT = 8UL,
	EXTI3_INTERRUPT = 9UL,
	EXTI4_INTERRUPT = 10UL,

	// DMA 1 Stream interrupts group 1
	DMA1_STREAM0_INTERRUPT = 11UL,
	DMA1_STREAM1_INTERRUPT = 12UL,
	DMA1_STREAM2_INTERRUPT = 13UL,
	DMA1_STREAM3_INTERRUPT = 14UL,
	DMA1_STREAM4_INTERRUPT = 15UL,
	DMA1_STREAM5_INTERRUPT = 16UL,
	DMA1_STREAM6_INTERRUPT = 17UL,

	// DMA1 Stream interrupts group 2
	DMA1_STREAM7_INTERRUPT = 47UL,

	// DMA 2 Stream interrupts group 1
	DMA2_STREAM0_INTERRUPT = 56UL,
	DMA2_STREAM1_INTERRUPT = 57UL,
	DMA2_STREAM2_INTERRUPT = 58UL,
	DMA2_STREAM3_INTERRUPT = 59UL,
	DMA2_STREAM4_INTERRUPT = 60UL,

	// DMA 2 Stream interrupts group 2
	DMA2_STREAM5_INTERRUPT = 68UL,
	DMA2_STREAM6_INTERRUPT = 69UL,
	DMA2_STREAM7_INTERRUPT = 70UL

}INTERRUPT_VECTOR_ENUM;



/**
 * Enable the given DMA stream interrupt request
 */
void NVIC_enable_IRQ(const INTERRUPT_VECTOR_ENUM irq);

/**
 * Disable the given DMA stream interrupt request
 */
void NVIC_disable_IRQ(const INTERRUPT_VECTOR_ENUM irq);





#ifdef __cplusplus
}
#endif

#endif //NVIC
