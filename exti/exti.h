#ifndef EXTI_H
#define EXTI_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * Constant Definitions
*/
static const uint32_t EXTI_BASE_ADDR = 0x40013C00U;

/**
 * Indexing Enum Definitions
*/
typedef enum
{
	EXTI_MODE_DISABLED = 0U,
	EXTI_MODE_INTERRUPT,
	EXTI_MODE_EVENT,
	EXTI_MODE_INVALID
}exti_mode_enum;

/**
 * Bit Mask Enum Definitions
*/
typedef enum
{
	EXTI_LINE_0  = 0x00000001U,
	EXTI_LINE_1  = 0x00000002U,
	EXTI_LINE_2  = 0x00000004U,
	EXTI_LINE_3  = 0x00000008U,
	EXTI_LINE_4  = 0x00000010U,
	EXTI_LINE_5  = 0x00000020U,
	EXTI_LINE_6  = 0x00000040U,
	EXTI_LINE_7  = 0x00000080U,
	EXTI_LINE_8  = 0x00000100U,
	EXTI_LINE_9  = 0x00000200U,
	EXTI_LINE_10 = 0x00000400U,
	EXTI_LINE_11 = 0x00000800U,
	EXTI_LINE_12 = 0x00001000U,
	EXTI_LINE_13 = 0x00002000U,
	EXTI_LINE_14 = 0x00004000U,
	EXTI_LINE_15 = 0x00008000U,
	EXTI_LINE_16 = 0x00010000U,
	EXTI_LINE_17 = 0x00020000U,
	EXTI_LINE_18 = 0x00040000U,
	EXTI_LINE_19 = 0x00080000U,
	EXTI_LINE_20 = 0x00100000U,
	EXTI_LINE_21 = 0x00200000U,
	EXTI_LINE_22 = 0x00400000U
}exti_line_enum;

/**
 * Interface Struct Definitions
 */
typedef struct
{
	exti_mode_enum mode;
	bool           risingTriggerEnable;
	bool           fallingTriggerEnable;
}exti_config_interface_t;

/**
 * Register Struct Definitions
 */
typedef struct
{
	uint32_t interruptMask;
	uint32_t eventMask;
	uint32_t risingTriggerSelect;
	uint32_t fallingTriggerSelect;
	uint32_t softwareInterruptEvent;
	uint32_t pending;
}exti_reg_t;

/**
 * Register Pointer Definitions
 */
static exti_reg_t volatile * const EXTI_REG = (exti_reg_t*)EXTI_BASE_ADDR;

/**
 * Function Prototypes
 */
bool exti_set_config(const exti_line_enum line, const exti_config_interface_t* const exti_config_struct);
bool exti_get_config_status(const exti_line_enum line, exti_config_interface_t* const exti_config_struct);
void exti_set_software_trigger(const exti_line_enum line);
bool exti_check_pending(const exti_line_enum line);
void exti_clear_pending(const exti_line_enum line);

#ifdef __cplusplus
}
#endif

#endif //EXTI_H
