#include "pathfinder.h"

int main(int argc, char const *argv[]) {
    mx_error_handler(argc, argv);

    /*
     * Creating array of unique cities names. (Names of cities do not repeat)
     * 1. number of unique cities.
     * 2. init array.
     * 3. fill array.
     */
    int num_of_ucities = mx_number_of_unique_cities((char *)argv[1]);
    char *unique_cities[num_of_ucities + 1];
    mx_make_unique_cities_array((char *)argv[1], unique_cities);

    /*
     * Matrix initialization and
     * filling it with very big number.
     * PS. it is considered, that distance between cities
     * can not be further than 2000000000.
     * In canonical workflow, Floyd`s-Warshall algorithm suggests to use
     * infinity to mark unnkown pathes between cities.
     */
    int matrix[num_of_ucities][num_of_ucities];
    for (int i = 0; i < num_of_ucities; ++i) {
        for (int j = 0; j < num_of_ucities ; ++j)
            matrix[i][j] = 2000000000;
    }
    // Creating matrix with destinations between cities.
    mx_make_matrix((char *)argv[1], unique_cities, num_of_ucities, matrix);

    /*
     * Floyd`s - Warshall algorithm - searches the shortest distance between two cities.
     * Fills matrix with shortest pathes and also add each swap route into linked list in order to
     * restore path then.
     */
    r_list *route_list = mx_algorithm(num_of_ucities, matrix, unique_cities);

    /*
     * Sorting list of noted swaps(pathes) and deleting inappropriate nodes.
     * 1. init list.
     * 2. Deletes(Set variables to "NULL") repeated nodes (A->B == B->A)
     * 3. sorting by distance. (algorithm can firstly find short path, but later it can be found shorted => thus, save only the shortest pathes.)
     */
    r_list *new_route_list =  mx_create_route_node("NULL","NULL","NULL",0,0,0);
    mx_sort_route_list(route_list, new_route_list, unique_cities, num_of_ucities);
    mx_sort_route_list2(new_route_list);

    // Printing result on stdout.
    mx_output(num_of_ucities, matrix, unique_cities, new_route_list);
}
