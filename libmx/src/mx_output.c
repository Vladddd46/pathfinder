#include "libmx.h"

/*
Функция вывода
*/

void mx_output(int num_of_cities, int matrix[num_of_cities][num_of_cities], char **unique_cities, r_list *list)
{

	//прохожусь по каждому элементу uniquecities
	int j_step = 1;
	for (int i = 0; i < num_of_cities; ++i)
	{
		for (int j = j_step; j < num_of_cities; ++j)
		{		
	
			 if(mx_is_in_list(list,unique_cities[i], unique_cities[j]))
			 {
			 	


			 	char *arr[num_of_cities+1];
			 	//заполняю массив arr NULLом
			 	int filler = 0;
			 	while (filler < num_of_cities+1)
			 	{
			 		arr[filler] = NULL;
			 		filler++;
			 	}
			 	//массив в котором будут хранится расстояния между городами
			 	int arr_int[num_of_cities];
			 	for (int i = 0; i < num_of_cities; ++i) arr[i] = NULL;

			 	//первоначально заполняю массив arr {start,middle,end} и arr_int
			 	mx_array_filler(num_of_cities+1, arr, arr_int, list, unique_cities[i], unique_cities[j]);

			 	//редактирую arr если между start/end нету прямогу пути к middle

			 	//данная переменная нужна для проверки на вывод в функции mx_outer_array_recursion
			 	int was_recursed = 0;
			 	mx_outer_array_recursion_editor(list, num_of_cities+1, arr, arr_int, was_recursed);
			 	
			 }
			 else
			 {
			 	int res = matrix[i][j];
			 	mx_printstr("========================================\n");
			 	mx_printer(unique_cities[i], unique_cities[j], res);
			 	mx_printstr("========================================\n");
			 }

		}
		j_step++;
	}

}

