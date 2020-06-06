#include "pathfinder.h"

// File is empty.
int mx_error_2(char const *argv[]) {
    char buff[1];
    int fd = open(argv[1], O_RDONLY);
    int len = 0;

    while (read(fd, buff, 1))
        len++;
    close(fd);
    if (len == 0)
        return -1;
    return 0;
}
