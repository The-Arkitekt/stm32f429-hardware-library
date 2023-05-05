#ifndef IRQ_DEF_H
#define IRQ_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "system_conf.h"

#ifdef STM32F429
#include "../Irq/STM32F429_IrqDef.h"
#endif

#ifdef __cplusplus
}
#endif

#endif //IRQ_DEF_H
