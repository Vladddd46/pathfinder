#include "libmx.h"

void mx_push_back(t_list **list, void *data){

	if (list == NULL)
	{
		return;
	}



	//выделяю память под узел и привожу к нужному типу данных
	t_list *node = mx_create_node(data);
	if (*list == NULL)
	{	
		*list = node;
		return;
	}

	//иду по связному списку до самого конечного элемента
	t_list *last_element = *list;
	while (last_element->next != NULL){
		last_element = last_element->next;
	}

	//добавляю новый узел в конец
	last_element->next = node;
}

