#include "libmx.h"

int mx_isdigit(char s) {
    if (s >= 48 && s <= 57)
        return 1;
    return -1;
}
