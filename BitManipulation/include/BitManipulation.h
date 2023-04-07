#ifndef BITMANIPULATION_H
#define BITMANIPULATION_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "BitManipulationDef.h"
#include "ReturnCodesDef.h"

ReturnCode clearWordBits(const WORD_TYPE mask, const BYTE_TYPE location, volatile WORD_TYPE* const wordPtr);
ReturnCode setWordBits(const WORD_TYPE mask, const BYTE_TYPE location, volatile WORD_TYPE* const wordPtr);

BIT_TYPE checkWordBits(const WORD_TYPE word, const WORD_TYPE mask, const BYTE_TYPE location);

WORD_TYPE      generateWordMask(const WORD_TYPE seed, const BYTE_TYPE shiftAmt);
HALF_WORD_TYPE generateHalfWordMask(const HALF_WORD_TYPE seed, const BYTE_TYPE shiftAmt);
BYTE_TYPE      generateByteMask(const BYTE_TYPE seed, const BYTE_TYPE shiftAmt);

#ifdef __cplusplus
}
#endif

#endif //BITMANIPULATION_H
