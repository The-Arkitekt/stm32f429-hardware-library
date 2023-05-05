#ifndef COMMON_DEF_H
#define COMMON_DEF_H

#ifdef __cplusplus
	extern "C" {
#endif

#ifndef NULL
	#define NULL 0
#endif //NULL

typedef enum Boolean{
	FALSE = 0U,
	TRUE
}Boolean;

#ifdef __cplusplus
}
#endif

#endif //COMMON_DEF_H
