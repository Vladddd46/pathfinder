#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned long len =(unsigned long)n;

	char *a = (char *)s1;
	char *b = (char *)s2;


	unsigned long i = 0;
    while(a[i] == b[i] && i < len) 
    {   
        i++;
    }
    if(a[i] != b[i]) 
    {
        return a[i] - b[i];
    } 
    return 0;
}




