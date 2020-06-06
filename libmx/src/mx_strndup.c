#include "libmx.h"

char *mx_strndup(const char *s1, size_t n){

	char *memory = mx_strnew(n);
	unsigned long i = 0;
	while(i < (unsigned long)n){
		memory[i] = s1[i];
		i++;
	}

	return memory;
}


