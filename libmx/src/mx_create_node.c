#include "libmx.h"

t_list *mx_create_node(void *data){
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL) {
        char *msg = "Malloc error\n";
        write(2, msg, (int)strlen(msg));
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}
