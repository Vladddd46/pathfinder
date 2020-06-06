#include "libmx.h"

int mx_number_of_unique_cities(char *argv)
{
	char *data = mx_file_to_str(argv);
 	int l = 0;
 	while (data[l] != '\n') l++;
 	char x[l];
 	int i = 0;
 	while (i != l)
 	{
 		x[i] = data[i];
 		i++;
 	} 
 	x[i] = '\0';
 	int num_of_ucities = mx_atoi(x);
 
 	return num_of_ucities;
}


