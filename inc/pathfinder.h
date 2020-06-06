#include "./libmx/inc/libmx.h"

/*
 * Structure, which describes found pathes from start city
 * to end city over middle city.
 */
typedef struct route_list {
	char *s; // Name of start city.
	char *m; // Name of middle city.
	char *e; // Name of end city.
	int a;   // Distance from start to middle.
	int b;   // Distance from middle to end.
	int c;   // Summ of distances.
	struct route_list *next;
}   r_list;

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
void mx_elements_of_line(char *line, char *result[3]);
// Floyd`s-Warshall algorithm.
r_list *mx_algorithm(int num_of_cities, int matrix[num_of_cities][num_of_cities], char **unique_cities);

// Output the result.
void mx_output(int num_of_cities, int matrix[num_of_cities][num_of_cities], char **unique_cities, r_list *list);
void mx_printer(char *s, char *e, int result);
void mx_big_array_printer(int num_of_cities, char *array[num_of_cities],  int arr_int[num_of_cities]);
void mx_array_filler(int num_of_cities, char *arr[num_of_cities], int arr_int[num_of_cities], r_list *list, char *start, char *end);
void mx_array_editor(int num_of_cities, char *arr[num_of_cities], r_list *list);
void mx_array_extender(int num_of_cities, char *array[num_of_cities], char *insert_element, int insert_index);
void mx_int_array_extender(int num_of_cities, int array[num_of_cities], int insert_element_1, int insert_element_2, int insert_index);
void mx_array_garbager(int num_of_cities,  int arr_int[num_of_cities]);
void mx_array_printer(r_list *list, int num_of_cities, char *array[num_of_cities]);
void mx_outer_array_recursion_editor(r_list *list, int num_of_cities, char *array[num_of_cities], int arr_int[num_of_cities], int was_recursed);
void mx_array_recursion_editor(r_list *list, int num_of_cities, char *array[num_of_cities], int arr_int[num_of_cities], int pure_arr_int[num_of_cities]);

char *mx_first_line_reader(char *str);
int mx_list_value_validator(t_list **list, void *data);
r_list *mx_create_route_node(char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_push_route_back(r_list **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_push_route_front(r_list **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_sort_route_list(r_list *list, r_list *new_list, char **unique_cities, int num_of_cities);
void mx_sort_route_list2(r_list *new_route_list);
int mx_is_in_list(r_list *list, char *start, char *end);
r_list *mx_copy_r_list(r_list *list);
r_list *mx_r_list_reverse(r_list *list);
