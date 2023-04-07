#ifndef BITMANIPULATION_DEF_H
#define BITMANIPULATION_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

typedef uint32_t WORD_TYPE;
typedef uint16_t HALF_WORD_TYPE;
typedef uint8_t BYTE_TYPE;
typedef uint8_t BIT_TYPE;

static const uint8_t WORD_SIZE = 32U;
static const uint8_t HALF_WORD_SIZE = 16U;

#ifdef __cplusplus
}
#endif

#endif //BITMANIPULATION_DEF_H
