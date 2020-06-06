#include "pathfinder.h"

/*
 * Fills array <unique_cities> with cities names.
 * Cities do not repeat.
 */
void mx_make_unique_cities_array(char *file_name, char **unique_cities) {
    char *file_data = mx_file_to_str(file_name);

    // Freeing array with space ' ' in order to keep only cities in it.
    for (int i = 0; i < mx_strlen(file_data); ++i) {
        if (mx_isalpha(file_data[i]) == -1)
            file_data[i] = ' ';
    }
    // Fill array with name of cities. (names can repeat) 
    char **un_unique_cities = mx_strsplit(file_data, ' ');
    
    // Change repeated names with "deleted" word.
    for (int i = 0; un_unique_cities[i + 1] != NULL; ++i) {
        for (int j = i + 1; un_unique_cities[j] != NULL; ++j) {
            if (mx_strcmp(un_unique_cities[i],un_unique_cities[j]) == 0)
                un_unique_cities[j] = "deleted";
        }
    }
    /*
     * Fill unique_cities array with names from un_unique_cities,
     * excluding "deleted".
     */
    int index = 0;
    for (int i = 0; un_unique_cities[i] != NULL; ++i) {
        if (mx_strcmp(un_unique_cities[i], "deleted") != 0) {
            unique_cities[index] = un_unique_cities[i];
            index++;
        }
    }
    unique_cities[index] = NULL;
}
