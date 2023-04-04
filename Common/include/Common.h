#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

uint32_t generate32BitMask(uint32_t seed, const uint8_t shiftAmt);


#ifdef __cplusplus
}
#endif

#endif //COMMON_H
