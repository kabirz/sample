/*
 * Sample code for calculating cpu frequecy.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc(void)
{
	union {
		struct  {
			uint32_t lo;
			uint32_t hi;
		};
		uint64_t  value;
	}  rv;

	/* rdtsc & cpuid clobbers eax, ebx, ecx and edx registers */
	__asm__ volatile (/* serialize */
		"xorl %%eax,%%eax;\n\t"
		"cpuid;\n\t"
		:
		:
		: "%eax", "%ebx", "%ecx", "%edx"
		);
	/*
	 * We cannot use "=A", since this would use %rax on x86_64 and
	 * return only the lower 32bits of the TSC
	 */
	__asm__ volatile ("rdtsc" : "=a" (rv.lo), "=d" (rv.hi));

	return rv.value;
}

int main(int argc, char const *argv[])
{
	uint64_t t1, t2;
	t1 = rdtsc();
	sleep(1);
	t2 = rdtsc();
	printf("cpu MHz : %lu\n", (t2 - t1) / 1000000);
	return 0;
}
