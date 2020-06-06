#include "libmx.h"
/* 
функция создает матрицу(matrix) вида:
	A 	B 	C 	D
A 	0	n 	n 	n
B 	n 	0 	n 	n
C 	n 	n 	0 	n
D 	n 	n 	n 	0	
, где n - расстояние между городами i,j
+если matrix[j] == matrix[j], то расстояние = 0,
если matrix[i],matrix[j] не связаны, расстояние между ними = 10000
*/

void mx_make_matrix(char *file_name, char **unique_cities, int num_of_cities, int matrix[num_of_cities][num_of_cities])
{
	
	char *file_data = mx_file_to_str(file_name);
	//file_data[mx_strlen(file_data)] = '\n';
	char **file_data_splited = mx_strsplit(file_data, '\n');
	
	
	for (int i = 0; unique_cities[i] != NULL; ++i)
	{
		for (int j = 0; unique_cities[j] != NULL; ++j)
	 	{
	 		if (mx_strcmp(unique_cities[i],unique_cities[j]) == 0 || mx_strcmp(unique_cities[j],unique_cities[i]) == 0)
	 		{
	 			matrix[i][j] = 0;
	 		}
	 		else
	 		{
		 		for (int q = 1; file_data_splited[q] != NULL; ++q)
		 		{	
		 			char *result[4];
		 		 	mx_elements_of_line(file_data_splited[q], result);
		 		 	if (mx_strcmp(unique_cities[i], result[0]) == 0 && mx_strcmp(unique_cities[j], result[1]) == 0)
		 		 	{
		 		 		matrix[i][j] = mx_atoi(result[2]);
		 		 	}
		 		 	else if (mx_strcmp(unique_cities[i], result[1]) == 0 && mx_strcmp(unique_cities[j], result[0]) == 0)
		 		 	{
		 		 		matrix[i][j] = mx_atoi(result[2]);
		 		 	}
		 		}
	 		}

	 	}
	}

}


