#include "exti.h"
#include "register.h"

void extiInterruptInit(const ExtiConfigStruct extiConfig){

	// Set Rising Trigger
	if (extiConfig.risingTrigger == TRUE){
		EXTI->RTSR |= (WORD_TYPE)(extiConfig.line);
	}
	else{
		EXTI->RTSR &= ~((WORD_TYPE)(extiConfig.line));
	}

	// Set Falling Trigger
	if (extiConfig.fallingTrigger == TRUE){
		EXTI->FTSR |= (WORD_TYPE)(extiConfig.line);
	}
	else{
		EXTI->FTSR &= ~((WORD_TYPE)(extiConfig.line));
	}

	// set Mask bit
	EXTI->IMR |= (WORD_TYPE)(extiConfig.line);
}

void extiInterruptDeinit(const ExtiLineSelect line){

	// Clear Rising Trigger
	EXTI->RTSR &= ~((WORD_TYPE)line);

	// Clear Falling Trigger
	EXTI->FTSR &= ~((WORD_TYPE)line);

	// Clear Mask Bit
	EXTI->IMR &= ~((WORD_TYPE)line);
}

void extiResetInterrupt(const ExtiLineSelect line){

	// the bit is cleared by setting it
	EXTI->PR |= (WORD_TYPE)line;
}

void extiEventInit(const ExtiConfigStruct extiConfig){

	// Set Rising Trigger
	if (extiConfig.risingTrigger == TRUE){
		EXTI->RTSR |= (WORD_TYPE)(extiConfig.line);
	}
	else{
		EXTI->RTSR &= ~((WORD_TYPE)(extiConfig.line));
	}

	// Set Falling Trigger
	if (extiConfig.fallingTrigger == TRUE){
		EXTI->FTSR |= (WORD_TYPE)(extiConfig.line);
	}
	else{
		EXTI->FTSR &= ~((WORD_TYPE)(extiConfig.line));
	}

	// set Mask bit
	EXTI->EMR |= (WORD_TYPE)(extiConfig.line);
}

void extiEventDeinit(const ExtiLineSelect line){

	// Clear Rising Trigger
	EXTI->RTSR &= ~((WORD_TYPE)line);

	// Clear Falling Trigger
	EXTI->FTSR &= ~((WORD_TYPE)line);

	// Clear Mask Bit
	EXTI->EMR &= ~((WORD_TYPE)line);
}

void extiTrigger(const ExtiLineSelect line){
	EXTI->SWIER |= (WORD_TYPE)line;
}
void enableExtiIrq(const ExtiIrqSelect irq){
	NVIC_EnableIRQ((IRQn_Type)irq);
}

void disableExtiIrq(const ExtiIrqSelect irq){
	NVIC_DisableIRQ((IRQn_Type)irq);
}
