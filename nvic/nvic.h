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
	(WORD_TYPE*)0xE000E100U,	//!< ISER0 : interrupts[0,31]
	(WORD_TYPE*)0xE000E104U,	//!< ISER1 : interrupts[32,63]
	(WORD_TYPE*)0xE000E108U,	//!< ISER2 : interrupts[64,95]
	(WORD_TYPE*)0xE000E10CU,	//!< ISER3 : interrupts[96,127]
	(WORD_TYPE*)0xE000E110U,	//!< ISER4 : interrupts[128.159]
	(WORD_TYPE*)0xE000E114U,	//!< ISER5 : interrupts[160,191]
	(WORD_TYPE*)0xE000E118U,	//!< ISER6 : interrupts[192,223]
	(WORD_TYPE*)0xE000E11CU  	//!< ISER7 : interrupts[224,239]
};

/**
 * Pointers to Interrupt Clear Enable registers
 *
 * 	- each register is offset by 0x04 (32-bit)
 */
static WORD_TYPE* const __NVIC_ICER[8U] =
{
	(WORD_TYPE*)0xE000E180UL,	//!< ICER0 : interrupts[0,31]
	(WORD_TYPE*)0xE000E184UL,	//!< ICER1 : interrupts[32,63]
	(WORD_TYPE*)0xE000E188UL, 	//!< ICER2 : interrupts[64,95]
	(WORD_TYPE*)0xE000E18CUL,	//!< ICER3 : interrupts[96,127]
	(WORD_TYPE*)0xE000E190UL,	//!< ICER4 : interrupts[128,159]
	(WORD_TYPE*)0xE000E194UL,	//!< ICER5 : interrupts[160,191]
	(WORD_TYPE*)0xE000E198UL,	//!< ICER6 : interrupts[192,223]
	(WORD_TYPE*)0xE000E19CUL	    //!< ICER7 : interrupts[224,239]
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
	EXTI0_INTERRUPT = 6U,
	EXTI1_INTERRUPT = 7U,
	EXTI2_INTERRUPT = 8U,
	EXTI3_INTERRUPT = 9U,
	EXTI4_INTERRUPT = 10U,

	// DMA 1 Stream interrupts group 1
	DMA1_STREAM0_INTERRUPT = 11U,
	DMA1_STREAM1_INTERRUPT = 12U,
	DMA1_STREAM2_INTERRUPT = 13U,
	DMA1_STREAM3_INTERRUPT = 14U,
	DMA1_STREAM4_INTERRUPT = 15U,
	DMA1_STREAM5_INTERRUPT = 16U,
	DMA1_STREAM6_INTERRUPT = 17U,

	// EXTI Interrupts
	EXTI9_5_INTERRUPT      = 23U,
	EXTI15_10_INTERRUPT    = 40U,

	// DMA1 Stream interrupts group 2
	DMA1_STREAM7_INTERRUPT = 47U,

	// DMA 2 Stream interrupts group 1
	DMA2_STREAM0_INTERRUPT = 56U,
	DMA2_STREAM1_INTERRUPT = 57U,
	DMA2_STREAM2_INTERRUPT = 58U,
	DMA2_STREAM3_INTERRUPT = 59U,
	DMA2_STREAM4_INTERRUPT = 60U,

	// DMA 2 Stream interrupts group 2
	DMA2_STREAM5_INTERRUPT = 68U,
	DMA2_STREAM6_INTERRUPT = 69U,
	DMA2_STREAM7_INTERRUPT = 70U

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
