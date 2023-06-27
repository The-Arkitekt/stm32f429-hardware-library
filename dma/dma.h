#ifndef DMA_H
#define DMA_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

/**
 * Address Constants
 */
static const uint32_t DMA1_BASE_ADDR = 0x40026000U;
static const uint32_t DMA2_BASE_ADDR = 0x40026400U;

static const uint32_t DMA_STREAM_START  = 0x10U;
static const uint32_t DMA_STREAM_OFFSET = 0x18U;

static const uint32_t DMA1_STREAM_0_ADDR = DMA1_BASE_ADDR + DMA_STREAM_START;
static const uint32_t DMA1_STREAM_1_ADDR = DMA1_STREAM_0_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA1_STREAM_2_ADDR = DMA1_STREAM_1_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA1_STREAM_3_ADDR = DMA1_STREAM_2_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA1_STREAM_4_ADDR = DMA1_STREAM_3_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA1_STREAM_5_ADDR = DMA1_STREAM_4_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA1_STREAM_6_ADDR = DMA1_STREAM_5_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA1_STREAM_7_ADDR = DMA1_STREAM_6_ADDR + DMA_STREAM_OFFSET;

static const uint32_t DMA2_STREAM_0_ADDR = DMA2_BASE_ADDR + DMA_STREAM_START;
static const uint32_t DMA2_STREAM_1_ADDR = DMA2_STREAM_0_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA2_STREAM_2_ADDR = DMA2_STREAM_1_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA2_STREAM_3_ADDR = DMA2_STREAM_2_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA2_STREAM_4_ADDR = DMA2_STREAM_3_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA2_STREAM_5_ADDR = DMA2_STREAM_4_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA2_STREAM_6_ADDR = DMA2_STREAM_5_ADDR + DMA_STREAM_OFFSET;
static const uint32_t DMA2_STREAM_7_ADDR = DMA2_STREAM_6_ADDR + DMA_STREAM_OFFSET;

/**
 * Value Constants
 */
static const uint8_t NUM_DMA                          = 2U;
static const uint8_t NUM_DMA_STREAMS                  = 8U;
static const uint8_t NUM_DMA_INTERRUPT_REGS           = 2U;
static const uint8_t NUM_DMA_STREAM_CR_CHSEL_OPTIONS  = 8U;
static const uint8_t NUM_DMA_STREAM_CR_PFCTRL_OPTIONS = 2U;
static const uint8_t NUM_DMA_STREAM_CR_PL_OPTIONS     = 2U;
static const uint8_t NUM_DMA_STREAM_CR_DIR_OPTIONS    = 3U;
static const uint8_t NUM_DMA_STREAM_CR_PINC_OPTIONS   = 2U;
static const uint8_t NUM_DMA_STREAM_CR_PBURST_OPTIONS = 4U;
static const uint8_t NUM_DMA_STREAM_CR_PSIZE_OPTIONS  = 3U;
static const uint8_t NUM_DMA_STREAM_CR_MINC_OPTIONS   = 2U;
static const uint8_t NUM_DMA_STREAM_CR_MBURST_OPTIONS = 4U;
static const uint8_t NUM_DMA_STREAM_CR_MSIZE_OPTIONS  = 3U;
static const uint8_t NUM_DMA_STREAM_CR_DBM_OPTIONS    = 2U;
static const uint8_t NUM_DMA_STREAM_CR_CIRC_OPTIONS   = 2U;
static const uint8_t NUM_DMA_STREAM_CR_TCIE_OPTIONS   = 2U;
static const uint8_t NUM_DMA_STREAM_CR_HTIE_OPTIONS   = 2U;
static const uint8_t NUM_DMA_STREAM_CR_TEIE_OPTIONS   = 2U;
static const uint8_t NUM_DMA_STREAM_CR_DMEIE_OPTIONS  = 2U;

static const uint8_t NUM_DMA_STREAM_FCR_DMDIS_OPTIONS = 2U;
static const uint8_t NUM_DMA_STREAM_FCR_FTH_OPTIONS   = 4U;
static const uint8_t NUM_DMA_STREAM_FCR_FEIE_OPTIONS  = 2U;

/**
 * Bit Mask Constants
 */
static const uint32_t DMA_STREAM_CR_EN_MSK     = 0x00000001U;
static const uint32_t DMA_STREAM_CR_CHSEL_MSK  = 0x0E000000U;
static const uint32_t DMA_STREAM_CR_PFCTRL_MSK = 0x00000020U;
static const uint32_t DMA_STREAM_CR_PL_MSK     = 0x00030000U;
static const uint32_t DMA_STREAM_CR_DIR_MSK    = 0x000000C0U;
static const uint32_t DMA_STREAM_CR_PINC_MSK   = 0x00000200U;
static const uint32_t DMA_STREAM_CR_PBURST_MSK = 0x00600000U;
static const uint32_t DMA_STREAM_CR_PSIZE_MSK  = 0x00001800U;
static const uint32_t DMA_STREAM_CR_MINC_MSK   = 0x00000400U;
static const uint32_t DMA_STREAM_CR_MBURST_MSK = 0x01800000U;
static const uint32_t DMA_STREAM_CR_MSIZE_MSK  = 0x00006000U;
static const uint32_t DMA_STREAM_CR_DBM_MSK    = 0x00040000U;
static const uint32_t DMA_STREAM_CR_CIRC_MSK   = 0x00000100U;
static const uint32_t DMA_STREAM_CR_TCIE_MSK   = 0x00000010U;
static const uint32_t DMA_STREAM_CR_HTIE_MSK   = 0x00000008U;
static const uint32_t DMA_STREAM_CR_TEIE_MSK   = 0x00000004U;
static const uint32_t DMA_STREAM_CR_DMEIE_MSK  = 0x00000002U;

static const uint32_t DMA_STREAM_FCR_DMDIS_MSK = 0x00000004U;
static const uint32_t DMA_STREAM_FCR_FTH_MSK   = 0x00000003U;
static const uint32_t DMA_STREAM_FCR_FEIE_MSK  = 0x00000080U;

/**
 * Bit Mask Array Constants
 */
static const uint32_t DMA_STREAM_CR_CHSEL[NUM_DMA_STREAM_CR_CHSEL_OPTIONS] =
{
	0x0U,
	0x02000000U,
	0x04000000U,
	0x06000000U,
	0x08000000U,
	0x0A000000U,
	0x0C000000U,
	DMA_STREAM_CR_CHSEL_MSK
};

static const uint32_t DMA_STREAM_CR_PFCTRL[NUM_DMA_STREAM_CR_PFCTRL_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_PFCTRL_MSK
};

static const uint32_t DMA_STREAM_CR_PL[NUM_DMA_STREAM_CR_PL_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_PL_MSK
};

static const uint32_t DMA_STREAM_CR_DIR[NUM_DMA_STREAM_CR_DIR_OPTIONS] =
{
	0x0U,
	0x00000040U,
	0x00000080U
};

static const uint32_t DMA_STREAM_CR_PINC[NUM_DMA_STREAM_CR_PINC_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_PINC_MSK
};

static const uint32_t DMA_STREAM_CR_PBURST[NUM_DMA_STREAM_CR_PBURST_OPTIONS] =
{
	0x0U,
	0x00200000U,
	0x00400000U,
	DMA_STREAM_CR_PBURST_MSK
};

static const uint32_t DMA_STREAM_CR_PSIZE[NUM_DMA_STREAM_CR_PSIZE_OPTIONS] =
{
	0x0U,
	0x00000800U,
	0x00001000U
};

static const uint32_t DMA_STREAM_CR_MINC[NUM_DMA_STREAM_CR_MINC_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_MINC_MSK,
};

static const uint32_t DMA_STREAM_CR_MBURST[NUM_DMA_STREAM_CR_MBURST_OPTIONS] =
{
	0x0U,
	0x00800000U,
	0x01000000U,
	DMA_STREAM_CR_MBURST_MSK
};

static const uint32_t DMA_STREAM_CR_MSIZE[NUM_DMA_STREAM_CR_MSIZE_OPTIONS] =
{
	0x0U,
	0x00002000U,
	0x00004000U
};

static const uint32_t DMA_STREAM_CR_DBM[NUM_DMA_STREAM_CR_DBM_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_DBM_MSK
};

static const uint32_t DMA_STREAM_CR_CIRC[NUM_DMA_STREAM_CR_CIRC_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_CIRC_MSK
};

static const uint32_t DMA_STREAM_CR_TCIE[NUM_DMA_STREAM_CR_TCIE_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_TCIE_MSK
};

static const uint32_t DMA_STREAM_CR_HTIE[NUM_DMA_STREAM_CR_HTIE_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_HTIE_MSK
};

static const uint32_t DMA_STREAM_CR_TEIE[NUM_DMA_STREAM_CR_TEIE_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_TEIE_MSK
};

static const uint32_t DMA_STREAM_CR_DMEIE[NUM_DMA_STREAM_CR_DMEIE_OPTIONS] =
{
	0x0U,
	DMA_STREAM_CR_DMEIE_MSK
};

static const uint32_t DMA_STREAM_FCR_DMDIS[NUM_DMA_STREAM_FCR_DMDIS_OPTIONS] =
{
	0x0U,
	DMA_STREAM_FCR_DMDIS_MSK

};

static const uint32_t DMA_STREAM_FCR_FTH[NUM_DMA_STREAM_FCR_FTH_OPTIONS] =
{
	0x0U,
	0x00000001U,
	0x00000002U,
	DMA_STREAM_FCR_FTH_MSK
};

static const uint32_t DMA_STREAM_FCR_FEIE[NUM_DMA_STREAM_FCR_FEIE_OPTIONS] =
{
	0x0U,
	DMA_STREAM_FCR_FEIE_MSK
};

/**
 * Enum Definitions
 */
typedef enum
{
	DMA_RETURN_SUCCESS,
	DMA_RETURN_FAIL
}dma_return_value_enum;

typedef enum
{
	DMA_1 = 0U,
	DMA_2
}dma_enum;

typedef enum
{
	DMA_STREAM_0 = 0U,
	DMA_STREAM_1,
	DMA_STREAM_2,
	DMA_STREAM_3,
	DMA_STREAM_4,
	DMA_STREAM_5,
	DMA_STREAM_6,
	DMA_STREAM_7
}dma_stream_enum;

typedef enum
{
	DMA_STREAM_CHANNEL_0 = 0U,
	DMA_STREAM_CHANNEL_1,
	DMA_STREAM_CHANNEL_2,
	DMA_STREAM_CHANNEL_3,
	DMA_STREAM_CHANNEL_4,
	DMA_STREAM_CHANNEL_5,
	DMA_STREAM_CHANNEL_6,
	DMA_STREAM_CHANNEL_7
}dma_stream_channel_enum;

typedef enum
{
	DMA_STREAM_FLOW_CONTROL_DMA = 0U,
	DMA_STREAM_FLOW_CONTROL_PERIPHERAL,
}dma_stream_flow_control_enum;

typedef enum
{
	DMA_STREAM_PRIORITY_LOW = 0U,
	DMA_STREAM_PRIORITY_MED,
	DMA_STREAM_PRIORITY_HIGH,
	DMA_STREAM_PRIORITY_VERYHIGH
}dma_stream_priority_enum;

typedef enum
{
	DMA_STREAM_FIFO_DIRECT_MODE_ENABLE = 0U,
	DMA_STREAM_FIFO_DIRECT_MODE_DISABLE,
}dma_stream_fifo_direct_mode_enum;

typedef enum
{
	DMA_STREAM_FIFO_THRESHOLD_QUARTER = 0U,
	DMA_STREAM_FIFO_THRESHOLD_HALF,
	DMA_STREAM_FIFO_THRESHOLD_THREEQUARTER,
	DMA_STREAM_FIFO_THRESHOLD_FULL
}dma_stream_fifo_threshold_enum;

typedef enum
{
	DMA_STREAM_FIFO_ERROR_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_FIFO_ERROR_INTERRUPT_ENABLE
}dma_stream_fifo_error_interrupt_enum;

typedef enum
{
	DMA_STREAM_DATA_TRANSFER_PERIPHERAL_TO_MEM = 0U,
	DMA_STREAM_DATA_TRANSFER_MEM_TO_PERIPHERAL,
	DMA_STREAM_DATA_TRANSFER_MEM_TO_MEM,
}dma_stream_data_transfer_direction_enum;

typedef enum
{
	DMA_STREAM_PERIPHERAL_FIXED_MODE = 0U,
	DMA_STREAM_PERIPHERAL_INCREMENT_MODE
}dma_stream_peripheral_increment_enum;

typedef enum
{
	DMA_STREAM_PERIPHERAL_BURST_SINGLE = 0U,
	DMA_STREAM_PERIPHERAL_BURST_INCR4,
	DMA_STREAM_PERIPHERAL_BURST_INCR8,
	DMA_STREAM_PERIPHERAL_BURST_INCR16
}dma_stream_peripheral_burst_enum;

typedef enum
{
	DMA_STREAM_PERIPHERAL_DATASIZE_BYTE = 0U,
	DMA_STREAM_PERIPHERAL_DATASIZE_HALFWORD,
	DMA_STREAM_PERIPHERAL_DATASIZE_WORD
}dma_stream_peripheral_data_size_enum;

typedef enum
{
	DMA_STREAM_MEM_FIXED_MODE = 0U,
	DMA_STREAM_MEM_INCREMENT_MODE
}dma_stream_mem_increment_enum;

typedef enum
{
	DMA_STREAM_MEM_BURST_SINGLE = 0U,
	DMA_STREAM_MEM_BURST_INCR4,
	DMA_STREAM_MEM_BURST_INCR8,
	DMA_STREAM_MEM_BURST_INCR16
}dma_stream_mem_burst_enum;

typedef enum
{
	DMA_STREAM_MEM_DATASIZE_BYTE = 0U,
	DMA_STREAM_MEM_DATASIZE_HALFWORD,
	DMA_STREAM_MEM_DATASIZE_WORD
}dma_stream_mem_data_size_enum;

typedef enum
{
	DMA_STREAM_SINGLE_BUFFER_MODE = 0U,
	DMA_STREAM_DOUBLE_BUFFER_MODE
}dma_stream_buffer_mode_enum;

typedef enum
{
	DMA_STREAM_CIRCULAR_MODE_DISABLE = 0U,
	DMA_STREAM_CIRCULAR_MODE_ENABLE,
}dma_stream_circular_mode_enum;

typedef enum
{
	DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT_ENABLE,
}dma_stream_transfer_complete_interrupt_enum;

typedef enum
{
	DMA_STREAM_HALF_TRANSFER_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_HALF_TRANSFER_INTERRUPT_ENABLE,
}dma_stream_half_transfer_interrupt_enum;

typedef enum
{
	DMA_STREAM_TRANSFER_ERROR_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_TRANSFER_ERROR_INTERRUPT_ENABLE
}dma_stream_transfer_error_interrupt_enum;

typedef enum
{
	DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT_ENABLE
}dma_stream_direct_mode_error_interrupt_enum;

/**
 * Interface Struct Definitions
 */
typedef struct
{
	uint32_t                                    peripheral_addr;
	uint32_t                                    mem0_addr;
	uint32_t                                    mem1_addr;
	uint32_t                                    num_data_items;
	dma_stream_channel_enum                     channel;
	dma_stream_flow_control_enum                flow_control;
	dma_stream_priority_enum                    priority_level;
	dma_stream_fifo_direct_mode_enum            fifo_direct_mode;
	dma_stream_fifo_threshold_enum              fifo_threshold;
	dma_stream_fifo_error_interrupt_enum	    fifo_error_interrupt;
	dma_stream_data_transfer_direction_enum     data_transfer_direction;
	dma_stream_peripheral_increment_enum        peripheral_increment_mode;
	dma_stream_peripheral_burst_enum            peripheral_burst;
	dma_stream_peripheral_data_size_enum        peripheral_data_size;
	dma_stream_mem_increment_enum               memory_increment;
	dma_stream_mem_burst_enum                   memory_burst;
	dma_stream_mem_data_size_enum               memory_data_size;
	dma_stream_mem_data_size_enum               buffer_mode;
	dma_stream_circular_mode_enum               circular_mode;
	dma_stream_transfer_complete_interrupt_enum transfer_complete_interrupt;
	dma_stream_half_transfer_interrupt_enum     half_transfer_interrupt;
	dma_stream_transfer_error_interrupt_enum    transfer_error_interrupt;
	dma_stream_direct_mode_error_interrupt_enum direct_mode_error_interrupt;
}dma_stream_interface_t;

/**
 * Register Struct Definitions
 */
typedef struct
{
	uint32_t status[NUM_DMA_INTERRUPT_REGS];
	uint32_t clear[NUM_DMA_INTERRUPT_REGS];
}dma_interrupt_reg_t;

typedef struct
{
	uint32_t config;
	uint32_t num_data;
	uint32_t peripheral_addr;
	uint32_t mem0_addr;
	uint32_t mem1_addr;
	uint32_t fifo_control;
}dma_stream_reg_t;

/**
 * Register Pointer Constants
 */
static dma_interrupt_reg_t volatile * const p_dma_interrupt[NUM_DMA] =
{
		(dma_interrupt_reg_t*)DMA1_BASE_ADDR,
		(dma_interrupt_reg_t*)DMA2_BASE_ADDR
};

static dma_stream_reg_t volatile * const p_dma_stream[NUM_DMA][NUM_DMA_STREAMS] =
{
	(
		(dma_stream_reg_t*)DMA1_STREAM_0_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_1_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_2_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_3_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_4_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_5_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_6_ADDR,
		(dma_stream_reg_t*)DMA1_STREAM_7_ADDR
	),
	(
		(dma_stream_reg_t*)DMA2_STREAM_0_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_1_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_2_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_3_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_4_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_5_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_6_ADDR,
		(dma_stream_reg_t*)DMA2_STREAM_7_ADDR
	)
};


/**
 * Function Prototypes
 */
dma_return_value_enum dma_set_stream_config(const dma_enum dma, const dma_stream_enum stream, const dma_stream_interface_t* const stream_control_struct);



#ifdef __cplusplus
}
#endif

#endif //DMA_H
