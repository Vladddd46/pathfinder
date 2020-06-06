#include "libmx.h"

/* 
функция копирует связной список r_list list в r_list dst
*/

r_list *mx_copy_r_list(r_list *list)
{

	r_list *dst = mx_create_route_node("NULL", "NULL", "NULL",0,0,0);

	r_list *tmp = list;
	while (tmp)
	{
		if (mx_strcmp(tmp->s, "NULL") != 0)
		{
			mx_push_route_back(&dst, tmp->s, tmp->m, tmp->e, tmp->a, tmp->b, tmp->c);
		}
		tmp = tmp -> next;
	}

	return dst;
}



