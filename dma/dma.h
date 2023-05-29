#ifndef DMA_H
#define DMA_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "boolean.h"
#include "register.h"

/**
 * DMA Selection
*/
typedef enum DmaSelect
{
	DMA1_SELECT = 0U,
	DMA2_SELECT
}DmaSelect;

/**
 * DMA Stream Selection
*/
typedef enum DmaStreamSelect
{
	DMA_STREAMSELECT_0 = 0U,
	DMA_STREAMSELECT_1,
	DMA_STREAMSELECT_2,
	DMA_STREAMSELECT_3,
	DMA_STREAMSELECT_4,
	DMA_STREAMSELECT_5,
	DMA_STREAMSELECT_6,
	DMA_STREAMSELECT_7,
}DmaStreamSelect;

/**
 * valid DMA_SxCR bitfield values
 * 
 *  CHSEL:  Values correspond to desired channel [0-7]
 * 	MBURST: 
 * 		0: Single transfer
 * 		1: Incremental burst of 4 beats
 * 		2: Incremental burst of 8 beats
 * 		3: Incremental burst of 16 beats
 * 	PBURST: 
 * 		0: Single transfer
 * 		1: Incremental burst of 4 beats
 * 		2: Incremental burst of 8 beats
 * 		3: Incremental burst of 16 beats
 * 	CT:
 * 		0: Target is Memory 0
 * 		1: Target is Memory 1
 * 	DBM:
 * 		0: No buffer switching at the end of transfer
 * 		1: Memory target switched at the end of DMA transfer
 * 	PL:
 * 		0: Low
 * 		1: Medium
 * 		2: High
 * 		3: Very high
 * 	PINCOS:
 * 		0: Offset size for peripheral address location is linked to PSIZE
 * 		1: Offset size for peripheral address location is fixed at 4
 * 	MSIZE:
 * 		0: Byte (8-bit)
 * 		1: Half-word (16-bit)
 * 		2: Word (32-bit)
 * 		3: reserved (no effect)
 * 	PSIZE:
 * 		0: Byte (8-bit)
 * 		1: Half-word (16-bit)
 * 		2: Word (32-bit)
 * 		3: reserved (no effect)
 * 	MINC:
 * 		0: Memory address pointer is fixed
 * 		1: Memory address pointer is incremented according to MSIZE after each transfer
 * 	PINC:
 * 		0: Peripheral address pointer is fixed
 * 		1: Peripheral address pointer is incremented according to PSIZE after each transfer
 * 	CIRC:
 * 		0: Circular mode disabled (Automatically set when PFCTRL = 1 and EN = 1)
 * 		1: Circular mode enabled (Automatically set when DBM = 1 and when EN is first set to 1)
 * 	DIR:
 * 		0: Peripheral-to-memory
 * 		1: Memory-to-peripheral
 * 		2: Memory-to-memory
 * 		3: reserved (no effect)
 * 	PFCTRL:
 * 		0: The DMA is the flow controller (Automatically set when DIR = 2)
 * 		1: The peripheral is the flow controller
 * 	TCIE:
 * 		0: Transfer Complete Interrupt disabled
 * 		1: Transfer Complete Interrupt enabled
 * 	HTIE:
 * 		0: Half Transfer Interrupt disabled
 * 		1: Half Transfer Interrupt enabled
 * 	TEIE:
 * 		0: Transfer Error Interrupt disabled
 * 		1: Transfer Error Interrupt enabled
 * 	DMEIE:
 * 		0: Direct Mode Error Interrupt disabled
 * 		1: Direct Mode Error Interrupt enabled
 * 	EN:
 * 		0: Stream disabled
 * 		1: Stream enabled
 */

/**
 *  DMA Stream Control (DMA_SxCR) bitfield selection  	
 */
typedef enum DmaStreamControlFieldSelect
{
	DMA_STREAM_CONTROL_CHSEL_FIELD = 0U, //!< Channel selection
	DMA_STREAM_CONTROL_MBURST_FIELD,	 //!< Memory burst transfer configuration
	DMA_STREAM_CONTROL_PBURST_FIELD,	 //!< Peripheral burst transfer configuration
	DMA_STREAM_CONTROL_CT_FIELD,		 //!< Current target (only in double buffer mode)
	DMA_STREAM_CONTROL_DBM_FIELD,		 //!< Double buffer mode
	DMA_STREAM_CONTROL_PL_FIELD,		 //!< Priority level
	DMA_STREAM_CONTROL_PINCOS_FIELD,	 //!< Peripheral increment offset size
	DMA_STREAM_CONTROL_MSIZE_FIELD,		 //!< Memory data size
	DMA_STREAM_CONTROL_PSIZE_FIELD,	     //!< Peripheral data size
	DMA_STREAM_CONTROL_MINC_FIELD,	 	 //!< Memory increment mode 
	DMA_STREAM_CONTROL_PINC_FIELD,		 //!< Peripheral increment mode
	DMA_STREAM_CONTROL_CIRC_FIELD,		 //!< Circular mode
	DMA_STREAM_CONTROL_DIR_FIELD,		 //!< Data transfer direction
	DMA_STREAM_CONTROL_PFCTRL_FIELD,	 //!< Peripheral flow controller
	DMA_STREAM_CONTROL_TCIE_FIELD,	     //!< Transfer complete interrupt enable
	DMA_STREAM_CONTROL_HTIE_FIELD,       //!< Half transfer interrupt enable
	DMA_STREAM_CONTROL_TEIE_FIELD,	     //!< Transfer error interrupt enable
	DMA_STREAM_CONTROL_DMEIE_FIELD,	     //!< Direct mode error interrupt enable
	DMA_STREAM_CONTROL_EN_FIELD			 //!< Stream enable / flag stream ready when read low
}DmaStreamControlFieldSelect;

/**
 * The number of bitfields in the DMA Stream Control (DMA_SxCR) register
*/
#ifndef NUM_DMA_STREAM_CONTROL_FIELDS
	#define NUM_DMA_STREAM_CONTROL_FIELDS 19
#endif

/**
 * Array of bitfield details in DMA Stream Control (DMA_SxCR) register
*/
static const BitFieldDetails DMA_STREAM_CONTROL_FIELD_DETAILS[NUM_DMA_STREAM_CONTROL_FIELDS] = 
{
	{DMA_SxCR_CHSEL_Pos, THREE_BIT_MASK, THREE_BIT_MASK},	//!< Channel selection field details
	{DMA_SxCR_MBURST_Pos, TWO_BIT_MASK, TWO_BIT_MASK},		//!< Memory Burst field details
	{DMA_SxCR_PBURST_Pos, TWO_BIT_MASK, TWO_BIT_MASK},		//!< Peripheral Burst field details
	{DMA_SxCR_CT_Pos, ONE_BIT_MASK, ONE_BIT_MASK}, 			//!< Current Target field details
	{DMA_SxCR_DBM_Pos, ONE_BIT_MASK, ONE_BIT_MSK},			//!< Double Buffer Mode field details
	{DMA_SxCR_PL_Pos, TWO_BIT_MASK, TWO_BIT_MASK},			//!< Priority Level field details
	{DMA_SxCR_PINCOS_Pos, ONE_BIT_MSK, ONE_BIT_MSK},		//!< Peripheral Offset Size field details
	{DMA_SxCR_MSIZE_Pos, 2U, TWO_BIT_MASK}, 				//!< Memory Size field details
	{DMA_SxCR_PSIZE_Pos, 2U, TWO_BIT_MASK},					//!< Peripheral Size field details
	{DMA_SxCR_MINC_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Memory Increment field details
	{DMA_SxCR_PINC_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Peripheral Increment field details
	{DMA_SxCR_CIRC_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Circular Buffer field details
	{DMA_SxCR_DIR_Pos, 2U, TWO_BIT_MASK},					//!< Data Transfer Direction field details
	{DMA_SxCR_PFCTRL_Pos, 2U, TWO_BIT_MASK},				//!< Flow Control field details
	{DMA_SxCR_TCIE_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Transfer Complete Interrupt field details
	{DMA_SxCR_HTIE_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Half Transfer Interrupt field details
	{DMA_SxCR_TEIE_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Transfer Error Interrupt field details
	{DMA_SxCR_DMEIE_Pos, ONE_BIT_MASK, ONE_BIT_MASK},		//!< Direct Mode Error Interrupt field details
	{DMA_SxCR_EN_Pos, ONE_BIT_MASK, ONE_BIT_MASK}			//!< Stream Enable field details
}

/**
 * DMA Stream Interrupt Types Select 
*/
typedef enum DmaStreamInterruptTypeSelect
{	
	DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT = 0U,	//!<  Stream transfer complete interrupt		    
	DMA_STREAM_HALF_TRANSFER_INTERRUPT,			    //!< Stream half transfer interrupt
	DMA_STREAM_TRANSFER_ERROR_INTERRUPT,			//!< Stream transfer error interrupt
	DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT,			//!< Stream direct mode error interrupt
	DMA_STREAM_RESERVED,							//!< Reserved Bit (Read-Only)
	DMA_STREAM_FIFO_ERROR_INTERRUPT					//!< Stream FIFO error interrupt
}DmaStreamInterruptTypeSelect;

/**
 * The number of streams per interrupt register
*/
#ifndef NUM_DMA_STREAMS_PER_INT_REG
	#define NUM_DMA_STREAMS_PER_INT_REG 4U
#endif //DMA_STREAMS_PER_INT_REG

/**
 * Array used to find position of specific stream bits in interrupt registers
 * For streams > 3, subtract 4 from stream number to get element in this array
*/
static const BYTE_TYPE DMA_INTERRUPT_REG_STREAM_POS[NUM_DMA_STREAMS_PER_INT_REG] = 
{
	0U, 6U, 16U, 22U
}

/**
 * Valid DMA_SxFCR bitfield values
 * 
 * 	FEIE:
 * 		0: FE interrupt disabled
 * 		1: FE interrupt enabled
 * 	FS:
 * 		0: 0 < fifo_level < 1/4 
 * 		1: 1/4 ≤ fifo_level < 1/2 
 * 		2: 1/2 ≤ fifo_level < 3/4
 * 		3: 3/4 ≤ fifo_level < full
 * 		4: FIFO is empty
 * 		5: FIFO is full
 * 		6-7: no meaning or effect
 * 	DMDIS:
 * 		0: Direct mode enabled
 * 		1: Direct mode disabled
 * 	FTH:
 * 		0: 1/4 full FIFO
 * 		1: 1/2 full FIFO
 * 		2: 3/4 full FIFO
 * 		3: full FIFO
*/

/**
 * DMA Stream FIFO COntrol field selection enum
*/
typedef enum DmaStreamFifoControlFieldSelect
{
	DMA_STREAM_FIFO_CTRL_FEIE_FIELD,	//!< FIFO error interrupt enable
	DMA_STREAM_FIFO_CTRL_STATUS_FIELD,	//!< FIFO status (Read-only)
	DMA_STREAM_FIFO_CTRL_DMDIS_FIELD,	//!< Direct mode disable
	DMA_STREAM_FIFO_CTRL_FTH_FIELD		//!< FIFO threshold selection
}DmaStreamFifoControlFieldSelect;

/**
 * The number of bitfields in the DMA_SxFCR register
*/
#ifndef NUM_DMA_STREAM_FIFO_CONTROL_FIELDS
	#define NUM_DMA_STREAM_FIFO_CONTROL_FIELDS 4U
#endif //NUM_DMA_STREAM_FIFO_CONTROL_FIELDS

/**
 * Array of bitfield details for Stream Fifo Control (DMA_SxFCR) register
*/
static const BitFieldDetails DMA_STREAM_FIFO_CONTROL_FIELD_DETAILS[NUM_DMA_STREAM_FIFO_CONTROL_FIELDS] = 
{
	{DMA_SxFCR_FEIE_Pos, ONE_BIT_MASK, ONE_BIT_MASK},	//!< FIFO Error Interrupt Enable field details
	{DMA_SxFCR_FS_Pos, 5U, THREE_BIT_MASK},				//!< FIFO Status field details
	{DMA_SxFCR_DMDIS_Pos, ONE_BIT_MASK, ONE_BIT_MASK},	//!< Direct Mode Disable field details
	{DMA_SxFCR_FTH_Pos, TWO_BIT_MASK, TWO_BIT_MASK},	//!< FIFO Threshold Selection field details
}

/**
 * Return DMA type for given Dma Selection
 * @param dma The Dma Select enum value
 * @return A DMA_TypeDef pointer
*/
DMA_TypeDef* getDma(const DmaSelect dma);

/**
 * Return DMA Stream type for given Stream Selection
 * @param dma The Dma Select enum value 
 * @param stream The Dma Stream Select enum value
 * @return  A DMA_Stream_TypeDef pointer 
*/
DMA_Stream_TypeDef* getDmaStream(const DmaSelect dma, const DmaStreamSelect dmaStream);

/**
 * Set a bitfield value in the DMA_SxCR register
 * @param streamPtr The DMA_STREAM_Typedef pointer containing the register
 * @param field The Bitfield select enum for the desired bitfield
 * @param value Desired value to be set at the given bitfield
*/
void setDmaStreamControl(DMA_Stream_TypeDef* const streamPtr, 
						 const DmaStreamControlFieldSelect field, 
						 BYTE_TYPE value);

/**
 * read a bitfield value in the DMA_SxCR register
 * @param streamPtr The DMA_Stream_Typedef pointer containing the register
 * @param field The bitfield select enum for the desired bitfield
 * @param[out] out The value of the selected field
 * @return True if successful, false otherwise
*/
Boolean readDmaStreamControl(const DMA_Stream_TypeDef* const streamPtr,
							 const DmaStreamConfigFieldSelect field, BYTE_TYPE* const out);

/**
 * Clear stream interrupt flag
 * @param dmaPtr The DMA_Typedef pointer containing the interrupt flag to clear
 * @param stream The Dma Stream Select enum value
 * @param interruptType The Dma Stream Interrupt flag type to clear
*/
void clearDmaInterruptFlag(DMA_TypeDef* const dmaPtr, const DmaStreamSelect stream,
                           const DmaStreamInterruptTypeSelect interruptType);

/**
 * read stream interrupt flag value
 * @param dmaPtr The DMA_Typedef pointer containing the interrupt flag values
 * @param stream The Dma Stream Select enum value
 * @param interruptType The Dma Stream Interrupt flag type to check
 * @param[out] out True if the flag is set, false otherwise
 * @return TRUE if successful, false otherwise
*/
Boolean readDmaInterruptFlag(const DMA_TypeDef* const dmaPtr, const DmaStreamSelect stream,
								 const DmaStreamInterruptTypeSelect interruptType, Boolean* const out);

/**
 * Set Number of data items to be transferred
 * 	(EN must be low)
 * @param streamPtr DMA_STREAM_Typedef pointer containing the register
 * @param numDataItems The number of data items to be transfered
*/
void setDmaNumberItemsToTransfer(DMA_Stream_TypeDef* const streamPtr, const HALF_WORD numDataItems);

/**
 * Read number of remaining data items to be transferred
 * @param streamPtr DMA_Stream_Typedef pointer containing the register to read 
 * @param[out] out The value from the register
 * @return True if successful, false otherwise
*/
Boolean readDmaNumberItemsToTransfer(const DMA_Stream_TypeDef* const streamPtr, HALF_WORD* const out);

/**
 * Set the stream peripheral address data will be transferred from/to
 *  (EN must be low)
 * @param streamPtr DMA_Stream_Typedef pointer containing the register to set
 * @param address The peripheral address to set in the register
*/
void setDmaPeripheralAddress(DMA_Stream_TypeDef* const streamPtr, const WORD_TYPE address);

/**
 * read the stream peripheral address which data will be transfered from/to
 * @param streamPtr DMA_Stream_Typedef pointer containing the register
 * @return The peripheral address
*/
WORD_TYPE readDmaPeripheralAddress(const DMA_Stream_TypeDef* const streamPtr);

/**
 * Set base address of memory area 0 which data will be transfered to/from
 * 	(EN must be low OR EN can be high if CT bit is high and double buffer mode is enabled)
 * @param streamPtr DMA_Stream_Typedef pointer containing the register
 * @param address The memory address to set in the register
*/
void setDmaMemory0Address(DMA_Stream_TypeDef* const streamPtr, const WORD_TYPE address);

/**
 * read the base address of memory area 0 which data will be transfered to/from
 * @param streamPtr DMA_Stream_Typedef pointer containing the register
 * @param[out] out The memory address
 * @return True if successful, false otherwise
*/
Boolean readDmaMemory0Address(const DMA_Stream_TypeDef* const streamPtr, WORD_TYPE* const out);

/**
 * set base address of memory area 1 which data will be transfered to/from
 * 	(Used in double buffer mode)
 * 	(EN must be low OR EN can be high if CT bit is low and double buffer mode is enabled)
 * @param streamPtr DMA_Stream_Typedef pointer containing the register
 * @param address The memory address to set in the register
*/
void setDmaMemory1Address(DMA_Stream_TypeDef* const streamPtr, const WORD_TYPE address);

/**
 * read base address of memory area 1 which data will be transferred to/from
 * @param streamPtr DMA_Stream_Typedef pointer containing the register
 * @param[out] out The memory address
 * @return True if successful, false otherwise
*/
Boolean readDmaMemory1Address(const DMA_Stream_TypeDef* const streamPtr, WORD_TYPE* const out);

/**
 * set bitfield value in the DMA_SxFCR register (FIFO Control)
 * 	(FIFO Status is READ-ONLY, so setting here has no effect)
 * @param streamPtr The DMA_Stream_Typedef pointer containing the register
 * @param field The Fifo Control field to be set
 * @param value The value to set in the field
*/
void setDmaStreamFifoControl(DMA_Stream_TypeDef* const streamPtr, const DmaStreamFifoControlFieldSelect field,
						     const BYTE_TYPE value);

/**
 * read bitfield value in the DMA_SxFCR register (FIFO Control)
 * @param streamPtr THe DMA_Stream_Typedef pointer containing the register
 * @param field The FIfo Control field to be set
 * @param[out] out The value from the field in the register
 * @return True if successful, false otherwise
*/
Boolean readDmaStreamFifoControl(const DMA_Stream_TypeDef* const streamPtr, 
								 const setDmaStreamFifoControlFieldSelect field, BYTE_TYPE* const out);

/**
 * Enable the DMA peripheral in the RCC register
 * @param dma The dma to enable (1 or 2)
*/
void dmaEnable(const DmaSelect dma);

/** 
 * Disable the DMA peripheral in the RCC register
 * @param dma The dma to disable (1 or 2)
*/
void dmaDisable(const DmaSelect dma);

#ifdef __cplusplus
}
#endif

#endif //DMA_H
