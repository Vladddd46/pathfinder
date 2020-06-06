#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim){

	if (arr == NULL || delim == NULL)
	{
		return;
	}

	for (unsigned long i = 0; arr[i] != NULL; ++i)
	{
		mx_printstr(arr[i]);
		mx_printstr(delim);
	}

	mx_printchar('\n');
}




