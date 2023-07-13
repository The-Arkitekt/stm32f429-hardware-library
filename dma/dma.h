#ifndef DMA_H
#define DMA_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * Constant Definitions
*/
static const uint32_t DMA_1_BASE_ADDR = 0x40026000U;
static const uint32_t DMA_2_BASE_ADDR = 0x40026400U;

static const uint8_t STREAM_0_4_INTERRUPT_REG_SHIFT_AMT = 0U;
static const uint8_t STREAM_1_5_INTERRUPT_REG_SHIFT_AMT = 6U;
static const uint8_t STREAM_2_6_INTERRUPT_REG_SHIFT_AMT = 16U;
static const uint8_t STREAM_3_7_INTERRUPT_REG_SHIFT_AMT = 22U;

/**
 * Indexing Enum Definitions
 */
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
	DMA_STREAM_7,
	DMA_STREAM_MAX_VALUE
}dma_stream_enum;


typedef enum
{
	DMA_INTERRUPT_REG_LOW = 0U,
	DMA_INTERRUPT_REG_HIGH,
	DMA_INTERRUPT_REG_MAX_VALUE
}dma_interrupt_reg_enum;

/**
 * Bit Mask Enum Definitions
*/
typedef enum
{
	DMA_INTERRUPT_FIFO_ERROR        = 0x1U,
	DMA_INTERRUPT_DIRECT_MODE_ERROR = 0x4U,
	DMA_INTERRUPT_TRANSFER_ERROR    = 0x8U,
	DMA_INTERRUPT_HALF_TRANSFER     = 0x10U,
	DMA_INTERRUPT_TRANSFER_COMPLETE = 0x20U
}dma_interrupt_type_enum;

typedef enum
{
	DMA_STREAM_DISABLED = 0U,
	DMA_STREAM_ENABLED = 0x00000001U
}dma_stream_enable_enum;

typedef enum
{
	DMA_STREAM_CHANNEL_0 = 0U,
	DMA_STREAM_CHANNEL_1 = 0x02000000U,
	DMA_STREAM_CHANNEL_2 = 0x04000000U,
	DMA_STREAM_CHANNEL_3 = 0x06000000U,
	DMA_STREAM_CHANNEL_4 = 0x08000000U,
	DMA_STREAM_CHANNEL_5 = 0x0A000000U,
	DMA_STREAM_CHANNEL_6 = 0x0C000000U,
	DMA_STREAM_CHANNEL_7 = 0x0E000000U,
}dma_stream_channel_enum;

typedef enum
{
	DMA_STREAM_FLOW_CONTROL_DMA        = 0U,
	DMA_STREAM_FLOW_CONTROL_PERIPHERAL = 0x00000020U,
}dma_stream_flow_control_enum;

typedef enum
{
	DMA_STREAM_PRIORITY_LOW      = 0U,
	DMA_STREAM_PRIORITY_MED      = 0x00010000U,
	DMA_STREAM_PRIORITY_HIGH     = 0x00020000U,
	DMA_STREAM_PRIORITY_VERYHIGH = 0x00030000U
}dma_stream_priority_enum;

typedef enum
{
	DMA_STREAM_FIFO_DIRECT_MODE_ENABLE  = 0U,
	DMA_STREAM_FIFO_DIRECT_MODE_DISABLE = 0x00000004U
}dma_stream_fifo_direct_mode_enum;

typedef enum
{
	DMA_STREAM_FIFO_THRESHOLD_QUARTER      = 0U,
	DMA_STREAM_FIFO_THRESHOLD_HALF         = 0x00000001U,
	DMA_STREAM_FIFO_THRESHOLD_THREEQUARTER = 0x00000002U,
	DMA_STREAM_FIFO_THRESHOLD_FULL         = 0x00000003U
}dma_stream_fifo_threshold_enum;
typedef enum
{
	DMA_STREAM_FIFO_ERROR_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_FIFO_ERROR_INTERRUPT_ENABLE  = 0x00000080U
}dma_stream_fifo_error_interrupt_enum;

typedef enum
{
	DMA_STREAM_DATA_TRANSFER_PERIPHERAL_TO_MEM = 0U,
	DMA_STREAM_DATA_TRANSFER_MEM_TO_PERIPHERAL = 0x00000040U,
	DMA_STREAM_DATA_TRANSFER_MEM_TO_MEM        = 0x00000080U,
	DMA_STREAM_DATA_TRANSFER_RESERVED_MASK     = 0x000000C0U
}dma_stream_data_transfer_direction_enum;

typedef enum
{
	DMA_STREAM_PERIPHERAL_FIXED_MODE     = 0U,
	DMA_STREAM_PERIPHERAL_INCREMENT_MODE = 0x00000200U
}dma_stream_peripheral_increment_enum;

typedef enum
{
	DMA_STREAM_PERIPHERAL_BURST_SINGLE = 0U,
	DMA_STREAM_PERIPHERAL_BURST_INCR4  = 0x00200000U,
	DMA_STREAM_PERIPHERAL_BURST_INCR8  = 0x00400000U,
	DMA_STREAM_PERIPHERAL_BURST_INCR16 = 0x00600000U
}dma_stream_peripheral_burst_enum;

typedef enum
{
	DMA_STREAM_PERIPHERAL_DATASIZE_BYTE          = 0U,
	DMA_STREAM_PERIPHERAL_DATASIZE_HALFWORD      = 0x00000800U,
	DMA_STREAM_PERIPHERAL_DATASIZE_WORD          = 0x00001000U,
	DMA_STREAM_PERIPHERAL_DATASIZE_RESERVED_MASK = 0x00001800U
}dma_stream_peripheral_data_size_enum;

typedef enum
{
	DMA_STREAM_MEM_FIXED_MODE     = 0U,
	DMA_STREAM_MEM_INCREMENT_MODE = 0x00000400U
}dma_stream_mem_increment_enum;

typedef enum
{
	DMA_STREAM_MEM_BURST_SINGLE = 0U,
	DMA_STREAM_MEM_BURST_INCR4  = 0x00800000U,
	DMA_STREAM_MEM_BURST_INCR8  = 0x01000000U,
	DMA_STREAM_MEM_BURST_INCR16 = 0x01800000U
}dma_stream_mem_burst_enum;

typedef enum
{
	DMA_STREAM_MEM_DATASIZE_BYTE          = 0U,
	DMA_STREAM_MEM_DATASIZE_HALFWORD      = 0x00002000U,
	DMA_STREAM_MEM_DATASIZE_WORD          = 0x00004000U,
	DMA_STREAM_MEM_DATASIZE_RESERVED_MASK = 0x00006000U,
}dma_stream_mem_data_size_enum;

typedef enum
{
	DMA_STREAM_SINGLE_BUFFER_MODE = 0U,
	DMA_STREAM_DOUBLE_BUFFER_MODE = 0x00040000U
}dma_stream_buffer_mode_enum;

typedef enum
{
	DMA_STREAM_CIRCULAR_MODE_DISABLE = 0U,
	DMA_STREAM_CIRCULAR_MODE_ENABLE  = 0x00000100U,
}dma_stream_circular_mode_enum;

typedef enum
{
	DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_TRANSFER_COMPLETE_INTERRUPT_ENABLE  = 0x00000010U,
}dma_stream_transfer_complete_interrupt_enum;

typedef enum
{
	DMA_STREAM_HALF_TRANSFER_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_HALF_TRANSFER_INTERRUPT_ENABLE  = 0x00000008U,
}dma_stream_half_transfer_interrupt_enum;

typedef enum
{
	DMA_STREAM_TRANSFER_ERROR_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_TRANSFER_ERROR_INTERRUPT_ENABLE  = 0x00000004U
}dma_stream_transfer_error_interrupt_enum;

typedef enum
{
	DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT_DISABLE = 0U,
	DMA_STREAM_DIRECT_MODE_ERROR_INTERRUPT_ENABLE  = 0x00000002U
}dma_stream_direct_mode_error_interrupt_enum;


/**
 * Interrupt Registers Shift Amount Array
 */
static const uint8_t INTERRUPT_REGISTER_SHIFT_AMT[] =
{
	STREAM_0_4_INTERRUPT_REG_SHIFT_AMT,
	STREAM_1_5_INTERRUPT_REG_SHIFT_AMT,
	STREAM_2_6_INTERRUPT_REG_SHIFT_AMT,
	STREAM_3_7_INTERRUPT_REG_SHIFT_AMT,
	STREAM_0_4_INTERRUPT_REG_SHIFT_AMT,
	STREAM_1_5_INTERRUPT_REG_SHIFT_AMT,
	STREAM_2_6_INTERRUPT_REG_SHIFT_AMT,
	STREAM_3_7_INTERRUPT_REG_SHIFT_AMT
};

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
	dma_stream_buffer_mode_enum                 buffer_mode;
	dma_stream_circular_mode_enum               circular_mode;
	dma_stream_transfer_complete_interrupt_enum transfer_complete_interrupt;
	dma_stream_half_transfer_interrupt_enum     half_transfer_interrupt;
	dma_stream_transfer_error_interrupt_enum    transfer_error_interrupt;
	dma_stream_direct_mode_error_interrupt_enum direct_mode_error_interrupt;
}dma_stream_config_interface_t;

/**
 * Register Struct Definitions
 */
typedef struct
{
	uint32_t control;
	uint32_t num_data;
	uint32_t peripheral_addr;
	uint32_t mem0_addr;
	uint32_t mem1_addr;
	uint32_t fifo_control;
}dma_stream_reg_t;

typedef struct
{
	uint32_t         status[DMA_INTERRUPT_REG_MAX_VALUE];
	uint32_t         clear[DMA_INTERRUPT_REG_MAX_VALUE];
	dma_stream_reg_t stream[DMA_STREAM_MAX_VALUE];
}dma_reg_t;

/**
 * Register Pointer Definitions
*/
static dma_reg_t volatile * const DMA_REG_PTRS[] =
{
	(dma_reg_t*)DMA_1_BASE_ADDR,
	(dma_reg_t*)DMA_2_BASE_ADDR
};

/**
 * Function Prototypes
 */
void dma_set_stream_enable(const dma_enum dma, const dma_stream_enum stream, const dma_stream_enable_enum value);
dma_stream_enable_enum dma_get_stream_enable_status(const dma_enum dma, const dma_stream_enum stream);

bool dma_set_stream_config(const dma_enum dma, const dma_stream_enum stream, const dma_stream_config_interface_t* const stream_control_struct);
bool dma_get_stream_config(const dma_enum dma, const dma_stream_enum stream, dma_stream_config_interface_t* const stream_control_struct);

bool get_interrupt_status(const dma_enum dma, const dma_stream_enum stream, const dma_interrupt_type_enum interrupt);
void clear_interrupt_flag(const dma_enum dma, const dma_stream_enum stream, const dma_interrupt_type_enum interrupt);

#ifdef __cplusplus
}
#endif

#endif //DMA_H
