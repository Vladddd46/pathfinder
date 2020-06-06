#include "pathfinder.h"

// Inserts in array insert_element_1 and insert_element_2 by insert_index and insert_index + 1.
void mx_int_array_extender(int num_of_cities, int array[num_of_cities], 
                           int insert_element_1, int insert_element_2, int insert_index) {
    int i = num_of_cities - 2;

    for (; i >= insert_index; i--)
        array[i + 1] = array[i];
    array[i+1] = insert_element_1;

    int j = num_of_cities - 2;
    for (; j >= insert_index + 1; j--)
        array[j + 1] = array[j];
    array[j+1] = insert_element_2;
    for (int i = j+2; i < num_of_cities + 1; ++i)
        array[i] = array[i+1];
}
