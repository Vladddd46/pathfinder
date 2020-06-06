#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	unsigned long len = n;
 	unsigned char *dst1 = (unsigned char *)dst;
    const unsigned char *src1 = (const unsigned char *)src;

    unsigned long i = 0;
    for(; i < len && src1[i - 1] != c; i++) 
    {
		dst1[i] = src1[i];
	}

	if (dst1[i-1] == c)
	{
		return &dst1[i];
	}
	else
	{
		return NULL;
	}
}



