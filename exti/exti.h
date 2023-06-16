#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif


#include "register.h"
#include "boolean.h"


/**
 * EXTI REGISTERS
 *
 * 	- Pointers to specific EXTI registers
 */
static const WORD_TYPE* __EXTI_IMR   = 0x40013C00UL;	//!< EXTI interrupt mask register
static const WORD_TYPE* __EXTI_EMR   = 0x40013C04UL; //!< EXTI event mask register
static const WORD_TYPE* __EXTI_RTSR  = 0x40013C08UL; //!< EXTI rising trigger event/interrupt configuration register
static const WORD_TYPE* __EXTI_FTSR  = 0x40013C0CUL; //!< EXTI falling trigger event/interrupt configuration register
static const WORD_TYPE* __EXTI_SWIER = 0x40013C10UL; //!< EXTI software interrupt trigger register
static const WORD_TYPE* __EXTI_PR    = 0x40013C14UL; //!< EXTI pending request register


/**
 * EXTI LINE
 *
 * 	- Masks used to set or clear bits for exti line
 */
typedef enum EXTI_LINE_ENUM
{
	EXTI_LINE_0  = 0x1UL,
	EXTI_LINE_1  = 0x2UL,
	EXTI_LINE_2  = 0x4UL,
	EXTI_LINE_3	 = 0x8UL,
	EXTI_LINE_4  = 0x10UL,
	EXTI_LINE_5  = 0x20UL,
	EXTI_LINE_6  = 0x40UL,
	EXTI_LINE_7  = 0x80UL,
	EXTI_LINE_8  = 0x100UL,
	EXTI_LINE_9  = 0x200UL,
	EXTI_LINE_10 = 0x400UL,
	EXTI_LINE_11 = 0x800UL,
	EXTI_LINE_12 = 0x1000UL,
	EXTI_LINE_13 = 0x2000UL,
	EXTI_LINE_14 = 0x4000UL,
	EXTI_LINE_15 = 0x8000UL,
	EXTI_LINE_16 = 0x10000UL,
	EXTI_LINE_17 = 0x20000UL,
	EXTI_LINE_18 = 0x40000UL,
	EXTI_LINE_19 = 0x80000UL,
	EXTI_LINE_20 = 0x100000UL,
	EXTI_LINE_21 = 0x200000UL,
	EXTI_LINE_22 = 0x400000UL
}EXTI_LINE_ENUM;



/**
 * Set/Remove the given EXTI line as interrupt source
 */
void EXTI_set_interrupt_source(const EXTI_LINE_ENUM exti_line, const Boolean set);

/**
 * Set/Remove the given EXTI line as event source
 */
void EXTI_set_event_source(const EXTI_LINE_ENUM exti_line, const Boolean set);

/**
 * Enable/Disable the given EXTI line rising trigger
 */
void EXTI_set_rising_trigger(const EXTI_LINE_ENUM exti_line, const Boolean enable);

/**
 * Enable/Disable the given EXTI line falling trigger
 */
void EXTI_set_falling_trigger(const EXTI_LINE_ENUM exti_line, const Boolean enable);

/**
 * Trigger a software interrupt/event at the given EXTI line
 */
void EXTI_trigger_interrupt_event(const EXTI_LINE_ENUM exti_line);

/**
 * Check if pending request exists for given EXTI line
 */
Boolean EXTI_pending_request_exists(const EXTI_LINE_ENUM exti_line);

/**
 * Clear pending request for given EXTI line
 */
void EXTI_clear_pending_request(const EXTI_LINE_ENUM exti_line);


#ifdef __cplusplus
}
#endif

#endif //EXTI_H
