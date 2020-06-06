#include "libmx.h"

void mx_pop_front(t_list **head){

	if (head == NULL || *head == NULL)
	{
		return;
	}

	t_list *node_to_delete = *head;
	*head = node_to_delete->next;

	// зачищаю память
	node_to_delete->next = NULL;
	node_to_delete -> data = NULL;
	free(node_to_delete);
	node_to_delete = NULL;
}

