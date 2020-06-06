#include "pathfinder.h"

r_list *mx_r_list_reverse(r_list *list)
{
	r_list *empty_list = mx_create_route_node("NULL","NULL","NULL",0,0,0);

	r_list *tmp = list;
	while(tmp)
	{
		mx_push_route_front(&empty_list, tmp->s, tmp->m, tmp->e, tmp->a, tmp->b, tmp->c);
		tmp = tmp->next;
	}

	r_list *returned_list = mx_copy_r_list(empty_list);


	return returned_list;
}

