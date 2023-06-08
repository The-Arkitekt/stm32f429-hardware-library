#include "dma.h"

Boolean DMA_get_interrupt_status(const DMA_ENUM dma,
								 const DMA_STREAM_ENUM stream,
								 const DMA_STREAM_INTERRUPT_ENUM interrupt)
{
    BYTE_TYPE reg_offset, stream_pos = 0U;
    if (stream < __NUM_STREAMS_PER_INTERRUPT_REG)
    {
        reg_offset = __DMA_LISR_OFFSET;
        stream_pos = __DMA_STREAM_INTERRUPT_POS[stream];
    }
    else
    {
        reg_offset = __DMA_HISR_OFFSET;
        stream_pos = __DMA_STREAM_INTERRUPT_POS[stream - __NUM_DMA_STREAMS_PER_INTERRUPT_REG]
    }

    // get pointer to DMA stream interrupt register
    WORD_TYPE* register = (WORD_TYPE*)(__DMA_ADDR[dma] + reg_offset);

    BYTE_TYPE interrupt_mask = __DMA_STREAM_INTERRUPT_BIT[DMA_STREAM_INTERRUPT_ENUM];
    return ((((*register) >> stream_pos) & interrupt_mask) != 0) ? TRUE : FALSE;
}

void DMA_clear_interrupt_flag(const DMA_ENUM dma,
							  const DMA_STREAM_ENUM stream,
							  const DMA_STREAM_INTERRUPT_ENUM interrupt)
{
    BYTE_TYPE reg_offset, stream_pos = 0U;
    if (stream < __NUM_STREAMS_PER_INTERRUPT_REG)
    {
        reg_offset = __DMA_LIFCR_OFFSET;
        stream_pos = __DMA_STREAM_INTERRUPT_POS[stream];
    }
    else
    {
        reg_offset = __DMA_HIFCR_OFFSET;
        stream_pos = __DMA_STREAM_INTERRUPT_POS[stream - __NUM_DMA_STREAMS_PER_INTERRUPT_REG];
    }

    // get pointer to DMA stream interrupt register
    WORD_TYPE* register = (WORD_TYPE*)(__DMA_ADDR[dma] + reg_offset);

    BYTE_TYPE interrupt_mask = __DMA_STREAM_INTERRUPT_BIT[DMA_STREAM_INTERRUPT_ENUM] << stream_pos;
    (*register) |= interrupt_mask;
}