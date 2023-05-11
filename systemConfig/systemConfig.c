#include "systemConfig.h"

void sysCfgEnable(){
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
}

void sysCfgDisable(){
	RCC->APB2ENR &= ~RCC_APB2ENR_SYSCFGEN;
}

void sysCfgMemRmpSetSwap(const Boolean value){
	sysCfgEnable();
	if (value == TRUE){
		SYSCFG->MEMRMP |= SYSCFG_MEMRMP_SWP_FMC_0;
	}
	else{
		SYSCFG->MEMRMP &= ~SYSCFG_MEMRMP_SWP_FMC;
	}
	sysCfgDisable();
}

void sysCfgMemRmpSetFbMode(const Boolean value){
	sysCfgEnable();
	if (value == TRUE){
		SYSCFG->MEMRMP |= SYSCFG_MEMRMP_UFB_MODE;
	}
	else{
		SYSCFG->MEMRMP &= ~SYSCFG_MEMRMP_UFB_MODE;
	}
	sysCfgDisable();
}

void sysCfgMemRmpSetMemMode(const SysCfgMemoryRemapModeSelect value){
	sysCfgEnable();
	WORD_TYPE tmp = SYSCFG->MEMRMP;
	tmp &= ~SYSCFG_MEMRMP_MEM_MODE;
	tmp |= ((BYTE_TYPE)value << SYSCFG_MEMRMP_MEM_MODE_Pos);
	SYSCFG->MEMRMP = tmp;
	sysCfgDisable();
}


void sysCfgPmcSetEthernet(const Boolean value){
	sysCfgEnable();
	if (value == TRUE){
		SYSCFG->PMC |= SYSCFG_PMC_MII_RMII_SEL;
	}
	else{
		SYSCFG->PMC &= ~SYSCFG_PMC_MII_RMII_SEL;
	}
	sysCfgDisable();
}

void sysCfgPmcSetAdcDc2(const SysCfgPmcAdcDc2Select position, const Boolean value){
	sysCfgEnable();
	if (value == TRUE){
		SYSCFG->PMC |= (1U << (BYTE_TYPE)position);
	}
	else{
		SYSCFG->PMC &= ~(1U << (BYTE_TYPE)position);
	}
}

void sysCfgSetExti(const GpioPortSelect portSelect, const GpioPinSelect pinSelect, const Boolean value){
	sysCfgEnable();
	BYTE_TYPE extiCrIndex = ((BYTE_TYPE)pinSelect / NUM_PINS_PER_CR_REG);
	BYTE_TYPE extiCrPosition = ((BYTE_TYPE)pinSelect - (extiCrIndex * NUM_PINS_PER_CR_REG)) << 2U;

	WORD_TYPE tmp = SYSCFG->EXTICR[extiCrIndex];
	// clear the bits
	tmp &= ~(0xF << extiCrPosition);
	if (value == TRUE){
		// set bits for port
		tmp |= ((BYTE_TYPE)portSelect << extiCrPosition);
	}

	SYSCFG->EXTICR[extiCrIndex] = tmp;
}
