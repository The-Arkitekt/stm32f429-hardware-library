
#include "systemConfig.h"

void sysCfgEnable(){
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
}

void sysCfgDisable(){
	RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN;
}

void sysCfgMemRmpSetSwap(const Boolean value){
	SysCfgEnable();
	if (value == TRUE){
		SYSCFG->MEMRMP |= SYSCFG_MEMRMP_SWP_FMC_0;
	}
	else{
		SYSCFG->MEMRMP &= ~SYSCFG_MEMRMP_SWP_FMC;
	}
	SysCfgDisable();
}
void SysCfgResetSwap(){
	SysCfgEnable();
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;
	clearWordBits(0b11, SYSCFG_SWP_FMC_POS, &(sysConfig->MEMRMP));
	SysCfgDisable();
}

void SysCfgSetFbMode(){
	SysCfgEnable();
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;
	setWordBits(1U, SYSCFG_FB_MODE_POS, &(sysConfig->MEMRMP));
	SysCfgDisable();
}
void SysCfgResetFbMode(){
	SysCfgEnable();
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;
	clearWordBits(1U, SYSCFG_FB_MODE_POS, &(sysConfig->MEMRMP));
	SysCfgDisable();
}
void SysCfgMemMapSetMode(const SysCfgMemMapMode mode){
	SysCfgEnable();
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;

	WORD_TYPE tmp = sysConfig->MEMRMP;
	clearWordBits(0b111, SYSCFG_FB_MODE_POS, &tmp);
	setWordBits(mode, SYSCFG_MEM_MODE_POS, &tmp);
	sysConfig->MEMRMP = tmp;

	SysCfgDisable();
}


void SysCfgSelectEthInterface(const SysCfgEthInterface interface){
	SysCfgEnable();
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;
	setWordBits(interface, SYSCFG_ETH_SEL_POS, &(sysConfig->PMC));
	SysCfgDisable();
}

ReturnCode SysCfgEnableExti(const GpioPortSelect port, const GpioPinSelect pin){
	SysCfgExtiCr controlRegister = SYSCFG_EXTI_CR_REGS[pin];

	/*
	 * four pins per register, each pin gets 4 bits
	 *
	 * (pin % 4) * 4 == (pin & 3) << 2
	 */

	SysCfgEnable();
	BYTE_TYPE location = (pin - (4*controlRegister)) * 4;
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;
	setWordBits(port, location, &(sysConfig->EXTICR[controlRegister]));
	//SysCfgDisable();

	return RETURNCODE_SUCCESS;
}
ReturnCode SysCfgDisableExti(const GpioPortSelect port, const GpioPinSelect pin){
	SysCfgExtiCr controlRegister = SYSCFG_EXTI_CR_REGS[pin];

	SysCfgEnable();
	BYTE_TYPE location = (pin & 3) << 2;
	SYSCFG_TypeDef* sysConfig = (SYSCFG_TypeDef*)SYSCFG_BASE;
	clearWordBits(0b1111, location, &(sysConfig->EXTICR[controlRegister]));
	SysCfgDisable();

	return RETURNCODE_SUCCESS;
}
