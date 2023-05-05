#ifndef STM32F429_DMA_DEF_H
#define STM32F429_DMA_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32.h"
#include "BitManipulationDef.h"
#include "CommonDef.h"

//	typedef struct
//	{
//	  __IO uint32_t CR;     /*!< DMA stream x configuration register      */
//	  __IO uint32_t NDTR;   /*!< DMA stream x number of data register     */
//	  __IO uint32_t PAR;    /*!< DMA stream x peripheral address register */
//	  __IO uint32_t M0AR;   /*!< DMA stream x memory 0 address register   */
//	  __IO uint32_t M1AR;   /*!< DMA stream x memory 1 address register   */
//	  __IO uint32_t FCR;    /*!< DMA stream x FIFO control register       */
//	} DMA_Stream_TypeDef;
typedef DMA_Stream_TypeDef * DMA_STREAM_TYPE;

typedef enum Dma1StreamSelect{
	DMA1_STREAMSELECT_0 = DMA1_Stream0_BASE,
	DMA1_STREAMSELECT_1 = DMA1_Stream1_BASE,
	DMA1_STREAMSELECT_2 = DMA1_Stream2_BASE,
	DMA1_STREAMSELECT_3 = DMA1_Stream3_BASE,
	DMA1_STREAMSELECT_4 = DMA1_Stream4_BASE,
	DMA1_STREAMSELECT_5 = DMA1_Stream5_BASE,
	DMA1_STREAMSELECT_6 = DMA1_Stream6_BASE,
	DMA1_STREAMSELECT_7 = DMA1_Stream7_BASE
}Dma1StreamSelect;

typedef enum Dma2StreamSelect{
	DMA2_STREAMSELECT_0 = DMA2_Stream0_BASE,
	DMA2_STREAMSELECT_1 = DMA2_Stream1_BASE,
	DMA2_STREAMSELECT_2 = DMA2_Stream2_BASE,
	DMA2_STREAMSELECT_3 = DMA2_Stream3_BASE,
	DMA2_STREAMSELECT_4 = DMA2_Stream4_BASE,
	DMA2_STREAMSELECT_5 = DMA2_Stream5_BASE,
	DMA2_STREAMSELECT_6 = DMA2_Stream6_BASE,
	DMA2_STREAMSELECT_7 = DMA2_Stream7_BASE
}Dma2StreamSelect;

/*
 * DMA_SxCR Stream configuration register
 */
// Register field positions
const static BYTE_TYPE DMA_STREAM_CR_CHAN_POS   = DMA_SxCR_CHSEL_Pos;
const static BYTE_TYPE DMA_STREAM_CR_MBURST_POS = DMA_SxCR_MBURST_Pos;
const static BYTE_TYPE DMA_STREAM_CR_PBURST_POS = DMA_SxCR_PBURST_Pos;
const static BYTE_TYPE DMA_STREAM_CR_CT_POS     = DMA_SxCR_CT_Pos;
const static BYTE_TYPE DMA_STREAM_CR_DBM_POS    = DMA_SxCR_DBM_Pos;
const static BYTE_TYPE DMA_STREAM_CR_PL_POS     = DMA_SxCR_PL_Pos;
const static BYTE_TYPE DMA_STREAM_CR_PINCOS_POS = DMA_SxCR_PINCOS_Pos;
const static BYTE_TYPE DMA_STREAM_CR_MSIZE_POS  = DMA_SxCR_MSIZE_Pos;
const static BYTE_TYPE DMA_STREAM_CR_PSIZE_POS  = DMA_SxCR_PSIZE_Pos;
const static BYTE_TYPE DMA_STREAM_CR_MINC_POS   = DMA_SxCR_MINC_Pos;
const static BYTE_TYPE DMA_STREAM_CR_PINC_POS   = DMA_SxCR_PINC_Pos;
const static BYTE_TYPE DMA_STREAM_CR_CIRC_POS   = DMA_SxCR_CIRC_Pos;
const static BYTE_TYPE DMA_STREAM_CR_DIR_POS    = DMA_SxCR_DIR_Pos;
const static BYTE_TYPE DMA_STREAM_CR_PFCTRL_POS = DMA_SxCR_PFCTRL_Pos;
const static BYTE_TYPE DMA_STREAM_CR_TCIE_POS   = DMA_SxCR_TCIE_Pos;
const static BYTE_TYPE DMA_STREAM_CR_HTIE_POS   = DMA_SxCR_HTIE_Pos;
const static BYTE_TYPE DMA_STREAM_CR_TEIE_POS   = DMA_SxCR_TEIE_Pos;
const static BYTE_TYPE DMA_STREAM_CR_DMEIE_POS  = DMA_SxCR_DMEIE_Pos;
const static BYTE_TYPE DMA_STREAM_CR_EN_POS     = DMA_SxCR_EN_Pos;

// Channel selection options
typedef enum DmaStreamCrChanSelect{
	DMA_STREAM_CR_CHANSELECT_0 = 0U,
	DMA_STREAM_CR_CHANSELECT_1,
	DMA_STREAM_CR_CHANSELECT_2,
	DMA_STREAM_CR_CHANSELECT_3,
	DMA_STREAM_CR_CHANSELECT_4,
	DMA_STREAM_CR_CHANSELECT_5,
	DMA_STREAM_CR_CHANSELECT_6,
	DMA_STREAM_CR_CHANSELECT_7
}DmaStreamCrChanSelect;

// Memory burst transfer configuration options
typedef enum DmaStreamCrMBurstSelect{
	DMA_STREAM_CR_MBURSTSELECT_SINGLE = 0U,
	DMA_STREAM_CR_MBURSTSELECT_INCR4,
	DMA_STREAM_CR_MBURSTSELECT_INCR8,
	DMA_STREAM_CR_MBURSTSELECT_INCR16
}DmaStreamCrMBurstSelect;

// Peripheral burst transfer configuration options
typedef enum DmaStreamCrPBurstSelect{
	DMA_STREAM_CR_PBURSTSELECT_SINGLE = 0U,
	DMA_STREAM_CR_PBURSTSELECT_INCR4,
	DMA_STREAM_CR_PBURSTSELECT_INCR8,
	DMA_STREAM_CR_PBURSTSELECT_INCR16
}DmaStreamCrPBurstSelect;

// Current target options
typedef enum DmaStreamCrCtSelect{
	DMA_STREAM_CR_CTSELECT_MEM0 = 0U,
	DMA_STREAM_CR_CTSELECT_MEM1
}DmaStreamCrCtSelect;

// Priority level options
typedef enum DmaStreamCrPlSelect{
	DMA_STREAM_CR_PLSELECT_LOW = 0U,
	DMA_STREAM_CR_PLSELECT_MED,
	DMA_STREAM_CR_PLSELECT_HIGH,
	DMA_STREAM_CR_PLSELECT_VERYHIGH
}DmaStreamCrPlSelect;

// Peripheral increment offset size options
typedef enum DmaStreamCrPincosSelect{
	DMA_STREAM_CR_PINCOSSELECT_PSIZE = 0U,
	DMA_STREAM_CR_PINCOSSELECT_4
};

// Memory data size options
typedef enum DmaStreamCrMSizeSelect{
	DMA_STREAM_CR_MSIZESELECT_BYTE = 0U,
	DMA_STREAM_CR_MSIZESELECT_HALFWORD,
	DMA_STREAM_CR_MSIZESELECT_WORD,
}DmaStreamCrMSizeSelect;

// Peripheral data size options
typedef enum DmaStreamCrPSizeSelect{
	DMA_STREAM_CR_PSIZESELECT_BYTE = 0U,
	DMA_STREAM_CR_PSIZESELECT_HALFWORD,
	DMA_STREAM_CR_PSIZESELECT_WORD
}DmaStreamCrPSizeSelect;

// Memory increment mode options and Peripheral increment mode options
typedef enum DmaStreamCrIncSelect{
	DMA_STREAM_CR_MINCSELECT_FIXED = 0U,
	DMA_STREAM_CR_MINCSELECT_INCR
}DmaStreamCrMinSelect;

// Data transfer direction options
typedef enum DmaStreamCrDirSelect{
	DMA_STREAM_CR_DIRSELECT_PERTOMEM = 0U,
	DMA_STREAM_CR_DIRSELECT_MEMTOPER,
	DMA_STREAM_CR_DIRSELECT_MEMTOMEM
};

// Peripheral flow controller options
typedef enum DmaStreamCrPfctrlSelect{
	DMA_STREAM_CR_PFCTRLSELECT_DMA = 0U,
	DMA_STREAM_CR_PFCTRLSELECT_PER
};

// Struct used to set the CR register for a given stream
typedef struct DmaStreamConfigStruct{
	DmaStreamCrChanSelect   channel;
	DmaStreamCrMBurstSelect memoryBurst;
	DmaStreamCrPBurstSelect peripheralBurst;
	DmaStreamCrCtSelect     currentTarget;
	Boolean                 doubleBufferModeEnable;
	DmaStreamCrPlSelect     priorityLevel;
	DmaStreamCrPincosSelect PeripheralIncrement;
	DmaStreamCrMSizeSelect  memoryDataSize;
	DmaStreamCrPSizeSelect  peripheralDataSize;
	DmaStreamCrIncSelect    memoryIncrementMode;
	DmaStreamCrIncSelect    peripheralIncrementMode;
	Boolean                 circularModeEnable;
	DmaStreamCrDirSelect    dataTransferDirection;
	DmaStreamCrPfctrlSelect peripheralFlowController;
	Boolean                 transferCompleteInterrupEnable;
	Boolean                 halfTransferInterruptEnable;
	Boolean					transferErrorInterruptEnable;
	Boolean					directModeErrorInterruptEnable;
}DmaStreamConfigStruct;

/*
 * DMA_SxFCR Stream FIFO control register
 */
// Register field positions
static const BYTE_TYPE DMA_STREAM_FCR_FEIE_POS  = DMA_SxFCR_FEIE_Pos;
static const BYTE_TYPE DMA_STREAM_FCR_FS_POS    = DMA_SxFCR_FS_Pos;
static const BYTE_TYPE DMA_STREAM_FCR_DMDIS_POS = DMA_SxFCR_DMDIS_Pos;
static const BYTE_TYPE DMA_STREAM_FCR_FTH_POS   = DMA_SxFCR_FTH_Pos;

// FIFO Status options
typedef enum DmaStreamFcrFifoStatusSelect{
	DMA_STREAM_FCR_FSSELECT_LT_FOURTH = 0U,
	DMA_STREAM_FCR_FSSELECT_LT_HALF,
	DMA_STREAM_FCR_FSSELECT_LT_THREE_FOURTHS,
	DMA_STREAM_FCR_FSSELECT_LT_FULL,
	DMA_STREAM_FCR_FSSELECT_EMPTY,
	DMA_STREAM_FCR_FSSELECT_LT_FULL
}DmaStreamFcrFifoStatusSelect;

// FIFO threshold selection options
typedef enum DmaStreamFcrFifoThreshSelect{
	DMA_STREAM_FCR_FTHSELECT_FOURTH = 0U,
	DMA_STREAM_FCR_FTHSELECT_HALF,
	DMA_STREAM_FCR_FTHSELECT_THREE_FOURTHS,
	DMA_STREAM_FCR_FTHSELECT_FULL
}DmaStreamFcrFifoThreshSelect;

// Struct used to set the FCR register for a given stream
typedef struct DmaStreamFifoConfigStruct{
	Boolean                      FifoErrorInterruptEnable;
	DmaStreamFcrFifoStatusSelect fifoStatus;
	Boolean                      directModeDisable;
	DmaStreamFcrFifoThreshSelect fifoThresholdSelection;
}DmaStreamFifoConfigStruct;

//typedef struct
//{
//  __IO uint32_t LISR;   /*!< DMA low interrupt status register,      Address offset: 0x00 */
//  __IO uint32_t HISR;   /*!< DMA high interrupt status register,     Address offset: 0x04 */
//  __IO uint32_t LIFCR;  /*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
//  __IO uint32_t HIFCR;  /*!< DMA high interrupt flag clear register, Address offset: 0x0C */
//} DMA_TypeDef;
typedef DMA_TypeDef * DMA_TYPE;

/**
 * DMA_LISR DMA low interrupt status register 
*/
// Register field locations
static const BYTE_TYPE


#ifdef __cplusplus
}
#endif

#endif //STM32F429_DMA_DEF_H
