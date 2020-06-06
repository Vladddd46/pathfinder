#include "pathfinder.h"

r_list *mx_create_route_node(char *start, char *middle, char *end, 
                            int s_distance, int m_distance, int e_distance) {
    r_list *node = (r_list *)malloc(sizeof(r_list));
    if (node == NULL) {
        char *msg  = "Malloc error\n";
        write(2, msg, (int)strlen(msg));
        exit(1);
    }
    node->s = start;
    node->m = middle;
    node->e = end;

    node->a = s_distance;
    node->b = m_distance;
    node->c = e_distance;

    node->next = NULL;
    return node;
}
