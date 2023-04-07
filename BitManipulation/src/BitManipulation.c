#include "CommonDef.h"
#include "BitManipulation.h"

WORD_TYPE generateWordMask(const WORD_TYPE seed, const BIT_TYPE shiftAmt){

	return seed << shiftAmt;
}

HALF_WORD_TYPE generateHalfWordMask(const HALF_WORD_TYPE seed, const BIT_TYPE shiftAmt){

	return seed << shiftAmt;
}

BYTE_TYPE generateByteMask(const BYTE_TYPE seed, const BIT_TYPE shiftAmt){

	return seed << shiftAmt;
}

ReturnCode clearWordBits(const WORD_TYPE mask,const BIT_TYPE location, volatile WORD_TYPE* const wordPtr){

	if ((location > WORD_SIZE) || wordPtr == NULL){
		return RETURNCODE_INVALID_INPUT;
	}

	(*wordPtr) &= ~(generateWordMask(mask, location));
	return RETURNCODE_SUCCESS;
}

ReturnCode setWordBits(const WORD_TYPE mask, const BIT_TYPE location, volatile WORD_TYPE* const wordPtr){

	if ((location > WORD_SIZE) || wordPtr == NULL){
		return RETURNCODE_INVALID_INPUT;
	}

	(*wordPtr) |= generateWordMask(mask, location);
	return RETURNCODE_SUCCESS;
}

BIT_TYPE checkWordBits(const WORD_TYPE word, const WORD_TYPE mask, const BIT_TYPE location){
	BIT_TYPE ret = 0;
	if (word & generateWordMask(0x1, location)){
		ret = 1;
	}

	return ret;
}
