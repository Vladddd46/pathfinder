#include "pathfinder.h"

/* 
Данная функция создает узел связного списка
в узле хранится путь из пункта start в путь end через middle
*/ 

r_list *mx_create_route_node(char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance)
{
	//выделяю память под узел и привожу к нужному типу данных
	r_list *node = malloc(sizeof(r_list));

	node->s = start;
	node->m = middle;
	node->e = end;

	node->a = s_distance;
	node->b = m_distance;
	node->c = e_distance;

	node->next = NULL;

	return node;
}


