#include "libmx.h"


void mx_outer_array_recursion_editor(r_list *list, int num_of_cities, char *array[num_of_cities], int arr_int[num_of_cities], int was_recursed)
{

	/* Создание копий */
	int checker_1 = 0;
	//копия листа
	r_list *copy_1 = mx_copy_r_list(list);
	//создаю копию массива
	char *tmp_arr[num_of_cities];
	for (int i = 0; i < num_of_cities; ++i)
	{
		tmp_arr[i] = array[i];
	}
	//создаю копию массива чисел
	int tmp_arr_int[num_of_cities];
	for (int i = 0; i < num_of_cities; ++i)
	{
		tmp_arr_int[i] = arr_int[i];
	}
	/* ================== */


	r_list *copy = mx_r_list_reverse(copy_1);


	for (int i = 0; tmp_arr[i+1] != NULL; ++i)
	{
		r_list *tmp = copy;
		while(tmp)
		{
			if (mx_strcmp(tmp->s,tmp_arr[i]) == 0 && mx_strcmp(tmp->e,tmp_arr[i+1]) == 0)
			{
				mx_array_recursion_editor(copy, num_of_cities, tmp_arr, arr_int, tmp_arr_int);
				tmp->s = "NULL";
				tmp->e = "NULL";
				checker_1 = 1;
				was_recursed++;
				break;
			}
			tmp = tmp->next;
		}
		if(checker_1)
		{
			break;
		}
	}



	if (checker_1)
	{
		mx_outer_array_recursion_editor(copy, num_of_cities, array, arr_int, was_recursed);
	}
	else
	{
		if (was_recursed == 0)
		{
			mx_array_printer(copy, num_of_cities, tmp_arr);
		}

	}

}














