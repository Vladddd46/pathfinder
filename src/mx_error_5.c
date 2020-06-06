#include "pathfinder.h"

/*
 * This error case checks, wheather number of islands, 
 * specified in 1st. line, is valid.
 */
int mx_error_5(char const *argv[]) {
    char *file_data = mx_file_to_str(argv[1]);
    char *input_data = mx_first_line_reader(file_data); 
    // Change all 'non-city' symbols with '-' -> it is needed to use strsplit.
    int i = 0;
    while (file_data[i]) {
        if (file_data[i] == ',' || file_data[i] == '\n' ||  mx_isdigit(file_data[i]) != -1)
            file_data[i] = '-';
        i++;
    }
    // Retrieve cities.
    char **cities = mx_strsplit(file_data, '-');
    // Create list of unique cities.
    t_list *node = mx_create_node(cities[0]);
    for (int j = 1; cities[j] != NULL; ++j) {
        if (mx_list_value_validator(&node, cities[j]) != -1)
            mx_push_front(&node, cities[j]);
    }
    // Determine the length of list with unique cities.
    int number_of_cities = mx_list_size(node);
    // Compare values.
    if (mx_strcmp(input_data, mx_itoa(number_of_cities)) != 0)
        return -1;
    return 0;
}
