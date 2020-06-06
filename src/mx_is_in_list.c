#include "pathfinder.h"

/* данная функция проверяет наличие узла node 
у которого 	node->s == start и 
			node->e == end
в  связном списке list
*/

int mx_is_in_list(r_list *list, char *start, char *end)
{
	r_list *tmp = list;
	while (tmp)
	{
		if (mx_strcmp(tmp->s, start) == 0 && mx_strcmp(tmp->e, end) == 0)
		{
			return 1;
		}
		tmp = tmp -> next;
	}

	return 0;
}






