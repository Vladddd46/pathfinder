#include "pathfinder.h"

void mx_big_array_printer(int num_of_cities, char *array[num_of_cities],  int arr_int[num_of_cities]){
    mx_array_garbager(num_of_cities,  arr_int); 
    mx_printstr("========================================\n");

    char *path = "Path: ";
    char *arrow = " -> ";
    write(1,path,mx_strlen(path));

    char *begin = array[0];
    write(1,begin,mx_strlen(begin));

    write(1,arrow,mx_strlen(arrow));
    int end = 0;
    for (; array[end] != NULL; end++);
    char *end_elem = array[end-1];
    write(1,end_elem,mx_strlen(end_elem));
    write(1,"\n",1);

    char *route = "Route: ";
    write(1,route,mx_strlen(route));
    for (int i = 0; array[i] != 0; ++i) {
        write(1, array[i], mx_strlen(array[i]));
        if (array[i+1] != 0)
            write(1," -> ", 4);
    }
    write(1,"\n",1);

    char *distance = "Distance: ";
    write(1,distance,mx_strlen(distance));
        
    for (int i = 0; arr_int[i] != 0; ++i) {
        char *print = mx_itoa(arr_int[i]);
        write(1,print, mx_strlen(print));
        if (arr_int[i+2] == 0) {
            write(1," = ", 3);
            char *p = mx_itoa(arr_int[i+1]);
            write(1,p, mx_strlen(p));
            break;
        }
        else 
            write(1, " + ", 3);
            
    }
    write(1,"\n",1);
    mx_printstr("========================================\n");
}
