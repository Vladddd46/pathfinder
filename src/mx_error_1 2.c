#include "pathfinder.h"

// Checks, whether file exists.
int mx_error_1(char const *argv[]) {
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        close(fd);
        return fd;
    }
    close(fd);
    return 1;
}
