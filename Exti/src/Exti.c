
#include "Exti.h"
#include "BitManipulation.h"

/*
 * Interrupt Functions
 */
void ExtiInterruptInit(const ExtiConfigStruct exti){

	EXTI_TYPE extiReg = (EXTI_TYPE)EXTI_BASE_ADDR;

	// Set Rising Trigger
	if (exti.risingTrigger == TRUE){
		setWordBits(1U, exti.line, &(extiReg->RTSR));
	}
	else{
		clearWordBits(1U, exti.line, &(extiReg->RTSR));
	}

	// Set Falling Trigger
	if (exti.fallingTrigger == TRUE){
		setWordBits(1U, exti.line, &(extiReg->FTSR));
	}
	else{
		clearWordBits(1U, exti.line, &(extiReg->FTSR));
	}

	// set Mask bit
	setWordBits(1U, exti.line, &(extiReg->IMR));

}
void ExtiInterruptDeinit(const ExtiConfigStruct exti){

	EXTI_TYPE extiReg = (EXTI_TYPE)EXTI_BASE_ADDR;

	// Clear Rising Trigger
	clearWordBits(1U, exti.line, &(extiReg->RTSR));

	// Clear Falling Trigger
	clearWordBits(1U, exti.line, &(extiReg->FTSR));

	// Clear Mask Bit
	clearWordBits(1U, exti.line, &(extiReg->IMR));
}

void ExtiResetInterrupt(const ExtiLineSelect line){

	EXTI_TYPE extiReg = (EXTI_TYPE)EXTI_BASE_ADDR;

	// the bit is cleared by setting it ?!?! For real
	WORD_TYPE lineMask = generateWordMask(1U, line);

	extiReg->PR = lineMask;
}

/*
 * Event Functions
 */
void ExtiEventInit(const ExtiConfigStruct exti){

	EXTI_TYPE extiReg = (EXTI_TYPE)EXTI_BASE_ADDR;

	// Set Rising Trigger
	if (exti.risingTrigger == TRUE){
		setWordBits(1U, exti.line, &(extiReg->RTSR));
	}
	else{
		clearWordBits(1U, exti.line, &(extiReg->RTSR));
	}

	// Set Falling Trigger
	if (exti.fallingTrigger == TRUE){
		setWordBits(1U, exti.line, &(extiReg->FTSR));
	}
	else{
		clearWordBits(1U, exti.line, &(extiReg->FTSR));
	}

	// set Mask bit
	setWordBits(1U, exti.line, &(extiReg->EMR));
}
void ExtiEventDeinit(const ExtiConfigStruct exti){

	EXTI_TYPE extiReg = (EXTI_TYPE)EXTI_BASE_ADDR;

	// Clear Rising Trigger
	clearWordBits(1U, exti.line, &(extiReg->RTSR));

	// Clear Falling Trigger
	clearWordBits(1U, exti.line, &(extiReg->FTSR));

	// Clear Mask Bit
	clearWordBits(1U, exti.line, &(extiReg->EMR));
}

/**
 * For Both
 */
void ExtiTrigger(const ExtiLineSelect line){

	EXTI_TYPE extiReg = (EXTI_TYPE)EXTI_BASE_ADDR;
	setWordBits(1U, line, &(extiReg->SWIER));
}
ReturnCode enableExtiIrq(const IRQ_TYPE irq){

	if (isValidExtiIrq(irq) == FALSE){
		return RETURNCODE_INVALID_INPUT;
	}

	NVIC_EnableIRQ(irq);

	return RETURNCODE_SUCCESS;
}

ReturnCode disableExtiIrq(const IRQ_TYPE irq){
	if (isValidExtiIrq(irq) == FALSE){
		return RETURNCODE_INVALID_INPUT;
	}

	NVIC_DisableIRQ(irq);

	return RETURNCODE_SUCCESS;
}

Boolean isValidExtiIrq(const IRQ_TYPE irq){
	for (BYTE_TYPE i = 0U; i < NUM_EXTI_IRQS; ++i){
		if (irq == EXTI_IRQS[i]){
			return TRUE;
		}
	}

	return FALSE;
}

ReturnCode getExtiIrqType(const ExtiLineSelect line, IRQ_TYPE* const irq){

	if (line > NUM_EXTI_IRQS){
		return RETURNCODE_INVALID_INPUT;
	}

	(*irq) = EXTI_IRQS[line];

	return RETURNCODE_SUCCESS;
}
