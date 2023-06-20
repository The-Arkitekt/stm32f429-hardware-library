#include "dma.h"

Boolean DMA_get_interrupt_status(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_INTERRUPT_ENUM interrupt)
{
    // Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_INTERRUPT_STATUS_OFFSETS[(((WORD_TYPE)stream >> 2U) & 1UL)]);

	return ((((*register_ptr) >> __DMA_STREAM_POSITIONS[((WORD_TYPE)stream & 3U)]) & (WORD_TYPE)interrupt) != 0U) ? TRUE : FALSE;
}

void DMA_clear_interrupt_flag(const DMA_ENUM dma,
							  const DMA_STREAM_ENUM stream,
							  const DMA_STREAM_INTERRUPT_ENUM interrupt)
{
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_INTERRUPT_STATUS_OFFSETS[(((WORD_TYPE)stream >> 2U) & 1UL)]);

	(*register_ptr) |= ((WORD_TYPE)interrupt << __DMA_STREAM_POSITIONS[((WORD_TYPE)stream & 3U)]);
}

void DMA_set_stream_configuration(const DMA_ENUM dma,
								  const DMA_STREAM_ENUM stream,
								  const DMA_STREAM_CR_FIELDS_ENUM cr_field,
								  const DMA_STREAM_CR_VALUE_ENUM cr_value)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_CR_OFFSET);

	// Clear and set the desired field
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~((WORD_TYPE)cr_field);
	tmp |= ((WORD_TYPE)cr_value & (WORD_TYPE)cr_field);
	(*register_ptr) = tmp;
}

DMA_STREAM_CR_VALUE_ENUM DMA_get_stream_configuration(const DMA_ENUM dma,
													  const DMA_STREAM_ENUM stream,
													  const DMA_STREAM_CR_FIELDS_ENUM cr_field)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream]+ __DMA_STREAM_CR_OFFSET);

	// If bitfield value is zero, the return value will be equal to multiple enums
	// Be smart about which enum you compare the return value to.
	return (*register_ptr) & cr_field;
}

void DMA_set_stream_num_data_items(const DMA_ENUM dma,
								   const DMA_STREAM_ENUM stream,
								   const HALF_WORD_TYPE num_data)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_NDTR_OFFSET);

	(*register_ptr) = num_data;
}

HALF_WORD_TYPE DMA_get_stream_num_data_items(const DMA_ENUM dma,
										     const DMA_STREAM_ENUM stream)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_NDTR_OFFSET);

	return (HALF_WORD_TYPE)(*register_ptr);
}

void DMA_set_stream_peripheral_address(const DMA_ENUM dma,
									   const DMA_STREAM_ENUM stream,
									   const WORD_TYPE address)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_PAR_OFFSET);

	(*register_ptr) = address;
}

void DMA_set_stream_memory_0_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_M0AR_OFFSET);

	(*register_ptr) = address;
}

void DMA_set_stream_memory_1_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_M1AR_OFFSET);

	(*register_ptr) = address;
}

void DMA_set_stream_fifo_control(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_FCR_FIELDS_ENUM fcr_field,
								 const DMA_STREAM_FCR_VALUE_ENUM fcr_value)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_FCR_OFFSET);

	// Clear and set the desired field
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~((WORD_TYPE)fcr_field);
	tmp |= ((WORD_TYPE)fcr_value & (WORD_TYPE)fcr_field);
	(*register_ptr) = tmp;
}

DMA_STREAM_FCR_VALUE_ENUM DMA_get_stream_fifo_status(const DMA_ENUM dma,
												     const DMA_STREAM_ENUM stream,
													 const DMA_STREAM_FCR_FIELDS_ENUM fcr_field)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)((WORD_TYPE)dma + __DMA_STREAM_OFFSETS[(WORD_TYPE)stream] + __DMA_STREAM_FCR_OFFSET);

	// If bitfield value is zero, the return value will be equal to multiple enums
	// Be smart about which enum you compare the return value to.
	return (*register_ptr) & (WORD_TYPE)fcr_field;
}


