#ifndef REGISTER_H
#define REGISTER_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

/**
 * Abstract the C style fixed size data types
*/
typedef uint32_t WORD_TYPE;
typedef uint16_t HALF_WORD_TYPE;
typedef uint8_t BYTE_TYPE;

//@{
/**
 * Define sizes
 * 	using preprocessor define so they can be used as array size parameters
*/
#ifndef WORD_SIZE
	#define WORD_SIZE 32U
#endif //WORD_SIZE

#ifndef HALF_WORD_SIZE
	#define HALF_WORD_SIZE 16U
#endif //HALF_WORD_SIZE
//@}

//@{
/**
 * Define mask values
*/
static const BYTE_TYPE      ONE_BIT_MASK   = 0b1;
static const BYTE_TYPE      TWO_BIT_MASK   = 0b11;
static const BYTE_TYPE      THREE_BIT_MASK = 0b111;
static const BYTE_TYPE      FOUR_BIT_MASK  = 0b1111;

static const HALF_WORD_TYPE HALF_WORD_MASK = 0xFFFF;
static const WORD_TYPE      WORD_MASK      = 0xFFFFFFFF;
//@}

/**
 * Store register bitfield details
*/
typedef struct BitFieldDetails{
	BYTE_TYPE position;
	BYTE_TYPE maxValidValue;
	BYTE_TYPE mask;
}BitFieldDetails;

#ifdef __cplusplus
}
#endif

#endif //REGISTER_H