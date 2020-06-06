#include "pathfinder.h"

/* Функция заполняет массив arr нужными значениями */

void mx_array_filler(int num_of_cities, char *arr[num_of_cities], int arr_int[num_of_cities], r_list *list, char *start, char *end)
{
	r_list *tmp = list;
	while(tmp)
	{
		if (mx_strcmp(tmp->s, start) == 0 && mx_strcmp(tmp->e, end) == 0)
		{
			arr[0] = tmp->s;
			arr[1] = tmp->m;
			arr[2] = tmp->e;
			arr_int[0] = tmp->a;
			arr_int[1] = tmp->b;
			arr_int[2] = tmp->c;
			break;
		}

		tmp = tmp -> next;
	}

}


