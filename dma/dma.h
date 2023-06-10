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
	DMA_1 = 0x40026000U, //!< Address of DMA1
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
 * DMA INTERRUPTS
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
 * DMA STREAM CONFIGURATION REGISTER
 */
typedef enum DMA_STREAM_CR_FIELDS_ENUM
{
	DMA_STREAM_CR_EN     = 0x1U,	//!< mask of stream enable bitfield
	DMA_STREAM_CR_DMEIE  = 0x2U,	//!< mask of direct mode error interrupt bitfield
	DMA_STREAM_CR_TEIE	 = 0x4U, 	//!< mask of transfer error interrrupt bitfield
	DMA_STREAM_CR_HTIE   = 0x8U, 	//!< mask of half transfer interrupt bitfield
	DMA_STREAM_CR_TCIE   = 0x10U,	//!< mask of transfer complere interrupt bitfield
	DMA_STREAM_CR_PFCTRL = 0x20U,	//!< mask of peripheral flow controller bitfield
	DMA_STREAM_CR_DIR    = 0xC0U,	//!< mask of data transfer direction bitfield
	DMA_STREAM_CR_CIRC   = 0x100U,	//!< mask of circular mode bitfield
	DMA_STREAM_CR_PINC   = 0x200U,	//!< mask of peripheral incrememnt bitfield
	DMA_STREAM_CR_MINC   = 0x400U,	//!< mask of memory increment bitfield
	DMA_STREAM_CR_PSIZE  = 0x1800U,	//!< mask of peripheral data size bitfield
	DMA_STREAM_CR_MSIZE  = 0x6000U, //!< mask of memory data size bitfield
	DMA_STREAM_CR_PINCOS = 0x8000U, //!< mask of peripheral increment offset size bitfield
	DMA_STREAM_CR_PL     = 0x30000U, //!< mask of priority level bitfield
	DMA_STREAM_CR_DBM    = 0x40000U, //!< mask of double buffer mode bitfield
	DMA_STREAM_CR_CT     = 0x80000U, //!< mask of current target bitfield
	DMA_STREAM_CR_PBURST = 0x600000U, //!< mask of peripheral burst transfer configuration bitfield
	DMA_STREAM_CR_MBURST = 0x1800000U, //!< mask of memory burst transfer configuration bitfield
	DMA_STREAM_CR_CHSEL  = 0xE000000U,	//!< Channel selection bitfield
}DMA_STREAM_CR_FIELDS_ENUM;

typedef enum DMA_STREAM_CR_VALUE_ENUM
{
	// Configuration enable
	DMA_STREAM_CR_DISABLE = 0U,					//!< Stream is ready when configuration is disabled
	DMA_STREAM_CR_ENABLE  = DMA_STREAM_CR_EN,	//!< Enable the configuration of the stream

	// Direct mode error interrupt
	DMA_STREAM_CR_DMEIE_DISABLE = 0U,					//!< Direct mode error interrupt disabled
	DMA_STREAM_CR_DMEIE_ENABLE  = DMA_STREAM_CR_DMEIE,	//!< Direct mode error interrupt enabled

	// Transfer error interrrupt
	DMA_STREAM_CR_TEIE_DISABLE = 0U,					//!< Transfer error interrupt disabled
	DMA_STREAM_CR_TEIE_ENABLE  = DMA_STREAM_CR_TEIE,	//!< Transfer error interrupt enabled

	// Half transfer error interrrupt
	DMA_STREAM_CR_HTIE_DISABLE = 0U,					//!< Half transfer interrupt disabked
	DMA_STREAM_CR_HTIE_ENABLE  = DMA_STREAM_CR_HTIE,	//!< Hald transfer interrupt enabled

	// Transfer complete interrupt
	DMA_STREAM_CR_TCIE_DISABLE = 0U,					//!< Transfer complete interrupt disabled
	DMA_STREAM_CR_TCIE_ENABLE  = DMA_STREAM_CR_TCIE,	//!< Transfer complete interrupt enabled

	// Peripheral flow controller
	DMA_STREAM_CR_PFCTRL_DMA = 0U,						//!< The DMA is the flow controller
	DMA_STREAM_CR_PFCTRL_PER = DMA_STREAM_CR_PFCTRL,	//!< The peripheral is the flow controller

	// Data transfer direction
	DMA_STREAM_CR_DIR_PER_TO_MEM = 0U, 	  //!< Peripheral-to-memory
	DMA_STREAM_CR_DIR_MEM_TO_PER = 0x40U, //!< Memory-to-peripheral
	DMA_STREAM_CR_DIR_MEM_TO_MEM = 0x80U, //!< Memory-to-memory

	// Circular mode
	DMA_STREAM_CR_CIRC_DISABLE = 0U,				 //!< Circular mode disabled
	DMA_STREAM_CR_CIRC_ENABLE  = DMA_STREAM_CR_CIRC, //!< Circular mode enabled

	// Peripheral increment mode
	DMA_STREAM_CR_PINC_FIXED = 0U,					//!< Peripheral address pointer is fixed
	DMA_STREAM_CR_PINC_INCR  = DMA_STREAM_CR_PINC,	//!< Peripheral address pointer is incremented

	// Memory increment mode
	DMA_STREAM_CR_MINC_FIXED = 0U,				   //!< Memory address pointer is fixed
	DMA_STREAM_CR_MINC_INCR  = DMA_STREAM_CR_MINC, //!< Memory address pointer is incremented

	// Peripheral data size
	DMA_STREAM_CR_PSIZE_BYTE 	  = 0U,		 //!< Byte
	DMA_STREAM_CR_PSIZE_HALF_WORD = 0x800U,	 //!< Half-Word
	DMA_STREAM_CR_PSIZE_WORD      = 0x1000U, //!< Word

	// Memory data size
	DMA_STREAM_CR_MSIZE_BYTE      = 0U,		 //!< Byte
	DMA_STREAM_CR_MSIZE_HALF_WORD = 0x2000U, //!< Half-Word
	DMA_STREAM_CR_MSIZE_WORD      = 0x4000U, //!< Word

	// Peripheral increment offset size
	DMA_STREAM_CR_PINCOS_PSIZE = 0U,				   //!< PSIZE value is used as increment offset size
	DMA_STREAM_CR_PINCOS_FOUR  = DMA_STREAM_CR_PINCOS, //!< Increment offset size is fixed at 4

	// Priority Level
	DMA_STREAM_CR_PL_LOW = 0U,			           //!< Low priority
	DMA_STREAM_CR_PL_MED = 0x10000U,	           //!< Medium priority
	DMA_STREAM_CR_PL_HIGH = 0x20000U, 			   //!< High priority
	DMA_STREAM_CR_PL_VERY_HIGH = DMA_STREAM_CR_PL, //!< Very high priority

	// Double buffer mode
	DMA_STREAM_CR_DBM_NO_SWITCH = 0U,				 //!< No buffer switching at the end of transfer
	DMA_STREAM_CR_DBM_SWITCH    = DMA_STREAM_CR_DBM, //!< Memory target switched at the end of the DMA transfer

	// Current Target
	DMA_STREAM_CR_CT_MEM0 = 0U,		//!< The current target memory is Memory 0 (SxM0AR)
	DMA_STREAM_CR_CT_MEM1 = DMA_STREAM_CR_CT, //!< The current target memory is Memory 1 (SxM1AR)

	// Peripheral burst transfer configuration
	DMA_STREAM_CR_PBURST_SINGLE = 0U,					//!< Single transfer
	DMA_STREAM_CR_PBURST_INCR4  = 0x200000U,			//!< Incremental burst of four beats
	DMA_STREAM_CR_PBURST_INCR8	= 0x400000U,			//!< Incremental burst of eight beats
	DMA_STREAM_CR_PBURST_INCR16 = DMA_STREAM_CR_PBURST, //!< Incremental burst of sixteen beats

	// Memory burst transfer configuration
	DMA_STREAM_CR_MBURST_SINGLE = 0U,				 	//!< Single transfer
	DMA_STREAM_CR_MBURST_INCR4  = 0x800000U,			//!< Incremental burst of four beats
	DMA_STREAM_CR_MBURST_INCR8  = 0x1000000U, 			//!< Incremental burst of eight beats
	DMA_STREAM_CR_MBURST_INCR16 = DMA_STREAM_CR_MBURST, //!< Incremental burst of sixteen beats

	// Channel selection
	DMA_STREAM_CR_CHSEL_0 = 0U,					 //!< Channel 0
	DMA_STREAM_CR_CHSEL_1 = 0x2000000U,			 //!< Channel 1
	DMA_STREAM_CR_CHSEL_2 = 0x4000000U,			 //!< Channel 2
	DMA_STREAM_CR_CHSEL_3 = 0x6000000U, 		 //!< Channel 3
	DMA_STREAM_CR_CHSEL_4 = 0x8000000U, 		 //!< Channel 4
	DMA_STREAM_CR_CHSEL_5 = 0xA000000U, 		 //!< Channel 5
	DMA_STREAM_CR_CHSEL_6 = 0xC000000U, 		 //!< Channel 6
	DMA_STREAM_CR_CHSEL_7 = DMA_STREAM_CR_CHSEL, //!< Channel 7

}DMA_STREAM_CR_VALUE_ENUM;

/**
 * DMA STREAM FIFO CONTROL REGISTER
 */
typedef enum DMA_STREAM_FCR_FIELDS_ENUM
{
	DMA_STREAM_FCR_FTH 	 = 0x3U,	//!< mask of FIFO threshold selection bitfield
	DMA_STREAM_FCR_DMDIS = 0x4U,	//!< mask of Direct mode disable bitfield
	DMA_STREAM_FCR_FS    = 0x38U,	//!< mask of FIFO status bitfield
	DMA_STREAM_FCR_FEIE  = 0x80U	//!< mask of FIFO interrupt enable bitfield
}DMA_STREAM_FCR_FIELDS_ENUM;

typedef enum DMA_STREAM_FCR_VALUE_ENUM
{
	// FIFO threshold selection
	DMA_STREAM_FCR_FTH_QUARTER 		 = 0U,	   		 	  //!< 1/4 full FIFO
	DMA_STREAM_FCR_FTH_HALF   		 = 0x1U,			  //!< 1/2 full FIFO
	DMA_STREAM_FCR_FTH_THREE_QUARTER = 0x2U,    		  //!< 3/4 full FIFO
	DMA_STREAM_FCR_FTH_FULL			 = DMA_STREAM_FCR_FTH, //!< Full FIFO

	// Direct mode disable
	DMA_STREAM_FCR_DMDIS_ENABLE  = 0U,					 //!< Direct mode is enabled
	DMA_STREAM_FCR_DMDIS_DISABLE = DMA_STREAM_FCR_DMDIS, //!< Direct mode is disabled

	// FIFO status
	DMA_STREAM_FCR_FS_QUARTER       = 0U,	  //!< 0 < fifo_level < 1/4
	DMA_STREAM_FCR_FS_HALF	        = 0x8U,	  //!< 1/4 < fifo_level < 1/2
	DMA_STREAM_FCR_FS_THREE_QUARTER = 0x10U,  //!< 1/2 < fifo_level < 3/4
	DMA_STREAM_FCR_FS_LESS_FULL     = 0x18U,  //!< 3/4 < fifo_level < full
	DMA_STREAM_FCR_FS_EMPTY         = 0x20U,  //!< FIFO is empty
	DMA_STREAM_FCR_FS_FULL          = 0x28U,  //!< FIFO is full

	// FIFO threshold selection
	DMA_STREAM_FCR_FEIE_DISABLE = 0U,	//!< FIFO error intrrupt disabled
	DMA_STREAM_FCR_FEIE_ENABLE  = DMA_STREAM_FCR_FEIE //!< FIFO error interrupt enabled
}DMA_STREAM_FCR_VALUE_ENUM;


/**
 * Get the position of the given stream in all of the interrupt registers
 */
BYTE_TYPE __DMA_get_stream_interrupt_pos(const DMA_STREAM_ENUM stream);


/**
 * Get / Clear the interrupt status of DMA stream
*/
Boolean DMA_get_interrupt_status(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_INTERRUPT_ENUM interrupt);
void DMA_clear_interrupt_flag(const DMA_ENUM dma,
							  const DMA_STREAM_ENUM stream,
							  const DMA_STREAM_INTERRUPT_ENUM interrupt);


/**
 * Set / get stream configuration value
 */
void DMA_set_stream_configuration(const DMA_ENUM dma,
								  const DMA_STREAM_ENUM stream,
								  const DMA_STREAM_CR_FIELDS_ENUM cr_field,
								  const DMA_STREAM_CR_VALUE_ENUM cr_value);
DMA_STREAM_CR_VALUE_ENUM DMA_get_stream_configuration(const DMA_ENUM dma,
													  const DMA_STREAM_ENUM stream,
													  const DMA_STREAM_CR_FIELDS_ENUM cr_field);

/**
 * Set / Get stream number of data items to transfer
 */
void DMA_set_stream_num_data_items(const DMA_ENUM dma,
								   const DMA_STREAM_ENUM stream,
								   const HALF_WORD_TYPE num_data);
HALF_WORD_TYPE DMA_get_stream_num_data_items(const DMA_ENUM dma,
										     const DMA_STREAM_ENUM stream);

/**
 * Set / get stream peripheral address
 */
void DMA_set_stream_peripheral_address(const DMA_ENUM dma,
									   const DMA_STREAM_ENUM stream,
									   const WORD_TYPE address);
WORD_TYPE DMA_get_stream_peripheral_address(const DMA_ENUM dma,
											const DMA_STREAM_ENUM stream);

/**
 * Set / Get stream memory 0 address
 */
void DMA_set_stream_memory_0_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address);
WORD_TYPE DMA_get_stream_memory_0_address(const DMA_ENUM dma,
										  const DMA_STREAM_ENUM stream);

/**
 * Set / Get stream memory 1 address
 */
void DMA_set_stream_memory_1_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address);
WORD_TYPE DMA_get_stream_memory_1_address(const DMA_ENUM dma,
										  const DMA_STREAM_ENUM stream);

/**
 * Set / Get stream FIFO Control / Status
 */
void DMA_set_stream_fifo_control(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_FCR_FIELDS_ENUM fcr_field,
								 const DMA_STREAM_FCR_VALUE_ENUM fcr_value);
DMA_STREAM_FCR_VALUE_ENUM DMA_get_stream_fifo_status(const DMA_ENUM dma,
												     const DMA_STREAM_ENUM stream,
													 const DMA_STREAM_FCR_FIELDS_ENUM fcr_field);

#ifdef __cplusplus
}
#endif

#endif //DMA_H
