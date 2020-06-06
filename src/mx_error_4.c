#include "pathfinder.h"

// If the last line will not end by the new_line.
int mx_bundage(const char *file) {
    char *file_data = mx_file_to_str(file);
    if (file_data[mx_strlen(file_data)-1] != '\n') {
        char *file_data2 = mx_strnew(mx_strlen(file_data)+1);
        int j = 0;
        while(file_data[j]) {
            file_data2[j] = file_data[j];
            j++;
        }
        file_data2[j] = '\n';
        char **lines = mx_strsplit(file_data2, '\n');
        int i = 0;
        while(lines[i])
            i++;
        return -i+1;
    }
    return 0;
}

/* 
 * Checks, whether syntax of input is valid.
 * In case of finding line with invalid syntax,
 * returns number_of_invalid_line * -1
 */
int mx_error_4(char const *argv[]) {
    int bundage = mx_bundage(argv[1]);
    if (bundage < 0)
        return bundage;

    char *file_data = mx_file_to_str(argv[1]);
    char **line = mx_strsplit(file_data, '\n');

   /* 
    * Walking through each line and checking if line is valid.
    * PS. start from 1st. line.
    */
    int i = 1;
    while (line[i]) {
        int dash = 0;
        int comma = 0;
        for (int j = 0; j < mx_strlen(line[i]); ++j) {
            if (comma == 0 && line[i][j] != '-' && line[i][j] != ',') {
                if (mx_isalpha(line[i][j]) == -1)
                    return -i;
            }
            else if (comma == 1 && line[i][j] != '-' && line[i][j] != ',') {
                if (mx_isdigit(line[i][j]) == -1)
                    return -i;
            }

            if (line[i][j] == '-')
                dash++;
            else if (line[i][j] == ',')
                comma++;
        }

        if (dash != 1 || comma != 1)
            return -i;
        i++;
    }
    return 0;
}
