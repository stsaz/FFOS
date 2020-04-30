/**
Target architecture, OS;  base types;  base macros.
Copyright (c) 2013 Simon Zolin
*/

#ifndef FF_VER

#define FF_VER  0x010d0000

#include <FFOS/detect-cpu.h>
#include <FFOS/detect-os.h>

#if defined FF_LINUX
	#include <FFOS/linux/types.h>

#elif defined FF_APPLE
	#include <FFOS/bsd/types.h>

#elif defined FF_BSD
	#include <FFOS/bsd/types.h>
#endif

#if defined FF_UNIX
	#include <FFOS/unix/types.h>

#elif defined FF_WIN
	#include <FFOS/win/types.h>
#endif

#include <FFOS/detect-compiler.h>
#include <FFOS/compiler-gcc.h>


typedef signed char ffint8;
typedef int ffbool;

#ifdef __cplusplus
	#define FF_EXTN extern "C"
#else
	#define FF_EXTN extern
#endif

#if defined _DEBUG || defined FF_ASSERT_ENABLED
	#include <assert.h>
	#define FF_ASSERT(expr)  assert(expr)
#else
	#define FF_ASSERT(expr)
#endif


#define FF_SAFECLOSE(obj, def, func)\
do { \
	if (obj != def) { \
		func(obj); \
		obj = def; \
	} \
} while (0)


enum FFDBG_T {
	FFDBG_MEM = 0x10,
	FFDBG_KEV = 0x20,
	FFDBG_TIMER = 0x40,
	FFDBG_PARSE = 0x100,
};

/** Print FF debug messages.
@t: enum FFDBG_T + level. */
extern int ffdbg_print(int t, const char *fmt, ...);

#ifdef _DEBUG
extern int ffdbg_mask; //~(enum FFDBG_T) + level

#define FFDBG_CHKLEV(t) \
	((ffdbg_mask & 0x0f) >= ((t) & 0x0f) && !((ffdbg_mask & (t)) & ~0x0f))

#define FFDBG_PRINT(t, ...) \
do { \
	if (FFDBG_CHKLEV(t)) \
		ffdbg_print(t, __VA_ARGS__); \
} while (0)

#define FFDBG_PRINTLN(t, fmt, ...) \
do { \
	if (FFDBG_CHKLEV(t)) \
		ffdbg_print(t, "%s(): " fmt "\n", FF_FUNC, __VA_ARGS__); \
} while (0)

#else
#define FFDBG_PRINT(...)
#define FFDBG_PRINTLN(...)
#endif


#include <FFOS/number.h>

#endif //FF_VER
