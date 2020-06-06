#include "pathfinder.h"

// Checks, wheather node has node->s and node->e
int mx_is_in_list(r_list *list, char *start, char *end) {
    r_list *tmp = list;
    while (tmp) {
        if (mx_strcmp(tmp->s, start) == 0 && mx_strcmp(tmp->e, end) == 0)
            return 1;
        tmp = tmp -> next;
    }
    return 0;
}
