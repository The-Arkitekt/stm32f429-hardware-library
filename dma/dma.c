#include "dma.h"

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
