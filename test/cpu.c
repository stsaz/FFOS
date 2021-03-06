/**
Copyright (c) 2017 Simon Zolin
*/

#include <FFOS/cpuid.h>
#include <FFOS/test.h>


void test_cpu()
{
	ffcpuid c = {};
	x(0 == ff_cpuid(&c, FFCPUID_VENDOR | FFCPUID_FEATURES | FFCPUID_BRAND));
	printf("CPU:%s\nBrand:%s\n"
		"SSE:%u\nSSE2:%u\nSSE3:%u\nSSSE3:%u\nSSE4.1:%u\nSSE4.2:%u\n"
		"POPCNT:%u\n"
		, c.vendor, c.brand
		, ff_cpuid_feat(&c, FFCPUID_SSE)
		, ff_cpuid_feat(&c, FFCPUID_SSE2)
		, ff_cpuid_feat(&c, FFCPUID_SSE3)
		, ff_cpuid_feat(&c, FFCPUID_SSSE3)
		, ff_cpuid_feat(&c, FFCPUID_SSE41)
		, ff_cpuid_feat(&c, FFCPUID_SSE42)
		, ff_cpuid_feat(&c, FFCPUID_POPCNT)
		);

#if 0
	fflog("TSC:%xU", ffcpu_rdtsc());

	x(0xffffffff == ffint_addcarry32(0xfffffffe, 1));
	x(0xfffffffe + 1 == ffint_addcarry32(0xffffffff, 0xffffffff));
#endif
}
