#include "pathfinder.h"

void mx_array_extender(int num_of_cities, char *array[num_of_cities], char *insert_element, int insert_index)
{
	int i = num_of_cities - 2;
	
	for (; i >= insert_index; i--)
	{
		array[i + 1] = array[i];
	}
	array[i+1] = insert_element;

}



