
#include "SystemConfig.h"
#include "BitManipulation.h"

void SysCfgEnable(){
	setWordBits(1U, SYSCFG_RCC_POS, &(RCC->APB2ENR));
}

void SysCfgDisable(){
	clearWordBits(1U, SYSCFG_RCC_POS, &(RCC->APB2ENR));
}

void SysCfgSetSwap(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	setWordBits(1U, SYSCFG_SWP_FMC_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}
void SysCfgResetSwap(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	clearWordBits(0b11, SYSCFG_SWP_FMC_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}

void SysCfgSetFbMode(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	setWordBits(1U, SYSCFG_FB_MODE_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}
void SysCfgResetFbMode(){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	clearWordBits(1U, SYSCFG_FB_MODE_POS, &(sysConfigReg->MEMRMP));
	SysCfgDisable();
}
void SysCfgMemMapSetMode(const SysCfgMemMapMode mode){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;

	WORD_TYPE tmp = sysConfigReg->MEMRMP;
	clearWordBits(0b111, SYSCFG_FB_MODE_POS, &tmp);
	setWordBits(mode, SYSCFG_MEM_MODE_POS, &tmp);
	sysConfigReg->MEMRMP = tmp;

	SysCfgDisable();
}


void SysCfgSelectEthInterface(const SysCfgEthInterface interface){
	SysCfgEnable();
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	setWordBits(interface, SYSCFG_ETH_SEL_POS, &(sysConfigReg->PMC));
	SysCfgDisable();
}

ReturnCode SysCfgEnableExti(const GpioPortSelect port, const GpioPinSelect pin){
	SysCfgExtiCr controlRegister = getExtiCr(pin);

	/*
	 * four pins per register, each pin gets 4 cbits
	 *
	 * (pin % 4) * 4 == (pin & 3) << 2
	 */

	SysCfgEnable();
	BYTE_TYPE location = (pin - (4*controlRegister)) * 4;
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	setWordBits(port, location, &(sysConfigReg->EXTICR[controlRegister]));
	//SysCfgDisable();

	return RETURNCODE_SUCCESS;
}
ReturnCode SysCfgDisableExti(const GpioPortSelect port, const GpioPinSelect pin){
	SysCfgExtiCr controlRegister = getExtiCr(pin);

	SysCfgEnable();
	BYTE_TYPE location = (pin & 3) << 2;
	SYSCFG_TYPE sysConfigReg = (SYSCFG_TYPE)SYSCFG_BASE_ADDR;
	clearWordBits(0b1111, location, &(sysConfigReg->EXTICR[controlRegister]));
	SysCfgDisable();

	return RETURNCODE_SUCCESS;
}
SysCfgExtiCr getExtiCr(const GpioPinSelect pin){

	if ((pin >= EXTI_1_MIN_PIN) && (pin <= EXTI_1_MAX_PIN)){
		return SYSCFG_EXTI_CR1;
	}
	if ((pin >= EXTI_2_MIN_PIN) && (pin <= EXTI_2_MAX_PIN)){
		return SYSCFG_EXTI_CR2;
	}
	if ((pin >= EXTI_3_MIN_PIN) && (pin <= EXTI_3_MAX_PIN)){
		return SYSCFG_EXTI_CR3;
	}
	// Must be cr4
	return SYSCFG_EXTI_CR4;
}
