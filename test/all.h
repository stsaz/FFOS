/**
Copyright (c) 2013 Simon Zolin
*/

#include <FFOS/types.h>
#include <FFOS/string.h>

FF_EXTN int test_types();
FF_EXTN int test_mem();
FF_EXTN int test_time();
FF_EXTN int test_file();
FF_EXTN int test_dir(const char *tmpdir);
FF_EXTN int test_thd();
FF_EXTN int test_skt();
FF_EXTN int test_timer();
FF_EXTN int test_kqu();
FF_EXTN int test_cpu();
FF_EXTN int test_wreg();

#ifdef FF_UNIX
#define TMP_PATH "/tmp"
#else
#define TMP_PATH "."
#endif
