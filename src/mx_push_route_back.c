#include "pathfinder.h"

void mx_push_route_back(r_list **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance)
{

	r_list *node = mx_create_route_node(start, middle, end, s_distance, m_distance, e_distance);

	//иду по связному списку до самого конечного элемента
	r_list *last_element = *list;
	while (last_element->next != NULL){
		last_element = last_element->next;
	}

	//добавляю новый узел в конец
	last_element->next = node;
}


