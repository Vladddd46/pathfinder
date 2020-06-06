#include "pathfinder.h"

/*
Функция проверяет есть значение data в list
*/

int mx_list_value_validator(t_list **list, void *data)
{
	t_list *x = *list;
	while (x -> next)
	{
		if (mx_strcmp(x -> data, data) == 0)
		{
			return -1;
		}
		x = x -> next;
	}

	if (mx_strcmp(x -> data, data) == 0)
	{
			return -1;
	}

	return 0;	
}

