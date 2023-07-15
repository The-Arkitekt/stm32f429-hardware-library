#include "dma.h"

void dma_set_stream_enable(const dma_enum dma, const dma_stream_enum stream, const dma_stream_enable_enum value)
{
	uint32_t volatile tmp_reg = DMA_REG_PTRS[(uint8_t)dma]->stream[(uint8_t)stream].control;

	tmp_reg &= ~(DMA_STREAM_ENABLE_MSK);
	tmp_reg |= (uint32_t)value;

	DMA_REG_PTRS[(uint8_t)dma]->stream[(uint8_t)stream].control;
}

dma_stream_enable_enum dma_get_stream_enable_status(const dma_enum dma, const dma_stream_enum stream)
{
	return (dma_stream_enable_enum)((DMA_REG_PTRS[(uint8_t)dma]->stream[(uint8_t)stream].control) & DMA_STREAM_ENABLE_MSK);
}

bool dma_set_stream_config(const dma_enum dma, const dma_stream_enum stream, const dma_stream_config_interface_t* const p_stream_config_struct)
{
	bool success = false;

	// Error Checking
	if ((0U != p_stream_config_struct) && (DMA_STREAM_DISABLED != dma_get_stream_enable_status(dma, stream)))
	{
		dma_reg_t volatile * const p_dma_reg = DMA_REG_PTRS[(uint8_t)dma];
		uint32_t volatile tmp_reg            = 0U;

		// Set Peripheral Port Register Address
		p_dma_reg->stream[(uint8_t)stream].peripheral_addr = p_stream_config_struct->peripheral_addr;

		// Set Mem0 Address
		p_dma_reg->stream[(uint8_t)stream].mem0_addr = p_stream_config_struct->mem0_addr;

		// Set Mem1 Address
		p_dma_reg->stream[(uint8_t)stream].mem1_addr = p_stream_config_struct->mem1_addr;

		// Set Number of data items to transfer
		p_dma_reg->stream[(uint8_t)stream].num_data = p_stream_config_struct->num_data_items;

		// Get copy of config register
		tmp_reg = p_dma_reg->stream[(uint8_t)stream].control;

		// Select DMA channel
		tmp_reg &= ~(DMA_STREAM_CHANNEL_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->channel);

		// Set Peripheral Flow Control
		tmp_reg &= ~(DMA_STREAM_FLOW_CONTROL_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->flow_control);

		// Set Stream Priority
		tmp_reg &= ~(DMA_STREAM_PRIORITY_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->priority_level);

		// Set Data Transfer Direction
		tmp_reg &= ~(DMA_STREAM_DATA_TRANSFER_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->data_transfer_direction);

		// Set Peripheral Increment Mode
		tmp_reg &= ~(DMA_STREAM_PERIPHERAL_INCREMENT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->peripheral_increment_mode);

		// Set Peripheral Burst
		tmp_reg &= ~(DMA_STREAM_PERIPHERAL_BURST_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->peripheral_burst);

		// Set Peripheral Data Size
		tmp_reg &= ~(DMA_STREAM_PERIPHERAL_DATASIZE_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->peripheral_data_size);

		// Set Memory Increment Mode
		tmp_reg &= ~(DMA_STREAM_MEM_INCREMENT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->memory_increment);

		// Set Memory Burst
		tmp_reg &= ~(DMA_STREAM_MEM_BURST_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->memory_burst);

		// Set Memory Data Size
		tmp_reg &= ~(DMA_STREAM_MEM_DATASIZE_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->memory_data_size);

		// Set Buffer Mode
		tmp_reg &= ~(DMA_STREAM_BUFFER_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->buffer_mode);

		// Set Circular Mode
		tmp_reg &= ~(DMA_STREAM_CIRCULAR_MODE_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->circular_mode);

		// Set Transfer Complete Interrupt
		tmp_reg &= ~(DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->transfer_complete_interrupt);

		// Set Half Transfer Interrupt
		tmp_reg &= ~(DMA_STREAM_HALF_TRANSFER_INTERRUPT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->half_transfer_interrupt);

		// Set Transfer Error Interrupt
		tmp_reg &= ~(DMA_STREAM_TRANSFER_ERROR_INTERRUPT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->transfer_error_interrupt);

		// Set Direct Mode Error Interrupt
		tmp_reg &= ~(DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->direct_mode_error_interrupt);

		// Set values in register
		p_dma_reg->stream[(uint8_t)stream].control = tmp_reg;

		// Get copy of FIFO control register
		tmp_reg = p_dma_reg->stream[(uint8_t)stream].fifo_control;

		// Set FIFO Direct Mode
		tmp_reg &= ~(DMA_STREAM_FIFO_DIRECT_MODE_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->fifo_direct_mode);

		// Set FIFO Threshold
		tmp_reg &= ~(DMA_STREAM_FIFO_THRESHOLD_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->fifo_threshold);

		// Set FIFO Error Interrupt
		tmp_reg &= ~(DMA_STREAM_FIFO_ERROR_INTERRUPT_MSK);
		tmp_reg |= (uint32_t)(p_stream_config_struct->fifo_error_interrupt);

		// Set values in register
		p_dma_reg->stream[(uint8_t)stream].fifo_control = tmp_reg;

		success = true;
	}

	return success;
}

bool dma_get_stream_config(const dma_enum dma, const dma_stream_enum stream, dma_stream_config_interface_t* const p_stream_config_struct)
{
	bool success = false;

	// Error Checking
	if (0U != p_stream_config_struct)
	{
		dma_reg_t volatile * const p_dma_reg = DMA_REG_PTRS[(uint8_t)dma];
		uint32_t volatile tmp_reg            = 0U;

		// Set Peripheral Port Register Address
		p_stream_config_struct->peripheral_addr = p_dma_reg->stream[(uint8_t)stream].peripheral_addr;

		// Set Mem0 Address
		p_stream_config_struct->mem0_addr = p_dma_reg->stream[(uint8_t)stream].mem0_addr;

		// Set Mem1 Address
		p_stream_config_struct->mem1_addr = p_dma_reg->stream[(uint8_t)stream].mem1_addr;

		// Set Number of data items to transfer
		p_stream_config_struct->num_data_items = p_dma_reg->stream[(uint8_t)stream].num_data;

		// Get copy of config register
		tmp_reg = p_dma_reg->stream[(uint8_t)stream].control;

		// Select DMA channel
		p_stream_config_struct->channel = (dma_stream_channel_enum)(tmp_reg & DMA_STREAM_CHANNEL_MSK);

		// Set Peripheral Flow Control
		p_stream_config_struct->flow_control = (dma_stream_flow_control_enum)(tmp_reg & DMA_STREAM_FLOW_CONTROL_MSK);

		// Set Stream Priority
		p_stream_config_struct->priority_level = (dma_stream_priority_enum)(tmp_reg & DMA_STREAM_PRIORITY_MSK);

		// Set Data Transfer Direction
		p_stream_config_struct->data_transfer_direction = (dma_stream_data_transfer_direction_enum)(tmp_reg & DMA_STREAM_DATA_TRANSFER_MSK);

		// Set Peripheral Increment Mode
		p_stream_config_struct->peripheral_increment_mode = (dma_stream_peripheral_increment_enum)(tmp_reg & DMA_STREAM_PERIPHERAL_INCREMENT_MSK);

		// Set Peripheral Burst
		p_stream_config_struct->peripheral_burst = (dma_stream_peripheral_burst_enum)(tmp_reg & DMA_STREAM_PERIPHERAL_BURST_MSK);

		// Set Peripheral Data Size
		p_stream_config_struct->peripheral_data_size = (dma_stream_peripheral_data_size_enum)(tmp_reg & DMA_STREAM_PERIPHERAL_DATASIZE_MSK);

		// Set Memory Increment Mode
		p_stream_config_struct->memory_increment = (dma_stream_mem_increment_enum)(tmp_reg & DMA_STREAM_MEM_INCREMENT_MSK);

		// Set Memory Burst
		p_stream_config_struct->memory_burst = (dma_stream_mem_burst_enum)(tmp_reg & DMA_STREAM_MEM_BURST_MSK);

		// Set Memory Data Size
		p_stream_config_struct->memory_data_size = (dma_stream_mem_data_size_enum)(tmp_reg & DMA_STREAM_MEM_DATASIZE_MSK);

		// Set Buffer Mode
		p_stream_config_struct->buffer_mode = (dma_stream_buffer_mode_enum)(tmp_reg & DMA_STREAM_BUFFER_MSK);

		// Set Circular Mode
		p_stream_config_struct->circular_mode = (dma_stream_circular_mode_enum)(tmp_reg & DMA_STREAM_CIRCULAR_MODE_MSK);

		// Set Transfer Complete Interrupt
		p_stream_config_struct->transfer_complete_interrupt = (dma_stream_transfer_complete_interrupt_enum)(tmp_reg & DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT_MSK);

		// Set Half Transfer Interrupt
		p_stream_config_struct->half_transfer_interrupt = (dma_stream_half_transfer_interrupt_enum)(tmp_reg & DMA_STREAM_HALF_TRANSFER_INTERRUPT_MSK);

		// Set Transfer Error Interrupt
		p_stream_config_struct->transfer_error_interrupt = (dma_stream_transfer_error_interrupt_enum)(tmp_reg & DMA_STREAM_TRANSFER_ERROR_INTERRUPT_MSK);

		// Set Direct Mode Error Interrupt
		p_stream_config_struct->direct_mode_error_interrupt = (dma_stream_direct_mode_error_interrupt_enum)(tmp_reg & DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT_MSK);

		// Get copy of FIFO control register
		tmp_reg = p_dma_reg->stream[(uint8_t)stream].fifo_control;

		// Set FIFO Direct Mode
		p_stream_config_struct->fifo_direct_mode = (dma_stream_fifo_direct_mode_enum)(tmp_reg & DMA_STREAM_FIFO_DIRECT_MODE_MSK);

		// Set FIFO Threshold
		p_stream_config_struct->fifo_threshold = (dma_stream_fifo_threshold_enum)(tmp_reg & DMA_STREAM_FIFO_THRESHOLD_MSK);

		// Set FIFO Error Interrupt
		p_stream_config_struct->fifo_error_interrupt = (dma_stream_fifo_error_interrupt_enum)(tmp_reg & DMA_STREAM_FIFO_ERROR_INTERRUPT_MSK);

		success = true;
	}

	return success;
}

bool get_interrupt_status(const dma_enum dma, const dma_stream_enum stream, const dma_interrupt_type_enum interrupt)
{
	bool interrupt_pending = false;
	uint32_t interrupt_msk = ((uint32_t)interrupt << INTERRUPT_REGISTER_SHIFT_AMT[(uint8_t)stream]);

	if ((stream == DMA_STREAM_0) || (stream == DMA_STREAM_1) || (stream == DMA_STREAM_2) || (stream == DMA_STREAM_3))
	{
		interrupt_pending = (DMA_REG_PTRS[(uint8_t)dma]->status[(uint8_t)DMA_INTERRUPT_REG_LOW] & interrupt_msk); 
	}
	else
	{
		interrupt_pending = (DMA_REG_PTRS[(uint8_t)dma]->status[(uint8_t)DMA_INTERRUPT_REG_HIGH] & interrupt_msk);
	}

	return interrupt_pending;
}

void clear_interrupt_flag(const dma_enum dma, const dma_stream_enum stream, const dma_interrupt_type_enum interrupt)
{
	if (stream != DMA_STREAM_MAX_VALUE)
	{
		uint32_t interrupt_msk = ((uint32_t)interrupt << INTERRUPT_REGISTER_SHIFT_AMT[(uint8_t)stream]);

		if ((stream == DMA_STREAM_0) || (stream == DMA_STREAM_1) || (stream == DMA_STREAM_2) || (stream == DMA_STREAM_3))
		{
			DMA_REG_PTRS[(uint8_t)dma]->clear[(uint8_t)DMA_INTERRUPT_REG_LOW] |= interrupt_msk;
		}
		else
		{
			DMA_REG_PTRS[(uint8_t)dma]->clear[(uint8_t)DMA_INTERRUPT_REG_HIGH] |= interrupt_msk;
		}
	}
}
