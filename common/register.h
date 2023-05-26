#ifndef REGISTER_H
#define REGISTER_H

#ifdef __cplusplus
	extern "C" {
#endif

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
 * Define max values
 * 	Shouldnt need to make arrays this big so typed constants are used
*/
static const WORD_TYPE      WORD_MAX_VALUE      = 0xFFFFFFFF;
static const HALF_WORD_TYPE HALF_WORD_MAX_VALUE = 0xFFFF;
//@}

#ifdef __cplusplus
}
#endif

#endif //REGISTER_H