#ifndef DMA_H
#define DMA_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "stm32f429xx.h"
#include "boolean.h"
#include "register.h"

/**
 * DMA Select enum
*/
typedef enum DmaSelect{
	DMA1_SELECT = 0U,
	DMA2_SELECT
}DmaSelect;

/**
 * DMA Stream Select enum
 * 	Enum maps to the address in memory of the stream registers
*/
typedef enum DmaStreamSelect{
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
 * valid DMA_SxCR bitfield value options
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
 * 	DMEIE:
 * 		0: Direct Mode Error Interrupt disabled
 * 		1: Direct Mode Error Interrupt enabled
 * 	EN:
 * 		0: Stream disabled
 * 		1: Strean enabled
 */

/**
 *  DMA_SxCR bitfield selection enum 	
 */
typedef enum DmaStreamControlFieldSelect{ //TODO: add comments for each field
	DMA_STREAM_CONTROL_CHSEL_FIELD = 0U,
	DMA_STREAM_CONTROL_MBURST_FIELD,
	DMA_STREAM_CONTROL_PBURST_FIELD,
	DMA_STREAM_CONTROL_CT_FIELD,
	DMA_STREAM_CONTROL_DBM_FIELD,
	DMA_STREAM_CONTROL_PL_FIELD,
	DMA_STREAM_CONTROL_PINCOS_FIELD,
	DMA_STREAM_CONTROL_MSIZE_FIELD,	
	DMA_STREAM_CONTROL_PSIZE_FIELD,
	DMA_STREAM_CONTROL_MINC_FIELD,	 
	DMA_STREAM_CONTROL_PINC_FIELD,
	DMA_STREAM_CONTROL_CIRC_FIELD,
	DMA_STREAM_CONTROL_DIR_FIELD,
	DMA_STREAM_CONTROL_PFCTRL_FIELD,
	DMA_STREAM_CONTROL_TCIE_FIELD,
	DMA_STREAM_CONTROL_HTIE_FIELD,
	DMA_STREAM_CONTROL_TEIE_FIELD,
	DMA_STREAM_CONTROL_DMEIE_FIELD,
	DMA_STREAM_CONTROL_EN_FIELD
}DmaStreamControlFieldSelect;

/**
 * The number of bitfields in the DMA_SxCR register
*/
#ifndef NUM_DMA_STREAM_CONTROL_FIELDS
	#define NUM_DMA_STREAM_CONTROL_FIELDS 19
#endif

/**
 * Array of the bitfield positions in DMA_SxCR register
*/
static const BYTE_TYPE DMA_STREAM_CONTROL_FIELD_POS[NUM_DMA_STREAM_CONTROL_FIELDS] = {
	DMA_SxCR_CHSEL_Pos, DMA_SxCR_MBURST_Pos,
	DMA_SxCR_PBURST_Pos, DMA_SxCR_CT_Pos,
	DMA_SxCR_DBM_Pos, DMA_SxCR_PL_Pos,
	DMA_SxCR_PINCOS_Pos, DMA_SxCR_MSIZE_Pos,
	DMA_SxCR_PSIZE_Pos, DMA_SxCR_MINC_Pos,
	DMA_SxCR_PINC_Pos, DMA_SxCR_CIRC_Pos,
	DMA_SxCR_DIR_Pos, DMA_SxCR_PFCTRL_Pos,
	DMA_SxCR_TCIE_Pos, DMA_SxCR_HTIE_Pos,
	DMA_SxCR_TEIE_Pos, DMA_SxCR_DMEIE_Pos,
	DMA_SxCR_EN_Pos
};

/**
 * Array of max values for each bit field
 * min is always zero
*/
static const DMA_STREAM_CONTROL_FIELD_MAX[NUM_DMA_STREAM_CONTROL_FIELDS] = {
	7U, 3U, 3U, 1U, 1U, 3U, 1U, 3U, 3U, 1U,
	1U, 1U, 3U, 1U, 1U, 1U, 1U, 1U, 1U
};

/**
 * DMA Stream Interrupt Types Select enum
*/
typedef enum DmaStreamInterruptTypeSelect{	// TODO: comments explaining the fields
	DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT = 0U,
	DMA_STREAM_INTERRUPT_RESERVED,
	DMA_STREAM_HALF_TRANSFER_INTERRUPT,
	DMA_STREAM_TRANSFER_ERROR_INTERRUPT,
	DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT,
	DMA_STREAM_FIFO_ERROR_INTERRUPT
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
static const BYTE_TYPE DMA_INTERRUPT_REG_STREAM_POS[NUM_DMA_STREAMS_PER_INT_REG] = {
	0U, 6U, 16U, 22U
}

//TODO: Comment block explaining field values

/**
 * DMA Stream FIFO COntrol field selection enum
*/
typedef enum DmaStreamFifoControlFieldSelect{ //TODO: comments explaining the fields
	DMA_STREAM_FIFO_CTRL_FEIE_FIELD,
	DMA_STREAM_FIFO_CTRL_STATUS_FIELD,
	DMA_STREAM_FIFO_CTRL_DMDIS_FIELD,
	DMA_STREAM_FIFO_CTRL_FTH_FIELD
}DmaStreamFifoControlFieldSelect;

/**
 * The number of bitfields in the DMA_SxFCR register
*/
#ifndef NUM_DMA_STREAM_FIFO_CONTROL_FIELDS
	#define NUM_DMA_STREAM_FIFO_CONTROL_FIELDS 4U
#endif //NUM_DMA_STREAM_FIFO_CONTROL_FIELDS

/**
 * Array used to find position if bitfield in DMA_SxCR_FCTRL register
*/
static const BYTE_TYPE DMA_STREAM_FIFO_CONTROL_FIELD_POS[NUM_DMA_STREAM_FIFO_CONTROL_FIELDS] = {
	DMA_SxFCR_FEIE_Pos, DMA_SxFCR_FS_Pos, DMA_SxFCR_DMDIS_Pos, DMA_SxFCR_FTH_Pos
}

/**
 *  Array of max values for each FIFO COntrol field
*/
static const BYTE_TYPE DMA_STREAM_FIFO_CONTROL_FIELD_MAX[NUM_DMA_STREAM_FIFO_CONTROL_FIELDS] = {
	1U, 7U, 1U, 3U
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
 * @param out The value of the selected field
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
 * @param out True if the flag is set, false otherwise
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
 * @param out The value from the register
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
 * @param out The memory address
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
 * @param out The memory address
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
 * @param out The value from the field in the register
 * @return True if successful, false otherwise
*/
Boolean readDmaStreamFifoControl(const DMA_Stream_TypeDef* const streamPtr, 
								 const setDmaStreamFifoControlFieldSelect field, BYTE_TYPE* const out);

//@{
/**
 * Enable the DMA1 peripheral in the RCC register
*/
void dma1Enable();
void dma2Enable();
//@}

//@{
/** 
 * Disable the DMA2 peripheral in the RCC register
*/
void dma1Disable();
void dma2Disable();
//@}

#ifdef __cplusplus
}
#endif

#endif //DMA_H
