#ifndef RETURN_CODE_H
#define RETURN_CODE_H
// TODO: Delete this type, shouldnt be necessary
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

#endif //RETURN_CODE_H
