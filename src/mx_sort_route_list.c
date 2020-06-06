#include "pathfinder.h"

/*
 * Deletes repeated nodes. (change their values to "NULL")
 * A->B is the same as B->A
 */
void mx_sort_route_list(r_list *list, r_list *new_list, char **unique_cities, int num_of_cities) {
    
    r_list *tmp = list;

    for (int i = 0; i < num_of_cities; ++i) {
        r_list *tmp2 = tmp;
        while(tmp2) {
            if (mx_strcmp(tmp2->s, unique_cities[i]) == 0) {
                mx_push_route_back(&new_list, tmp2->s, tmp2->m, tmp2->e, tmp2->a, tmp2->b, tmp2->c);
                tmp2 -> s = "NULL";
                tmp2 -> e = "NULL";
            }
            else if (mx_strcmp(tmp2->e, unique_cities[i]) == 0) {
                mx_push_route_back(&new_list, tmp2->e, tmp2->m, tmp2->s, tmp2->a, tmp2->b, tmp2->c);
                tmp2 -> s = "NULL";
                tmp2 -> e = "NULL";
            }
            tmp2 = tmp2->next;
        }
    }
 }
