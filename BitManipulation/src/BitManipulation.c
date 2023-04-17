#include "CommonDef.h"
#include "BitManipulation.h"

WORD_TYPE generateWordMask(const WORD_TYPE seed, const BYTE_TYPE shiftAmt){

	return seed << shiftAmt;
}

HALF_WORD_TYPE generateHalfWordMask(const HALF_WORD_TYPE seed, const BYTE_TYPE shiftAmt){

	return seed << shiftAmt;
}

BYTE_TYPE generateByteMask(const BYTE_TYPE seed, const BYTE_TYPE shiftAmt){

	return seed << shiftAmt;
}

ReturnCode clearWordBits(const WORD_TYPE mask,const BYTE_TYPE location, volatile WORD_TYPE* const wordPtr){

	if ((location > WORD_SIZE) || wordPtr == NULL){
		return RETURNCODE_INVALID_INPUT;
	}

	(*wordPtr) &= ~(generateWordMask(mask, location));
	return RETURNCODE_SUCCESS;
}

ReturnCode setWordBits(const WORD_TYPE mask, const BYTE_TYPE location, volatile WORD_TYPE* const wordPtr){

	if ((location > WORD_SIZE) || wordPtr == NULL){
		return RETURNCODE_INVALID_INPUT;
	}

	(*wordPtr) |= generateWordMask(mask, location);
	return RETURNCODE_SUCCESS;
}

Boolean checkWordBits(const WORD_TYPE word, const WORD_TYPE mask, const BYTE_TYPE location){
	Boolean ret = FALSE;
	if (word & generateWordMask(0x1, location)){
		ret = TRUE;
	}

	return ret;
}
