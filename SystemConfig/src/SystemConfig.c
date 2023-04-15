
#include "SystemConfig.h"
#include "BitManipulation.h"

void SysCfgEnable(){
	setWordBits(1U, 14U, &(RCC->APB2ENR));
}

void SysCfgDisable(){
	clearWordBits(1U, 14U, &(RCC->APB2ENR));
}

void SysCfgSetSwap(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	setWordBits(1U, SYSCFG_SWP_FMC_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}
void SysCfgResetSwap(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	clearWordBits(3U, SYSCFG_SWP_FMC_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}

void SysCfgSetFbMode(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	setWordBits(1U, SYSCFG_FB_MODE_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}
void SysCfgResetFbMode(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	clearWordBits(1U, SYSCFG_FB_MODE_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}
void SysCfgMemMapSetMode(const SysCfgMemMapMode mode){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	setWordBits(mode, SYSCFG_MEM_MODE_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}


void SysCfgSelectEthInterface(const SysCfgEthInterface interface){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	setWordBits(interface, SYSCFG_ETH_SEL_POS, &(sysConfigReg->PMC));
	SysCfgDisable();
}

ReturnCode SysCfgEnableExti(const SysCfgExtiCr controlRegister, const GpioPortSelect port, const GpioPinSelect pin){
	if (isValidExtiPin(controlRegister, pin) == FALSE){
		return RETURNCODE_INVALID_INPUT;
	}

	/*
	 * four pins per register, each pin gets 4 cbits
	 *
	 * (pin % 4) * 4 == (pin & 3) << 2
	 */

	SysCfgEnable();
	BYTE_TYPE location = (pin - (4*controlRegister)) * 4;
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	setWordBits(port, location, &(sysConfigReg->EXTICR[controlRegister]));
	//SysCfgDisable();

	return RETURNCODE_SUCCESS;
}
ReturnCode SysCfgDisableExti(const SysCfgExtiCr controlRegister, const GpioPortSelect port, const GpioPinSelect pin){
	if (isValidExtiPin(controlRegister, pin) == FALSE){
		return RETURNCODE_INVALID_INPUT;
	}

	SysCfgEnable();
	BYTE_TYPE location = (pin & 3) << 2;
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCONFIG_BASE;
	clearWordBits(port, location, &(sysConfigReg->EXTICR[controlRegister]));
	SysCfgDisable();

	return RETURNCODE_SUCCESS;
}
Boolean isValidExtiPin(const SysCfgExtiCr controlRegister, const GpioPinSelect pin){
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
