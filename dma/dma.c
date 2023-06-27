#include "dma.h"

dma_return_value_enum dma_set_stream_control(const dma_enum dma, const dma_stream_enum stream, const dma_stream_interface_t* const p_stream_control_struct)
{
	dma_return_value_enum return_val = DMA_RETURN_SUCCESS;
	dma_stream_reg_t volatile * const p_stream_reg = p_dma_stream[(uint8_t)dma][(uint8_t)stream];
	uint32_t volatile tmp_reg = 0U;

	// Error Checking
	if((0U == p_stream_control_struct) || (0U != ((p_stream_reg->config) & DMA_STREAM_CR_EN_MSK)))
	{
		return_val = DMA_RETURN_FAIL;
	}
	else
	{
		// Set Peripheral Port Register Address
		p_stream_reg->peripheral_addr = p_stream_control_struct->peripheral_addr;

		// Set Mem0 Address
		p_stream_reg->mem0_addr = p_stream_control_struct->mem0_addr;

		// Set Mem1 Address
		p_stream_reg->mem1_addr = p_stream_control_struct->mem1_addr;

		// Set Number of data items to transfer
		p_stream_reg->num_data = p_stream_control_struct->num_data_items;

		// Get copy of config register
		tmp_reg = p_stream_reg->config;

		// Select DMA channel
		tmp_reg &= ~(DMA_STREAM_CR_CHSEL_MSK);
		tmp_reg |= DMA_STREAM_CR_CHSEL[(uint8_t)(p_stream_control_struct->channel)];

		// Set Peripheral Flow Control
		tmp_reg &= ~(DMA_STREAM_CR_PFCTRL_MSK);
		tmp_reg |= DMA_STREAM_CR_PFCTRL[(uint8_t)(p_stream_control_struct->flow_control)];

		// Set Stream Priority
		tmp_reg &= ~(DMA_STREAM_CR_PL_MSK);
		tmp_reg |= DMA_STREAM_CR_PL[(uint8_t)(p_stream_control_struct->priority_level)];

		// Set Data Transfer Direction
		tmp_reg &= ~(DMA_STREAM_CR_DIR_MSK);
		tmp_reg |= DMA_STREAM_CR_DIR[(uint8_t)(p_stream_control_struct->data_transfer_direction)];

		// Set Peripheral Increment Mode
		tmp_reg &= ~(DMA_STREAM_CR_PINC_MSK);
		tmp_reg |= DMA_STREAM_CR_PINC[(uint8_t)(p_stream_control_struct->peripheral_increment_mode)];

		// Set Peripheral Burst
		tmp_reg &= ~(DMA_STREAM_CR_PBURST_MSK);
		tmp_reg |= DMA_STREAM_CR_PBURST[(uint8_t)(p_stream_control_struct->peripheral_burst)];

		// Set Peripheral Data Size
		tmp_reg &= ~(DMA_STREAM_CR_PSIZE_MSK);
		tmp_reg |= DMA_STREAM_CR_PSIZE[(uint8_t)(p_stream_control_struct->peripheral_data_size)];

		// Set Memory Increment Mode
		tmp_reg &= ~(DMA_STREAM_CR_MINC_MSK);
		tmp_reg |= DMA_STREAM_CR_MINC[(uint8_t)(p_stream_control_struct->memory_increment)];

		// Set Memory Burst
		tmp_reg &= ~(DMA_STREAM_CR_MBURST_MSK);
		tmp_reg |= DMA_STREAM_CR_MBURST[(uint8_t)(p_stream_control_struct->memory_burst)];

		// Set Memory Data Size
		tmp_reg &= ~(DMA_STREAM_CR_MSIZE_MSK);
		tmp_reg |= DMA_STREAM_CR_MSIZE[(uint8_t)(p_stream_control_struct->memory_data_size)];

		// Set Buffer Mode
		tmp_reg &= ~(DMA_STREAM_CR_DBM_MSK);
		tmp_reg |= DMA_STREAM_CR_DBM[(uint8_t)(p_stream_control_struct->buffer_mode)];

		// Set Circular Mode
		tmp_reg &= ~(DMA_STREAM_CR_CIRC_MSK);
		tmp_reg |= DMA_STREAM_CR_CIRC[(uint8_t)(p_stream_control_struct->circular_mode)];

		// Set Transfer Complete Interrupt
		tmp_reg &= ~(DMA_STREAM_CR_TCIE_MSK);
		tmp_reg |= DMA_STREAM_CR_TCIE[(uint8_t)(p_stream_control_struct->transfer_complete_interrupt)];

		// Set Half Transfer Interrupt
		tmp_reg &= ~(DMA_STREAM_CR_HTIE_MSK);
		tmp_reg |= DMA_STREAM_CR_HTIE[(uint8_t)(p_stream_control_struct->half_transfer_interrupt)];

		// Set Transfer Error Interrupt
		tmp_reg &= ~(DMA_STREAM_CR_TEIE_MSK);
		tmp_reg |= DMA_STREAM_CR_TEIE[(uint8_t)(p_stream_control_struct->transfer_error_interrupt)];

		// Set Direct Mode Error Interrupt
		tmp_reg &= ~(DMA_STREAM_CR_DMEIE_MSK);
		tmp_reg |= DMA_STREAM_CR_DMEIE[(uint8_t)(p_stream_control_struct->direct_mode_error_interrupt)];

		// Set values in register
		p_stream_reg->config = tmp_reg;

		// Get copy of FIFO control register
		tmp_reg = p_stream_reg->fifo_control;

		// Set FIFO Direct Mode
		tmp_reg &= ~(DMA_STREAM_FCR_DMDIS_MSK);
		tmp_reg |= DMA_STREAM_FCR_DMDIS[(uint8_t)(p_stream_control_struct->fifo_direct_mode)];

		// Set FIFO Threshold
		tmp_reg &= ~(DMA_STREAM_FCR_FTH_MSK);
		tmp_reg |= DMA_STREAM_FCR_FTH[(uit8_t)(p_stream_control_struct->fifo_threshold)];

		// Set FIFO Error Interrupt
		tmp_reg &= ~(DMA_STREAM_FCR_FEIE_MSK);
		tmp_reg |= DMA_STREAM_FCR_FEIE[(uint8_t)(p_stream_control_struct->fifo_error_interrupt)];

		// Set values in register
		p_stream_reg->fifo_control = tmp_reg;
	}

	return return_val;
}
