#include "libmx.h"

t_list *mx_create_node(void *data){

	//выделяю память под узел и привожу к нужному типу данных
	t_list *node = malloc(sizeof(t_list));

	node->data = data;
	node->next = NULL;


	return node;
}


