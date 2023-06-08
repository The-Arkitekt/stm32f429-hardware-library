#ifndef DMA_H
#define DMA_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "boolean.h"
#include "register.h"

/**
 * DMA 
*/
typedef enum DMA_ENUM
{
	DMA1 = 0U,
	DMA2
}DMA_ENUM;
static const BYTE_TYPE __NUM_DMA = 2U;
static const WORD_TYPE __DMA_ADDR[__NUM_DMA] = 
{
	0x40026000U,	//!< Address of DMA1
	0x40026400U		//!< Address of DMA2
};

/**
 * DMA REGISTER OFFSETS
*/
static const BYTE_TYPE __DMA_LISR_OFFSET  = 0U;
static const BYTE_TYPE __DMA_HISR_OFFSET  = 0x4U;
static const BYTE_TYPE __DMA_LIFCR_OFFSET = 0x8U;
static const BYTE_TYPE __DMA_HIFCR_OFFSET = 0xCU;

/**
 * DMA STREAMS
*/
typedef enum DMA_STREAM_ENUM
{
	DMA_STREAM_0 = 0U,
	DMA_STREAM_1,
	DMA_STREAM_2,
	DMA_STREAM_3,
	DMA_STREAM_4,
	DMA_STREAM_5,
	DMA_STREAM_6,
	DMA_STREAM_7,
}DMA_STREAM_ENUM;
static const BYTE_TYPE __NUM_STREAMS_PER_DMA = 8U;
static const BYTE_TYPE __DMA_STREAM_OFFSET[__NUM_STREAMS_PER_DMA] = 
{
	0x10U,		//!< Stream 0 
	0x28U,		//!< Stream 1
	0x40U,		//!< Stream 2
	0x58U,		//!< Stream 3
	0x70U,		//!< Stream 4
	0x88U,		//!< Stream 5
	0xA0U,		//!< Stream 6
	0xB8U,		//!< Stream 7
}

/**
 * DMA STREAM REGISTERS
*/
static const BYTE_TYPE __DMA_STREAM_CR_OFFSET   = 0U;
static const BYTE_TYPE __DMA_STREAM_NDTR_OFFSET = 0x4U;
static const BYTE_TYPE __DMA_STREAM_PAR_OFFSET  = 0x8U;
static const BYTE_TYPE __DMA_STREAM_M0AR_OFFSET = 0xCU;
static const BYTE_TYPE __DMA_STREAM_M1AR_OFFSET = 0x10U;
static const BYTE_TYPE __DMA_STREAM_FCR_OFFSET  = 0x14U;

/**
 * DMA STREAM INTERRUPTS
*/
typedef enum DMA_STREAM_INTERRUPT_ENUM
{
	DMA_STREAM_FIFO_ERROR = 0U,
	DMA_STREAM_DIRECT_MODE_ERROR,
	DMA_STREAM_TRANSFER_ERROR,
	DMA_STREAM_HALF_TRANSFER,
	DMA_STREAM_TRANSFER_COMPLETE
}DMA_STREAM_INTERRUPT_ENUM;
static const BYTE_TYPE __NUM_DMA_STREAM_INTERRUPT_TYPES = 5U;
static const BYTE_TYPE __DMA_STREAM_INTERRUPT_BIT[__NUM_DMA_STREAM_INTERRUPT_TYPES] = 
{
	0x1U,	//!< FIFO error
	0x4U,	//!< Direct Mode error
	0x8U,   //!< Transfer error
	0x10U,  //!< Half Transfer
	0x20U,  //!< Treansfer complete
}
static const BYTE_TYPE __NUM_DMA_STREAMS_PER_INTERRUPT_REG = 4U;
static const BYTE_TYPE __DMA_STREAM_INTERRUPT_POS[__NUM_STREAMS_PER_INTERRUPT_REG] = 
{
	0U,		//!< STREAM 0/4
	6U,		//!< STREAM 1/5
	16U,    //!< STREAM 2/6
	22U     //!< STREAM 3/7
}

/**
 * Get the interrupt status of DMA stream
*/
Boolean DMA_get_interrupt_status(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_INTERRUPT_ENUM interrupt);

/**
 * Clear the interrupt flag of DMA stream
*/
void DMA_clear_interrupt_flag(const DMA_ENUM dma,
							  const DMA_STREAM_ENUM stream,
							  const DMA_STREAM_INTERRUPT_ENUM interrupt);

/**
 * Enable the DMA peripheral in the RCC register
 * @param dma The dma to enable (1 or 2)
*/
void DMA_enable(const Dma dma);

/** 
 * Disable the DMA peripheral in the RCC register
 * @param dma The dma to disable (1 or 2)
*/
void DMA_disable(const Dma dma);

#ifdef __cplusplus
}
#endif

#endif //DMA_H
