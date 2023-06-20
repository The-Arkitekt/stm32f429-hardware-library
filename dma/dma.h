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
	DMA_1 = 0x40026000UL, //!< Start address of DMA1 registers
	DMA_2 = 0x40026400UL  //!< Start ddress of DMA2 registers
}DMA_ENUM;


/**
 * DMA REGISTER OFFSETS
 *
 * 	- Used as 'private' values to get specific registers
 * 	- Add to DMA_X address to get specific register address
*/
static const BYTE_TYPE __DMA_INTERRUPT_STATUS_OFFSETS[2UL] =
{
	0UL,	//!< Low register  (Streams 0-3)
	0x4UL	//!< High register (Streams 4-7)
};
static const BYTE_TYPE __DMA_INTERRUPT_CLEAR_OFFSETS[2UL] =
{
	0x8UL,	//!< Low register
	0xCUL	//!< high register
};

/**
 * DMA INTERRUPTS
 *
 * 	- Masks used to set or clear Interrupt related bits
*/
typedef enum DMA_STREAM_INTERRUPT_ENUM
{
	DMA_STREAM_FIFO_ERROR 		 = 0x1UL,
	DMA_STREAM_DIRECT_MODE_ERROR = 0x4UL,
	DMA_STREAM_TRANSFER_ERROR    = 0x8UL,
	DMA_STREAM_HALF_TRANSFER     = 0x10UL,
	DMA_STREAM_TRANSFER_COMPLETE = 0x20UL
}DMA_STREAM_INTERRUPT_ENUM;

/**
 * DMA STREAMS
 *
 *	- Enum-array combination used in order to utilize same stream
 *	  enumeration in multiple functions
*/
typedef enum DMA_STREAM_ENUM
{
	DMA_STREAM_0 = 0U,	//!< Stream 0
	DMA_STREAM_1,		//!< Stream 1
	DMA_STREAM_2,  		//!< Stream 2
	DMA_STREAM_3,		//!< Stream 3
	DMA_STREAM_4,		//!< Stream 4
	DMA_STREAM_5,		//!< Stream 5
	DMA_STREAM_6,		//!< Stream 6
	DMA_STREAM_7   		//!< Stream 7
}DMA_STREAM_ENUM;
static const BYTE_TYPE __DMA_STREAM_OFFSETS[8U] =
{
	0x10U,	//!< Stream 0
	0x28U,	//!< Stream 1
	0x40U,  //!< Stream 2
	0x58U,	//!< Stream 3
	0x70U,	//!< Stream 4
	0x88U,	//!< Stream 5
	0xA0U,	//!< Stream 6
	0xB8U   //!< Stream 7
};
static const BYTE_TYPE __DMA_STREAM_POSITIONS[4U] =
{
	0U,  //!< Stream 0 and 4
	6U,  //!< Stream 1 and 5
	16U, //!< Stream 2 and 6
	22U, //!< Stream 3 and 7
};

/**
 * DMA STREAM REGISTER OFFSETS
 *
 * 	- Used as 'private' variables to get specific registers
 * 	- Add to DMA_STREAM_X address to get specific register address
*/
static const BYTE_TYPE __DMA_STREAM_CR_OFFSET   = 0UL;		//!< Stream Configuration Register
static const BYTE_TYPE __DMA_STREAM_NDTR_OFFSET = 0x4UL;		//!< Stream Number of Data Register
static const BYTE_TYPE __DMA_STREAM_PAR_OFFSET  = 0x8UL;		//!< Stream Peripheral Address Register
static const BYTE_TYPE __DMA_STREAM_M0AR_OFFSET = 0xCUL;		//!< Stream Memory 0 Address Register
static const BYTE_TYPE __DMA_STREAM_M1AR_OFFSET = 0x10UL;	//!< Stream Memory 1 Address Register
static const BYTE_TYPE __DMA_STREAM_FCR_OFFSET  = 0x14UL;	//!< Stream FIFO Configuration Register

/**
 * DMA STREAM CONFIGURATION REGISTER
 */
typedef enum DMA_STREAM_CR_FIELDS_ENUM
{
	DMA_STREAM_CR_EN     = 0x1UL,	//!< mask of stream enable bitfield
	DMA_STREAM_CR_DMEIE  = 0x2UL,	//!< mask of direct mode error interrupt bitfield
	DMA_STREAM_CR_TEIE	 = 0x4UL, 	//!< mask of transfer error interrrupt bitfield
	DMA_STREAM_CR_HTIE   = 0x8UL, 	//!< mask of half transfer interrupt bitfield
	DMA_STREAM_CR_TCIE   = 0x10UL,	//!< mask of transfer complere interrupt bitfield
	DMA_STREAM_CR_PFCTRL = 0x20UL,	//!< mask of peripheral flow controller bitfield
	DMA_STREAM_CR_DIR    = 0xC0UL,	//!< mask of data transfer direction bitfield
	DMA_STREAM_CR_CIRC   = 0x100UL,	//!< mask of circular mode bitfield
	DMA_STREAM_CR_PINC   = 0x200UL,	//!< mask of peripheral incrememnt bitfield
	DMA_STREAM_CR_MINC   = 0x400UL,	//!< mask of memory increment bitfield
	DMA_STREAM_CR_PSIZE  = 0x1800UL,	//!< mask of peripheral data size bitfield
	DMA_STREAM_CR_MSIZE  = 0x6000UL, //!< mask of memory data size bitfield
	DMA_STREAM_CR_PINCOS = 0x8000UL, //!< mask of peripheral increment offset size bitfield
	DMA_STREAM_CR_PL     = 0x30000UL, //!< mask of priority level bitfield
	DMA_STREAM_CR_DBM    = 0x40000UL, //!< mask of double buffer mode bitfield
	DMA_STREAM_CR_CT     = 0x80000UL, //!< mask of current target bitfield
	DMA_STREAM_CR_PBURST = 0x600000UL, //!< mask of peripheral burst transfer configuration bitfield
	DMA_STREAM_CR_MBURST = 0x1800000UL, //!< mask of memory burst transfer configuration bitfield
	DMA_STREAM_CR_CHSEL  = 0xE000000UL,	//!< Channel selection bitfield
}DMA_STREAM_CR_FIELDS_ENUM;

typedef enum DMA_STREAM_CR_VALUE_ENUM
{
	// Configuration enable
	DMA_STREAM_CR_DISABLE = 0UL,					//!< Stream is ready when configuration is disabled
	DMA_STREAM_CR_ENABLE  = DMA_STREAM_CR_EN,	//!< Enable the configuration of the stream

	// Direct mode error interrupt
	DMA_STREAM_CR_DMEIE_DISABLE = 0UL,					//!< Direct mode error interrupt disabled
	DMA_STREAM_CR_DMEIE_ENABLE  = DMA_STREAM_CR_DMEIE,	//!< Direct mode error interrupt enabled

	// Transfer error interrrupt
	DMA_STREAM_CR_TEIE_DISABLE = 0UL,					//!< Transfer error interrupt disabled
	DMA_STREAM_CR_TEIE_ENABLE  = DMA_STREAM_CR_TEIE,	//!< Transfer error interrupt enabled

	// Half transfer error interrrupt
	DMA_STREAM_CR_HTIE_DISABLE = 0UL,					//!< Half transfer interrupt disabked
	DMA_STREAM_CR_HTIE_ENABLE  = DMA_STREAM_CR_HTIE,	//!< Hald transfer interrupt enabled

	// Transfer complete interrupt
	DMA_STREAM_CR_TCIE_DISABLE = 0UL,					//!< Transfer complete interrupt disabled
	DMA_STREAM_CR_TCIE_ENABLE  = DMA_STREAM_CR_TCIE,	//!< Transfer complete interrupt enabled

	// Peripheral flow controller
	DMA_STREAM_CR_PFCTRL_DMA = 0UL,						//!< The DMA is the flow controller
	DMA_STREAM_CR_PFCTRL_PER = DMA_STREAM_CR_PFCTRL,	//!< The peripheral is the flow controller

	// Data transfer direction
	DMA_STREAM_CR_DIR_PER_TO_MEM = 0UL, 	  //!< Peripheral-to-memory
	DMA_STREAM_CR_DIR_MEM_TO_PER = 0x40UL, //!< Memory-to-peripheral
	DMA_STREAM_CR_DIR_MEM_TO_MEM = 0x80UL, //!< Memory-to-memory

	// Circular mode
	DMA_STREAM_CR_CIRC_DISABLE = 0UL,				 //!< Circular mode disabled
	DMA_STREAM_CR_CIRC_ENABLE  = DMA_STREAM_CR_CIRC, //!< Circular mode enabled

	// Peripheral increment mode
	DMA_STREAM_CR_PINC_FIXED = 0UL,					//!< Peripheral address pointer is fixed
	DMA_STREAM_CR_PINC_INCR  = DMA_STREAM_CR_PINC,	//!< Peripheral address pointer is incremented

	// Memory increment mode
	DMA_STREAM_CR_MINC_FIXED = 0UL,				   //!< Memory address pointer is fixed
	DMA_STREAM_CR_MINC_INCR  = DMA_STREAM_CR_MINC, //!< Memory address pointer is incremented

	// Peripheral data size
	DMA_STREAM_CR_PSIZE_BYTE 	  = 0UL,		 //!< Byte
	DMA_STREAM_CR_PSIZE_HALF_WORD = 0x800UL,	 //!< Half-Word
	DMA_STREAM_CR_PSIZE_WORD      = 0x1000UL, //!< Word

	// Memory data size
	DMA_STREAM_CR_MSIZE_BYTE      = 0UL,		 //!< Byte
	DMA_STREAM_CR_MSIZE_HALF_WORD = 0x2000UL, //!< Half-Word
	DMA_STREAM_CR_MSIZE_WORD      = 0x4000UL, //!< Word

	// Peripheral increment offset size
	DMA_STREAM_CR_PINCOS_PSIZE = 0UL,				   //!< PSIZE value is used as increment offset size
	DMA_STREAM_CR_PINCOS_FOUR  = DMA_STREAM_CR_PINCOS, //!< Increment offset size is fixed at 4

	// Priority Level
	DMA_STREAM_CR_PL_LOW = 0UL,			           //!< Low priority
	DMA_STREAM_CR_PL_MED = 0x10000UL,	           //!< Medium priority
	DMA_STREAM_CR_PL_HIGH = 0x20000UL, 			   //!< High priority
	DMA_STREAM_CR_PL_VERY_HIGH = DMA_STREAM_CR_PL, //!< Very high priority

	// Double buffer mode
	DMA_STREAM_CR_DBM_NO_SWITCH = 0UL,				 //!< No buffer switching at the end of transfer
	DMA_STREAM_CR_DBM_SWITCH    = DMA_STREAM_CR_DBM, //!< Memory target switched at the end of the DMA transfer

	// Current Target
	DMA_STREAM_CR_CT_MEM0 = 0UL,		//!< The current target memory is Memory 0 (SxM0AR)
	DMA_STREAM_CR_CT_MEM1 = DMA_STREAM_CR_CT, //!< The current target memory is Memory 1 (SxM1AR)

	// Peripheral burst transfer configuration
	DMA_STREAM_CR_PBURST_SINGLE = 0UL,					//!< Single transfer
	DMA_STREAM_CR_PBURST_INCR4  = 0x200000UL,			//!< Incremental burst of four beats
	DMA_STREAM_CR_PBURST_INCR8	= 0x400000UL,			//!< Incremental burst of eight beats
	DMA_STREAM_CR_PBURST_INCR16 = DMA_STREAM_CR_PBURST, //!< Incremental burst of sixteen beats

	// Memory burst transfer configuration
	DMA_STREAM_CR_MBURST_SINGLE = 0UL,				 	//!< Single transfer
	DMA_STREAM_CR_MBURST_INCR4  = 0x800000UL,			//!< Incremental burst of four beats
	DMA_STREAM_CR_MBURST_INCR8  = 0x1000000UL, 			//!< Incremental burst of eight beats
	DMA_STREAM_CR_MBURST_INCR16 = DMA_STREAM_CR_MBURST, //!< Incremental burst of sixteen beats

	// Channel selection
	DMA_STREAM_CR_CHSEL_0 = 0UL,					 //!< Channel 0
	DMA_STREAM_CR_CHSEL_1 = 0x2000000UL,			 //!< Channel 1
	DMA_STREAM_CR_CHSEL_2 = 0x4000000UL,			 //!< Channel 2
	DMA_STREAM_CR_CHSEL_3 = 0x6000000UL, 		 //!< Channel 3
	DMA_STREAM_CR_CHSEL_4 = 0x8000000UL, 		 //!< Channel 4
	DMA_STREAM_CR_CHSEL_5 = 0xA000000UL, 		 //!< Channel 5
	DMA_STREAM_CR_CHSEL_6 = 0xC000000UL, 		 //!< Channel 6
	DMA_STREAM_CR_CHSEL_7 = DMA_STREAM_CR_CHSEL, //!< Channel 7

}DMA_STREAM_CR_VALUE_ENUM;

/**
 * DMA STREAM FIFO CONTROL REGISTER
 */
typedef enum DMA_STREAM_FCR_FIELDS_ENUM
{
	DMA_STREAM_FCR_FTH 	 = 0x3UL,	//!< mask of FIFO threshold selection bitfield
	DMA_STREAM_FCR_DMDIS = 0x4UL,	//!< mask of Direct mode disable bitfield
	DMA_STREAM_FCR_FS    = 0x38UL,	//!< mask of FIFO status bitfield
	DMA_STREAM_FCR_FEIE  = 0x80UL	//!< mask of FIFO interrupt enable bitfield
}DMA_STREAM_FCR_FIELDS_ENUM;

typedef enum DMA_STREAM_FCR_VALUE_ENUM
{
	// FIFO threshold selection
	DMA_STREAM_FCR_FTH_QUARTER 		 = 0UL,	   		 	  //!< 1/4 full FIFO
	DMA_STREAM_FCR_FTH_HALF   		 = 0x1UL,			  //!< 1/2 full FIFO
	DMA_STREAM_FCR_FTH_THREE_QUARTER = 0x2UL,    		  //!< 3/4 full FIFO
	DMA_STREAM_FCR_FTH_FULL			 = DMA_STREAM_FCR_FTH, //!< Full FIFO

	// Direct mode disable
	DMA_STREAM_FCR_DMDIS_ENABLE  = 0UL,					 //!< Direct mode is enabled
	DMA_STREAM_FCR_DMDIS_DISABLE = DMA_STREAM_FCR_DMDIS, //!< Direct mode is disabled

	// FIFO status
	DMA_STREAM_FCR_FS_QUARTER       = 0UL,	  //!< 0 < fifo_level < 1/4
	DMA_STREAM_FCR_FS_HALF	        = 0x8UL,	  //!< 1/4 < fifo_level < 1/2
	DMA_STREAM_FCR_FS_THREE_QUARTER = 0x10UL,  //!< 1/2 < fifo_level < 3/4
	DMA_STREAM_FCR_FS_LESS_FULL     = 0x18UL,  //!< 3/4 < fifo_level < full
	DMA_STREAM_FCR_FS_EMPTY         = 0x20UL,  //!< FIFO is empty
	DMA_STREAM_FCR_FS_FULL          = 0x28UL,  //!< FIFO is full

	// FIFO threshold selection
	DMA_STREAM_FCR_FEIE_DISABLE = 0UL,	//!< FIFO error intrrupt disabled
	DMA_STREAM_FCR_FEIE_ENABLE  = DMA_STREAM_FCR_FEIE //!< FIFO error interrupt enabled
}DMA_STREAM_FCR_VALUE_ENUM;

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
 * Set stream peripheral address
 */
void DMA_set_stream_peripheral_address(const DMA_ENUM dma,
									   const DMA_STREAM_ENUM stream,
									   const WORD_TYPE address);

/**
 * Set stream memory 0 address
 */
void DMA_set_stream_memory_0_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address);

/**
 * Set stream memory 1 address
 */
void DMA_set_stream_memory_1_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address);

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
