#include "libmx.h"

void mx_push_back(t_list **list, void *data){

    if (list == NULL)
        return;

    t_list *node = mx_create_node(data);
    if (*list == NULL) {    
        *list = node;
        return;
    }

    t_list *last_element = *list;
    while (last_element->next != NULL)
        last_element = last_element->next;
    last_element->next = node;
}
