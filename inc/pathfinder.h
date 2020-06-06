#include "./libmx/inc/libmx.h"

// Input error handling.
int mx_error_handler(int argc, char const *argv[]);
int mx_error_0(int argc);
int mx_error_1(char const *argv[]);
int mx_error_2(char const *argv[]);
int mx_error_3(char const *argv[]);
int mx_error_4(char const *argv[]);
int mx_error_5(char const *argv[]);

// Creating matrix with destinations between cities.
int  mx_number_of_unique_cities(char *argv);
void mx_make_unique_cities_array(char *file_name, char **unique_cities);
void mx_make_matrix(char *file_name, char **unique_cities, 
					int num_of_cities, int matrix[num_of_cities][num_of_cities]);
