#ifndef DMA_TYPES_H
#define DMA_TYPES_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "boolean.h"
#include "register.h"

/**
 * DMA Stream Select enum
 * 	Enum maps to the address in memory of the stream registers
*/
typedef enum DmaStreamSelect{
	DMA1_STREAMSELECT_0 = 0U,
	DMA1_STREAMSELECT_1,
	DMA1_STREAMSELECT_2,
	DMA1_STREAMSELECT_3,
	DMA1_STREAMSELECT_4,
	DMA1_STREAMSELECT_5,
	DMA1_STREAMSELECT_6,
	DMA1_STREAMSELECT_7,
	DMA2_STREAMSELECT_0,
	DMA2_STREAMSELECT_1,
	DMA2_STREAMSELECT_2,
	DMA2_STREAMSELECT_3,
	DMA2_STREAMSELECT_4,
	DMA2_STREAMSELECT_5,
	DMA2_STREAMSELECT_6,
	DMA2_STREAMSELECT_7
}DmaStreamSelect;

#ifndef NUM_DMA_STREAMS
	#define NUM_DMA_STREAMS 16
#endif //NUM_DMA_STREAMS

static const WORD_TYPE DMA_STREAMS[NUM_DMA_STREAMS] = {
	(WORD_TYPE)DMA1_Stream0_BASE,
	(WORD_TYPE)DMA1_Stream1_BASE,
	(WORD_TYPE)DMA1_Stream2_BASE,
	(WORD_TYPE)DMA1_Stream3_BASE,
	(WORD_TYPE)DMA1_Stream4_BASE,
	(WORD_TYPE)DMA1_Stream5_BASE,
	(WORD_TYPE)DMA1_Stream6_BASE,
	(WORD_TYPE)DMA1_Stream7_BASE,
	(WORD_TYPE)DMA2_Stream0_BASE,
	(WORD_TYPE)DMA2_Stream1_BASE,
	(WORD_TYPE)DMA2_Stream2_BASE,
	(WORD_TYPE)DMA2_Stream3_BASE,
	(WORD_TYPE)DMA2_Stream4_BASE,
	(WORD_TYPE)DMA2_Stream5_BASE,
	(WORD_TYPE)DMA2_Stream6_BASE,
	(WORD_TYPE)DMA2_Stream7_BASE
}

/**
 * DMA_SxCR Stream Configure Register Channel Select enum
*/
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

/**
 * DMA_SxCR Stream Configure Register Memory Burst Transfer Select enum
*/
typedef enum DmaStreamCrMBurstSelect{
	DMA_STREAM_CR_MBURSTSELECT_SINGLE = 0U,
	DMA_STREAM_CR_MBURSTSELECT_INCR4,
	DMA_STREAM_CR_MBURSTSELECT_INCR8,
	DMA_STREAM_CR_MBURSTSELECT_INCR16
}DmaStreamCrMBurstSelect;

/**
 * DMA_SxCR Stream Configure Register Peripheral Burst Transfer Select enum
*/
typedef enum DmaStreamCrPBurstSelect{
	DMA_STREAM_CR_PBURSTSELECT_SINGLE = 0U,
	DMA_STREAM_CR_PBURSTSELECT_INCR4,
	DMA_STREAM_CR_PBURSTSELECT_INCR8,
	DMA_STREAM_CR_PBURSTSELECT_INCR16
}DmaStreamCrPBurstSelect;

/**
 * DMA_SxCR Stream Configure Register Priority Level Select enum
*/
typedef enum DmaStreamCrPlSelect{
	DMA_STREAM_CR_PLSELECT_LOW = 0U,
	DMA_STREAM_CR_PLSELECT_MED,
	DMA_STREAM_CR_PLSELECT_HIGH,
	DMA_STREAM_CR_PLSELECT_VERYHIGH
}DmaStreamCrPlSelect;

/**
 * DMA_SxCR Stream Configure Register Memory Data Size Select enum
*/
typedef enum DmaStreamCrMSizeSelect{
	DMA_STREAM_CR_MSIZESELECT_BYTE = 0U,
	DMA_STREAM_CR_MSIZESELECT_HALFWORD,
	DMA_STREAM_CR_MSIZESELECT_WORD,
}DmaStreamCrMSizeSelect;

/**
 * DMA_SxCR Stream Configure Register Peripheral Data Size Select enum
*/
typedef enum DmaStreamCrPSizeSelect{
	DMA_STREAM_CR_PSIZESELECT_BYTE = 0U,
	DMA_STREAM_CR_PSIZESELECT_HALFWORD,
	DMA_STREAM_CR_PSIZESELECT_WORD
}DmaStreamCrPSizeSelect;

/**
 * DMA_SxCR Stream Configure Register Data Transfer Direction Select enum
*/
typedef enum DmaStreamCrDirSelect{
	DMA_STREAM_CR_DIRSELECT_PERTOMEM = 0U,
	DMA_STREAM_CR_DIRSELECT_MEMTOPER,
	DMA_STREAM_CR_DIRSELECT_MEMTOMEM
}DmaStreamCrDirSelect;




/**
 *  DMA_SxCR bitfield selection enum
 */
typedef enum Dma_SxCR_BitFieldSelect{
	DMA_SxCR_CHANNEL_SELECT = 0U,
	DMA_SxCR_MBURST_SELECT,
	DMA_SxCR_PBURST_SELECT,
	DMA_SxCR_CT_SELECT,
	DMA_SxCR_DBM_SELECT,
	DMA_SxCR_PL_SELECT,
	DMA_SxCR_PINCOS_SELECT,
	DMA_SxCR_MSIZE_SELECT,	
	DMA_SxCR_PSIZE_SELECT,
	DMA_SxCR_MINC_SELECT,	 
	DMA_SxCR_PINC_SELECT,
	DMA_SxCR_CIRC_SELECT,
	DMA_SxCR_DIR_SELECT,
	DMA_SxCR_PFCTRL_SELECT,
	DMA_SxCR_TCIE_SELECT,
	DMA_SxCR_HTIE_SELECT,
	DMA_SxCR_TEIE_SELECT,
	DMA_SxCR_DMEIE_SELECT
}Dma_SxCR_BitFieldSelect;

/*
 * DMA_SxFCR Stream FIFO Control Register FIFO Status enum
 */
typedef enum DmaStreamFcrFifoStatus{
	DMA_STREAM_FCR_FSSELECT_LT_FOURTH = 0U,
	DMA_STREAM_FCR_FSSELECT_LT_HALF,
	DMA_STREAM_FCR_FSSELECT_LT_THREE_FOURTHS,
	DMA_STREAM_FCR_FSSELECT_LT_FULL,
	DMA_STREAM_FCR_FSSELECT_EMPTY,
	DMA_STREAM_FCR_FSSELECT_LT_FULL
}DmaStreamFcrFifoStatus;

/*
 * DMA_SxFCR Stream FIFO Control Register FIFO Threshold Select enum
 */
typedef enum DmaStreamFcrFifoThreshSelect{
	DMA_STREAM_FCR_FTHSELECT_FOURTH = 0U,
	DMA_STREAM_FCR_FTHSELECT_HALF,
	DMA_STREAM_FCR_FTHSELECT_THREE_FOURTHS,
	DMA_STREAM_FCR_FTHSELECT_FULL
}DmaStreamFcrFifoThreshSelect;

#ifdef __cplusplus
}
#endif

#endif //DMA_TYPES_H