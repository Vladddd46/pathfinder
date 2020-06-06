#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
	
	// make ptr point to the end of destination string
    char* ptr = s1 + mx_strlen(s1);

    // Appends characters of source to the destination string
    while (*s2 != '\0')
        *ptr++ = *s2++;

    // null terminate destination string
    *ptr = '\0';

    // destination is returned by standard strcat()
    return s1;
}


