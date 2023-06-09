#include "dma.h"

Boolean DMA_get_interrupt_status(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_INTERRUPT_ENUM interrupt)
{
	// Decide if data for given stream in Low or High register
	BYTE_TYPE offset = __DMA_LISR_OFFSET;
	if ((stream == DMA_STREAM_4) ||
		(stream == DMA_STREAM_5) ||
		(stream == DMA_STREAM_6) ||
		(stream == DMA_STREAM_7))
	{
		offset = __DMA_HISR_OFFSET;
	}

    // Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + offset);

	// check bit value
	BYTE_TYPE stream_pos = __DMA_get_stream_interrupt_pos(stream);
	return ((((*register_ptr) >> stream_pos) & interrupt) != 0U) ? TRUE : FALSE;
}

void DMA_clear_interrupt_flag(const DMA_ENUM dma,
							  const DMA_STREAM_ENUM stream,
							  const DMA_STREAM_INTERRUPT_ENUM interrupt)
{
    // Decide if data for given stream in Low or High register
	BYTE_TYPE offset = __DMA_LIFCR_OFFSET;
	if ((stream == DMA_STREAM_4) ||
		(stream == DMA_STREAM_5) ||
		(stream == DMA_STREAM_6) ||
		(stream == DMA_STREAM_7))
	{
		offset = __DMA_HIFCR_OFFSET;
	}

	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + offset);

	// set bit value (set to 1 clears the flag in the interrupt status register)
	BYTE_TYPE stream_pos = __DMA_get_stream_interrupt_pos(stream);
	(*register_ptr) |= (interrupt << stream_pos);
}

void DMA_set_stream_configuration(const DMA_ENUM dma,
								  const DMA_STREAM_ENUM stream,
								  const DMA_STREAM_CR_FIELDS_ENUM cr_field,
								  const DMA_STREAM_CR_VALUE_ENUM cr_value)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_CR_OFFSET);

	// Clear and set the desired field
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(cr_field);
	tmp |= (cr_value & cr_field);
	(*register_ptr) = tmp;
}

DMA_STREAM_CR_VALUE_ENUM DMA_get_stream_configuration(const DMA_ENUM dma,
													  const DMA_STREAM_ENUM stream,
													  const DMA_STREAM_CR_FIELDS_ENUM cr_field)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_CR_OFFSET);

	// If bitfield value is zero, the return value will be equal to multiple enums
	// Be smart about which enum you compare the return value to.
	return (*register_ptr) & cr_field;
}

void DMA_set_stream_num_data_items(const DMA_ENUM dma,
								   const DMA_STREAM_ENUM stream,
								   const HALF_WORD_TYPE num_data)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_NDTR_OFFSET);

	(*register_ptr) = num_data;
}

HALF_WORD_TYPE DMA_get_stream_num_data_items(const DMA_ENUM dma,
										     const DMA_STREAM_ENUM stream)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_NDTR_OFFSET);

	return (HALF_WORD_TYPE)(*register_ptr);
}

void DMA_set_stream_peripheral_address(const DMA_ENUM dma,
									   const DMA_STREAM_ENUM stream,
									   const WORD_TYPE address)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_PAR_OFFSET);

	(*register_ptr) = address;
}

WORD_TYPE DMA_get_stream_peripheral_address(const DMA_ENUM dma,
											const DMA_STREAM_ENUM stream)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_PAR_OFFSET);

	return (WORD_TYPE)(*register_ptr);
}

void DMA_set_stream_memory_0_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_M0AR_OFFSET);

	(*register_ptr) = address;
}

WORD_TYPE DMA_get_stream_memory_0_address(const DMA_ENUM dma,
										  const DMA_STREAM_ENUM stream)
{
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_M0AR_OFFSET);

	return (WORD_TYPE)(*register_ptr);
}

void DMA_set_stream_memory_1_address(const DMA_ENUM dma,
									 const DMA_STREAM_ENUM stream,
									 const WORD_TYPE address)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_M1AR_OFFSET);

	(*register_ptr) = address;
}

WORD_TYPE DMA_get_stream_memory_1_address(const DMA_ENUM dma,
										  const DMA_STREAM_ENUM stream)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_M1AR_OFFSET);

	return (WORD_TYPE)(*register_ptr);
}

void DMA_set_stream_fifo_control(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_FCR_FIELDS_ENUM fcr_field,
								 const DMA_STREAM_FCR_VALUE_ENUM fcr_value)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_FCR_OFFSET);

	// Clear and set the desired field
	WORD_TYPE tmp = (*register_ptr);
	tmp &= ~(fcr_field);
	tmp |= (fcr_value & fcr_field);
	(*register_ptr) = tmp;
}

DMA_STREAM_FCR_VALUE_ENUM DMA_get_stream_fifo_status(const DMA_ENUM dma,
												     const DMA_STREAM_ENUM stream,
													 const DMA_STREAM_FCR_FIELDS_ENUM fcr_field)
{
	// Get the pointer to the register
	WORD_TYPE* register_ptr = (WORD_TYPE*)(dma + stream + __DMA_STREAM_FCR_OFFSET);

	// If bitfield value is zero, the return value will be equal to multiple enums
	// Be smart about which enum you compare the return value to.
	return (*register_ptr) & fcr_field;
}


/**
 * Helper functions
 */
BYTE_TYPE __DMA_get_stream_interrupt_pos(const DMA_STREAM_ENUM stream)
{
	BYTE_TYPE out = 0U;
	switch(stream)
	{
	case(DMA_STREAM_0):
	case(DMA_STREAM_4):
		break;	// Leave out = 0U
	case(DMA_STREAM_1):
	case(DMA_STREAM_5):
		out = 6U;
		break;
	case(DMA_STREAM_2):
	case(DMA_STREAM_6):
		out = 16U;
		break;
	case(DMA_STREAM_3):
	case(DMA_STREAM_7):
		out = 22U;
	}

	return out;
}


