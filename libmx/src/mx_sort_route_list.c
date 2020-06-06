#include "libmx.h"

/*
Эта функция приводит список путей к городам к нужному для вывода виду
если  route_list->s > unique_cities[i] => меняем их местами (route_list->s <=> route_list->e)
таким образом у нас получится отсортированный для вывода список, но с повторениями и путями, которые
не являются наименьшими.
Дальнейшее привидение списка к нужному виду реализовано в функции mx_sort_route_list2
*/


void mx_sort_route_list(r_list *list, r_list *new_list, char **unique_cities, int num_of_cities)
{
	
	r_list *tmp = list;

 	for (int i = 0; i < num_of_cities; ++i)
 	{
 		r_list *tmp2 = tmp;
 		while(tmp2)
 		{
 			if (mx_strcmp(tmp2->s, unique_cities[i]) == 0)
 			{
 				mx_push_route_back(&new_list, tmp2->s, tmp2->m, tmp2->e, tmp2->a, tmp2->b, tmp2->c);
 				tmp2 -> s = "NULL";
 				tmp2 -> e = "NULL";
 			}
 			else if (mx_strcmp(tmp2->e, unique_cities[i]) == 0)
 			{
 				mx_push_route_back(&new_list, tmp2->e, tmp2->m, tmp2->s, tmp2->a, tmp2->b, tmp2->c);
 				tmp2 -> s = "NULL";
 				tmp2 -> e = "NULL";
 			}
 			tmp2 = tmp2->next;
 		}
 	}
 }



 

