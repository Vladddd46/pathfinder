#include "libmx.h"

int mx_list_size(t_list *list)
{

	if (list == NULL){
		return -1;
	}

	int size = 0;

	while (list->next!= NULL){
		list = list->next;
		size++;
	}
	size++;

	return size;
}




