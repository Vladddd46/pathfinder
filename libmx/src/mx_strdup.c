#include "libmx.h"

char *mx_strdup(const char *str){
    if (str == NULL)
        return NULL;
    unsigned long length = mx_strlen(str);
    char *memory = mx_strnew(length);
    char *p = mx_strcpy(memory, str);
    return p;
}

