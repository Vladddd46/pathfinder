#include "libmx.h"

int mx_atoi(const char *s) {
	int n = 0;
    while( *s >= '0' && *s <= '9' ) {
        n *= 10;
        n += *s++;
        n -= '0';
    }
    return n;
}


