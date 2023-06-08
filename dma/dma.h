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
	DMA_1 = 0x40026000U,	//!< Address of DMA1
	DMA_2 = 0x40026400U  //!< Address of DMA2
}DMA_ENUM;


/**
 * DMA REGISTER OFFSETS
 *
 * 	- Used as 'private' values to get specific registers
 * 	- Add to DMA_X address to get specific register address
*/
static const BYTE_TYPE __DMA_LISR_OFFSET  = 0U;		//!< Interrupt Status Low Register  (Streams 0-3)
static const BYTE_TYPE __DMA_HISR_OFFSET  = 0x4U;	//!< Interrupt Status High Register (Streams 4-7)
static const BYTE_TYPE __DMA_LIFCR_OFFSET = 0x8U;	//!< Interrupt Clear Low Register
static const BYTE_TYPE __DMA_HIFCR_OFFSET = 0xCU;	//!< Interrupt Clear High Register

/**
 * DMA STREAMS
 *
 * - Add these values to DMA address to get DMA_STREAM_X address
*/
typedef enum DMA_STREAM_ENUM
{
	DMA_STREAM_0 = 0x10U,	//!< Stream 0
	DMA_STREAM_1 = 0x28U,	//!< Stream 1
	DMA_STREAM_2 = 0x40U,   //!< Stream 2
	DMA_STREAM_3 = 0x58U,	//!< Stream 3
	DMA_STREAM_4 = 0x70U,	//!< Stream 4
	DMA_STREAM_5 = 0x88U,	//!< Stream 5
	DMA_STREAM_6 = 0xA0U,	//!< Stream 6
	DMA_STREAM_7 = 0xB8U,   //!< Stream 7
}DMA_STREAM_ENUM;

/**
 * DMA STREAM REGISTER OFFSETS
 *
 * 	- Used as 'private' variables to get specific registers
 * 	- Add to DMA_STREAM_X address to get specific register address
*/
static const BYTE_TYPE __DMA_STREAM_CR_OFFSET   = 0U;		//!< Stream Configuration Register
static const BYTE_TYPE __DMA_STREAM_NDTR_OFFSET = 0x4U;		//!< Stream Number of Data Register
static const BYTE_TYPE __DMA_STREAM_PAR_OFFSET  = 0x8U;		//!< Stream Peripheral Address Register
static const BYTE_TYPE __DMA_STREAM_M0AR_OFFSET = 0xCU;		//!< Stream Memory 0 Address Register
static const BYTE_TYPE __DMA_STREAM_M1AR_OFFSET = 0x10U;	//!< Stream Memory 1 Address Register
static const BYTE_TYPE __DMA_STREAM_FCR_OFFSET  = 0x14U;	//!< Stream FIFO Configuration Register

/**
 * DMA STREAM INTERRUPTS
 *
 * 	- Masks used to set or clear Interrupt related bits
*/
typedef enum DMA_STREAM_INTERRUPT_ENUM
{
	DMA_STREAM_FIFO_ERROR 		 = 0x1U,
	DMA_STREAM_DIRECT_MODE_ERROR = 0x4U,
	DMA_STREAM_TRANSFER_ERROR    = 0x8U,
	DMA_STREAM_HALF_TRANSFER     = 0x10U,
	DMA_STREAM_TRANSFER_COMPLETE = 0x20U
}DMA_STREAM_INTERRUPT_ENUM;

/**
 * Get the position of the given stream in all of the interrupt registers
 */
BYTE_TYPE __DMA_get_stream_interrupt_pos(const DMA_STREAM_ENUM stream);


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
