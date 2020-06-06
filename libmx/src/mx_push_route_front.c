#include "libmx.h"

void mx_push_route_front(r_list **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance)
{

	r_list *node = malloc(sizeof(r_list));
	
	node->s = start;
	node->m = middle;
	node->e = end;
	
	node->a = s_distance;
	node->b = m_distance;
	node->c = e_distance;

	node->next = (*list);
	(*list ) = node;
}
