#include "pathfinder.h"

// Checks, whether first string contains invalid chars.
int mx_error_3(char const *argv[]) {
    char buff[1];
    int fd = open(argv[1], O_RDONLY);
    int checker = 0;

    while (read(fd, buff, 1)) {
        if (buff[0] == '\n')
            break;
        else if (mx_isdigit(buff[0]) == -1)
            return -1;
        checker++;
    }
    close(fd);
    
    if (checker == 0)
        return -1;
    return 0;
}
