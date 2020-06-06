#include "pathfinder.h"


r_list *mx_algorithm(int num_of_cities, int matrix[num_of_cities][num_of_cities], char **unique_cities)
{

	r_list *route_list = mx_create_route_node("NULL","NULL","NULL",0,0,0);

	for (int k = 0; k < num_of_cities; ++k)
	{
		for (int i = 0; i < num_of_cities; ++i)
		{
			for (int j = 0; j < num_of_cities; ++j) 
			{

				if (matrix[i][j] >= matrix[i][k] + matrix[k][j] && matrix[i][j] != 0 && matrix[i][k]!= 0 && matrix[k][j] != 0 )
				{
					
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					mx_push_route_front(&route_list, unique_cities[i], unique_cities[k], unique_cities[j], matrix[k][j], matrix[i][k], matrix[i][j]);
				}
			}
		}
	}

	return route_list;
}



