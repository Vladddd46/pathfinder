#include "pathfinder.h"

void mx_output(int num_of_cities, int matrix[num_of_cities][num_of_cities], char **unique_cities, r_list *list) {

    // Going through each element in unique_cities.
    int j_step = 1;
    for (int i = 0; i < num_of_cities; ++i) {
        for (int j = j_step; j < num_of_cities; ++j) {      
             if(mx_is_in_list(list,unique_cities[i], unique_cities[j])) {
                char *arr[num_of_cities + 1];
                // fill array with NULL.
                int filler = 0;
                while (filler < num_of_cities + 1) {
                    arr[filler] = NULL;
                    filler++;
                }
                // Array, where distances between cities will store.
                int arr_int[num_of_cities];
                for (int i = 0; i < num_of_cities; ++i) arr[i] = NULL;
                mx_array_filler(num_of_cities + 1, arr, arr_int, list, unique_cities[i], unique_cities[j]);
                int was_recursed = 0;
                mx_outer_array_recursion_editor(list, num_of_cities + 1, arr, arr_int, was_recursed);
                
             }
             else {
                int res = matrix[i][j];
                mx_printstr("========================================\n");
                mx_printer(unique_cities[i], unique_cities[j], res);
                mx_printstr("========================================\n");
             }
        }
        j_step++;
    }
}
