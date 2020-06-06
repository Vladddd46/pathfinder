#include "pathfinder.h"

int main(int argc, char const *argv[]) {
	mx_error_handler(argc, argv);

  /*
   * Creating array of unique cities names. (Names of cities do not repeat)
   * 1. number of unique cities.
   * 2. init array.
   * 3. fill array.
   */
  int num_of_ucities = mx_number_of_unique_cities((char *)argv[1]);
 	char *unique_cities[num_of_ucities + 1];
 	mx_make_unique_cities_array((char *)argv[1], unique_cities);

	
	
	/* инициализация матрицы */
  	int matrix[num_of_ucities][num_of_ucities];
  	//заполняю матрицу максимальным значением 
 	for (int i = 0; i < num_of_ucities; ++i)
 	{
 		for (int j = 0; j < num_of_ucities ; ++j)
  		{
  			matrix[i][j] = 10000;
  		}
  	}
  	//создаю смежную матрицу расстояний
  	mx_make_matrix((char *)argv[1], unique_cities, num_of_ucities, matrix);
  	/*==================*/



  	/* Алгоритм Флойда */
  	//- находит кратчайшие расстояния между всема данными городами
  	//- функция алгоритма возвращает поинтер на связной список, в котором записаны свапы городов
  	r_list *route_list = mx_algorithm(num_of_ucities, matrix, unique_cities);
  	/*==================*/



  /* Сортировка route_list */
  //(список путей с города A в город C через B город)
	r_list *new_route_list =  mx_create_route_node("NULL","NULL","NULL",0,0,0);    // создаю связной список с нулевой нодой -> туда записываю отсортированный список1
 	mx_sort_route_list(route_list, new_route_list, unique_cities, num_of_ucities); // первая сортировка (принцип ее работы описан в самой функции)
	mx_sort_route_list2(new_route_list); // вторая и послудняя сортировка (принцип ее работы описан в файле функции)
 	/*==================*/


  /* Вывод в stdout */
  mx_output(num_of_ucities, matrix, unique_cities, new_route_list);
  /*==================*/

}












