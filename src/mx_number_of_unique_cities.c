#include "pathfinder.h"

/*
 * Finds number of unique cities in file.
 * In short, just takes number, user specified in first line,
 * changes it to integer type and returns.
 */
int mx_number_of_unique_cities(char *argv) {
    char *data = mx_file_to_str(argv);
    int len = 0;
    while (data[len] != '\n') len++;

    char x[len];
    int i = 0;
    while (i != len) {
        x[i] = data[i];
        i++;
    } 
    x[i] = '\0';
    int num_of_ucities = mx_atoi(x);
 
    return num_of_ucities;
}
