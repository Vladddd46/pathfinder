#include "pathfinder.h"

// Pushes the route from start to end city through middle city.
void mx_push_route_front(r_list **list, char *start, char *middle, char *end, 
                         int s_distance, int m_distance, int e_distance) {
    r_list *node = (r_list *)malloc(sizeof(r_list));
    if (node == NULL) {
        char *msg = "Malloc Error\n";
        write(2, msg, (int)strlen(msg));
        exit(1);
    }
    node->s = start;
    node->m = middle;
    node->e = end;
    
    node->a = s_distance;
    node->b = m_distance;
    node->c = e_distance;

    node->next = (*list);
    (*list ) = node;
}
