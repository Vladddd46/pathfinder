#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *temp;
    temp = dst;
    int i = 0;  
    for (; i < len; i++)
        *dst++ = *src++;
   return temp;
}

