#ifndef RETURN_CODES_H
#define RETURN_CODES_H

#ifdef __cplusplus
	extern "C" {
#endif

typedef enum ReturnCode{
	RETURNCODE_SUCCESS = 0U,
	RETURNCODE_INVALID_INPUT,
	RETURNCODE_NULL_POINTER,
	RETURNCODE_UNKNOWN
}ReturnCode;

#ifdef __cplusplus
}
#endif

#endif //RETURN_CODES
