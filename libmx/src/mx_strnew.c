#include "libmx.h"

char *mx_strnew(const int size) {
    char *memory = malloc(size + 1);

    if (memory == NULL) {
        char *msg = "Malloc error\n";
        write(2, msg, (int)strlen(msg));
        exit(1);
    }
    for (int i = 0; i < size + 1; i++)
        memory[i] = '\0';
    return memory;
}
