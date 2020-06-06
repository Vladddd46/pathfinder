#include "pathfinder.h"


void mx_array_recursion_editor(r_list *list, int num_of_cities, char *array[num_of_cities],  int arr_int[num_of_cities], int pure_arr_int[num_of_cities])
{
	int checker_1 = 0;
	//копия листа
	r_list *copy = mx_copy_r_list(list);
	//создаю копию массива
	char *tmp_arr[num_of_cities];
	for (int i = 0; i < num_of_cities; ++i)
	{
		tmp_arr[i] = array[i];
	}



	for (int i = 0; tmp_arr[i+1] != NULL; ++i)
	{
		r_list *tmp = copy;
		while (tmp)
		{
			if (mx_strcmp(tmp->s,tmp_arr[i]) == 0 && mx_strcmp(tmp->e,tmp_arr[i+1]) == 0)
			{
				mx_array_extender(num_of_cities, tmp_arr, tmp->m, i+1);
				mx_int_array_extender(num_of_cities, pure_arr_int, tmp->a, tmp->b, i);
				tmp->s = "NULL";
				tmp->e = "NULL";
				checker_1 = 1;
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
		mx_array_recursion_editor(copy, num_of_cities, tmp_arr, arr_int, pure_arr_int);
	}
	else
	{
		//конечная функция принта
		//перевернуть СВЯЗНОЙ СПИСОК
		mx_big_array_printer(num_of_cities, tmp_arr,  pure_arr_int);	
	}

}








