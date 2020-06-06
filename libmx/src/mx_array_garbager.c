#include "libmx.h"

void mx_array_garbager(int num_of_cities,  int arr_int[num_of_cities])
{
	int end = num_of_cities - 1;
	for (; end != 0; end--)
	{
		int counter = 0;
		for (int i = 0; i < end; ++i)
		{
			counter += arr_int[i];
		}

		if (arr_int[end] == counter)
		{
			break;
		}
	}

	for (int i = num_of_cities - 1; i > end; i--)
	{
		arr_int[i] = 0;
	}
}




