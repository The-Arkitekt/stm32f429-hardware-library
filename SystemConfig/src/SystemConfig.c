
#include "SystemConfig.h"
#include "BitManipulation.h"

void SysCfgSetSwap(){
	setWordBits(1U, SYSCFG_SWP_FMC_POS, &(SYSCFG_REG->MEMRMP));
}
void SysCfgResetSwap(){
	clearWordBits(3U, SYSCFG_SWP_FMC_POS, &(SYSCFG_REG->MEMRMP));
}

void SysCfgSetFbMode(){
	setWordBits(1U, SYSCFG_FB_MODE_POS, &(SYSCFG_REG->MEMRMP));
}
void SysCfgResetFbMode(){
	clearWordBits(1U, SYSCFG_FB_MODE_POS, &(SYSCFG_REG->MEMRMP));
}
void SysCfgMemMapSetMode(SysCfgMemMapMode mode){
	setWordBits(mode, SYSCFG_MEM_MODE_POS, &(SYSCFG_REG->MEMRMP));
}


void SysCfgSelectEthInterface(SysCfgEthInterface interface){
	setWordBits(interface, SYSCFG_ETH_SEL_POS, &(SYSCFG_REG->PMC));
}

ReturnCode SysCfgEnableExti(SysCfgExtiCr controlRegister, GpioPortSelect port, GpioPinSelect pin){
	if (isValidExtiPin(controlRegister, pin) == FALSE){
		return RETURNCODE_INVALID_INPUT;
	}

	/*
	 * four pins per register, each pin gets 4 cbits
	 *
	 * (pin % 4) * 4 == (pin & 3) << 2
	 */
	BYTE_TYPE location = (pin & 3) << 2;
	setWordBits(port, location, &(SYSCFG_REG->EXTICR[controlRegister]));

	return RETURNCODE_SUCCESS;
}
ReturnCode SysCfgDisableExti(SysCfgExtiCr controlRegister, GpioPortSelect port, GpioPinSelect pin){
	if (isValidExtiPin(controlRegister, pin) == FALSE){
		return RETURNCODE_INVALID_INPUT;
	}

	BYTE_TYPE location = (pin & 3) << 2;
	clearWordBits(port, location, &(SYSCFG_REG)->EXTICR[controlRegister]);

	return RETURNCODE_SUCCESS;
}
Boolean isValidExtiPin(SysCfgExtiCr controlRegister, GpioPinSelect pin){
	if (controlRegister == SYSCFG_EXTI_CR1){
		if ((pin >= EXTI_CR1_MIN_PIN) && (pin <= EXTI_CR1_MAX_PIN)){
			return TRUE;
		}
	}
	else if(controlRegister == SYSCFG_EXTI_CR2){
		if ((pin >= EXTI_CR2_MIN_PIN) && (pin <= EXTI_CR2_MAX_PIN)){
			return TRUE;
		}
	}
	else if (controlRegister == SYSCFG_EXTI_CR3){
		if ((pin >= EXTI_CR3_MIN_PIN) && (pin <= EXTI_CR3_MAX_PIN)){
			return TRUE;
		}
	}
	else if (controlRegister == SYSCFG_EXTI_CR4){
		if ((pin >= EXTI_CR4_MIN_PIN) && (pin <= EXTI_CR4_MAX_PIN)){
			return TRUE;
		}
	}
	return FALSE;
}
