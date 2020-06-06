#include "libmx.h"

char *mx_del_extra_spaces(const char *str)  {
    if(str == NULL) return NULL;
    char *modified_str = mx_strtrim(str);
    int tmp = 0;
    while (modified_str[tmp]) {
        if ((modified_str[tmp] >= 9 && modified_str[tmp] <= 13) || modified_str[tmp] == 32)
        modified_str[tmp] = ' ';
        tmp++;
    }
    int num_of_words = mx_count_words(modified_str, ' ');
    int tmp2 = 0;
    int needed_memory = 0;
    while (modified_str[tmp2]) {
        if (modified_str[tmp2] != ' ')
            needed_memory++;
        tmp2++;
    }
    char *returned_str = mx_strnew(needed_memory + (num_of_words - 1));
    int tmp3 = 1;
    returned_str[0] = modified_str[0];
    for (int i = 1; i < mx_strlen(modified_str); ++i) {
        if (modified_str[i] == ' ' && modified_str[i-1] != ' ') {
            returned_str[tmp3] = modified_str[i];
            tmp3++;
        }
        else if(modified_str[i] != ' ') {
            returned_str[tmp3] = modified_str[i];
            tmp3++;
        }
    }
    free(modified_str);
    modified_str = NULL;
    return returned_str;
}
