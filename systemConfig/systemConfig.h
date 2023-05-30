#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "register.h"
#include "boolean.h"
#include "gpio.h"

/**
 * Valid SYSCFG_MEMRMP bitfield values
 * 
 * 	SWP_FMC:
 * 		0: No FMC memory mapping swap
 * 		1: SDRAM banks and NAND bank 2/PCCARD mapping are swapped
 * 		2: Reserved (no effect)
 * 		3: Reserved (no effect)
 *	FB_MODE:
 * 		0: Flash bank 1 is mapped at 0x0800 0000 and flash bank 2 is mapped at 0x0810 0000
 * 		1: Flash bank 2 is mapped at 0x0810 0000 and flash bank 1 is mapped at 0x0800 0000
 * 	MEM_MODE
 * 		0: Main flash memory mapped at 0x0
 * 		1: System flash memory mapped at 0x0
 * 		2: FMC bank 1 mapped at 0x0
 * 		3: Embedded SRAM mapped at 0x0
 * 		4: FMC / SDRAM bank 1 mapped at 0x0
 * 		[5-7]: Reserved (no effect)
*/

/**
 * System Config Memory Remap (SYSCFG_MEMRMP) bitfield selection
*/
typedef enum SystemConfigMemoryRemapFieldSelect
{
	SYSCFG_MEMRMP_SWP_FMC_FIELD = 0U,	//!< FMC memory mapping swap
	SYSCFG_MEMRMP_FB_MODE_FIELD,		//!< Flash bank mode selection
	SYSCFG_MEMRMP_MEM_MODE_FIELD		//!< Memory mapping selection
}SystemConfigMemoryRemapFieldSelect;

/**
 * The number if bitfields in the System Config Memory Remap (SYSCFG_MEMRMP) register
*/
#ifndef NUM_SYSCFG_MEMRMP_FIELDS
	#define NUM_SYSCFG_MEMRMP_FIELDS 3U
#endif //NUM_SYSCFG_MEMRMP_FIELDS

/**
 * Array of bitfield details for the System Cn=onfig Memory Remap (SYSCFG_MEMRMP) register
*/
static const BitFieldDetails SYSCFG_MEMRMP_FIELD_DETAILS[NUM_SYSCFG_MEMRMP_FIELDS] =
{
	{SYSCFG_MEMRMP_SWP_FMC_Pos, 1U, TWO_BIT_MASK},				//!< FMC Memory Swap field details
	{SYSCFG_MEMRMP_UFB_MODE_Pos, ONE_BIT_MASK, ONE_BIT_MASK},	//!< Flash Bank Mode field details
	{SYSCFG_MEMRMP_MEM_MODE_Pos, 4U , THREE_BIT_MASK}			//!< Memory Mapping field details
};

/**
 * Valid SYSCFG_PMC bitfield values
 * 
 * 	MII_RMII_SEL:
 * 		0: MII interface selected
 * 		1: RMII PHY interface selected
 * 	ADCxDC2:
 * 		0: Reserved (no effect)
 * 		1: Refer to AN4073 on how to use this bit. 
 *			Note: These bits can be set only if the following conditions are met:
 *				- ADC clock higher or equal to 30 MHz.
 *				- Only one ADCxDC2 bit must be selected if ADC conversions do not start 
 *				  at the same time and the sampling times differ. 
 *				- These bits must not be set when the ADCDC1 bit is set in PWR_CR 
 *				  register.
*/

/**
 * System Config Peripheral Mode Configuration (SYSCFG_PMC) field selection
*/
typedef enum SystemConfigPeripheralModeFieldSelect
{
	SYSCFG_PMC_MII_RMII_SEL = 0U,	//!< Ethernet PHY interface selection
	SYSCFG_PMC_ADC3DC2,				//!< Refer to AN4073 
	SYSCFG_PMC_ADC2DC2,				//!< Refer to AN4073 
	SYSCFG_PMC_ADC3DC2				//!< Refer to AN4073 
}SystemConfigPeripheralModeFieldSelect;

/**
 * The number of bitfields in the System Config Peripheral Mode Configuration (SYSCFG_PMC) register
*/
#ifndef NUM_SYSCFG_PMC_FIELDS
	#define NUM_SYSCFG_PMC_FIELDS 4U
#endif //NUM_SYSCFG_PMC_FIELDS

/**
 * Array of bitfield positions in the System Config Peripheral Mode Configuration (SYSCFG_PMC) register
*/
static const BYTE_TYPE SYSCFG_PMC_FIELD_POS[NUM_SYSCFG_PMC_FIELDS] = 
{
	SYSCFG_PMC_MII_RMII_SEL_Pos, SYSCFG_PMC_ADC3DC2_Pos,
	SYSCFG_PMC_ADC2DC2_Pos, SYSCFG_PMC_ADC1DC2_Pos
};

/**
 * Valid SYSCFG_EXTICRx bitfield values
 * 	
 * 	EXTIx:
 * 		0: PortA Pin X is the input for EXTIx external interrupt
 * 		1: PortB Pin X is the input for EXTIx external interrupt
 *  	2: PortC Pin X is the input for EXTIx external interrupt
 * 	    3: PortD Pin X is the input for EXTIx external interrupt
 * 	    4: PortE Pin X is the input for EXTIx external interrupt
 * 	    5: PortF Pin X is the input for EXTIx external interrupt
 * 	    6: PortG Pin X is the input for EXTIx external interrupt
 * 	    7: PortH Pin X is the input for EXTIx external interrupt
 * 	    8: PortI Pin X is the input for EXTIx external interrupt
 * 	    9: PortJ Pin X is the input for EXTIx external interrupt
 * 	    10: PortK Pin X is the input for EXTIx external interrupt
 * 		[11-15]: Reserved (no effect)
*/

/**
 * Number of bits per SYSCFG_EXTICRx bitfield
*/
static const BYTE_TYPE SYSCFG_EXTICRx_BITS_PER_PIN = 4U;

/**
 * Mask for (SYSCFG_EXTICRx) register at each pin
*/
static const BYTE_TYPE SYSCFG_EXTICRx_FIELD_MASK = FOUR_BIT_MASK;

/**
 * Number of pins per SYSCFG_EXTICRx register
*/
static const BYTE_TYPE SYSCFG_EXTICRx_PINS_PER_REGISTER = 4U;

/**
 * Set system memory remap configuration
 * @param field The field to set
 * @param value The value to set in the field
*/
void setSystemConfigMemoryRemap(const SystemConfigMemoryRemapFieldSelect field, const BYTE_TYPE value);

/**
 * Read system memory remap configuration
 * @param field The field to read
 * @return The value of the memory remap configuration field
*/
BYTE_TYPE readSystemConfigMemoryRemap(const SystemConfigMemoryRemapFieldSelect field);

/**
 * Set system peripheral mode configuration
 * @param field The field to set
 * @param value The value to set in the field
*/
void setSystemConfigPeripheralMode(const SystemConfigPeripheralModeFieldSelect field, const Boolean value);

/**
 * Read system peripheral mode configuration
 * @param field The field to read
 * @return The value of the peripheral mode configuration field
*/
Boolean readSystemConfigPeripheralMode(const SystemConfigPeripheralModeFieldSelect field);

/**
 * Set system external interrupt source configuration
 * @param port The port to set as external interrupt source
 * @param pin The pin to set as external interrupt source
*/
void setSystemExternalInterruptSource(const GpioPortSelect port, const BYTE_TYPE pin);

/**
 * Read which port is set for given pin EXTI line
 * @param pin The pin to check
 * @return The port set as source for that pin
*/
GpioPortSelect readSystemExternalInterruptSource(const BYTE_TYPE pin);

/**
 * Enable the System Config RCC clock
*/
void systemConfigEnable();

/**
 * Disable the system config RCC clock
*/
void systemConfigDisable();


#ifdef __cplusplus
}
#endif

#endif //SYSTEM_CONFIG_H
