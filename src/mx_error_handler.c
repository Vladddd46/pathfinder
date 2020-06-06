#include "pathfinder.h"

/*
 * Checks, whether user`s input is valid.
 * 1. wrong number of arguments, while input.
 * 2. specified file does not exits.
 * 3. file is empty.
 * 4. invalid first line.
 * 5. invalid syntax in one`s line.
 * 6. invalid number of specified islands.
 * In case of invalid input, prints msg on stderr and exit programm.
 */

int mx_error_handler(int argc, char const *argv[]) {
    char *msg;

    if (mx_error_0(argc) == -1) {
        msg = "usage: ./pathfinder [filename]\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    else if (mx_error_1(argv) == -1) {
        msg = "error: file ";
        write(2, msg, mx_strlen(msg));
        msg = (char *)argv[1];
        write(2, msg, mx_strlen(msg));
        msg = " doesn't exist\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    else if (mx_error_2(argv) == -1) {
        msg = "error: file ";
        write(2, msg, mx_strlen(msg));
        msg = (char *)argv[1];
        write(2, msg, mx_strlen(msg));
        msg = " is empty\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    else if (mx_error_3(argv) == -1) {
        msg = "error: line 1 isn't valid\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    else if (mx_error_4(argv) < 0) {
        msg = "error: line ";
        write(2, msg, mx_strlen(msg));
        msg = mx_itoa((mx_error_4(argv) * -1) + 1);
        write(2, msg, mx_strlen(msg));
        msg = " isn't valid\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    else if (mx_error_5(argv) == -1) {
        msg = "error: invalid number of islands\n";
        write(2, msg, mx_strlen(msg));
        exit(1);
    }
    return 1;
}
