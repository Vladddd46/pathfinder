/* Импорт Библиотек */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
/*=================*/

/* ---Структуры--- */
typedef struct s_list {
	void *data;
	struct s_list *next;
}   t_list;

typedef struct route_list {
	char *s; // start
	char *m; // middle
	char *e; // end
	int a;   // расстояние с города start в middle
	int b;   // расстояние с города middle до end
	int c;   // сумма расстояния
	struct route_list *next;
}   r_list;
/*=================*/




int mx_count_words(const char *str, char c);
void mx_foreach(int *arr, int size, void (*f)(int));
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
char *mx_nbr_to_hex(unsigned long nbr);
double mx_pow(double n, unsigned int pow);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_sqrt(int x);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
int mx_binary_search(char **arr, int size, const char *s, int *count);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_get_substr_index(const char *str, const char *sub);
char *mx_strstr(const char *haystack, const char *needle);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);
void mx_swap_char(char *s1, char *s2);
void mx_print_strarr(char **arr, const char *delim);
void mx_str_reverse(char *s);
int mx_get_char_index(const char *str, char c);
char *mx_strndup(const char *s1, size_t n);
char *mx_strdup(const char *str);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
int mx_count_substr(const char *str, const char *sub);
char **mx_strsplit(const char *s, char c);
t_list *mx_create_node(void *data);
int mx_list_size(t_list *list);
void mx_pop_back(t_list **head);
void mx_pop_front(t_list **head);
void mx_push_back(t_list **list, void *data);
void mx_push_front(t_list **list, void *data);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));
char *mx_strcpy(char *dst, const char *src);
void mx_del_strarr(char ***arr);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *mx_memset(void *b, int c, size_t len);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_realloc(void *ptr, size_t size);
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
void *mx_memmove(void *dst, const void *src, size_t len);
void mx_strdel(char **str);





/* !!!Pathfinder functions!!! */

/* Дополнительные функции */

int mx_isdigit(char s);
int mx_isalpha(char c);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_atoi(const char *s);



/* Алгоритм и создание матрицы */
void mx_elements_of_line(char *line, char *result[3]);
r_list *mx_algorithm(int num_of_cities, int matrix[num_of_cities][num_of_cities], char **unique_cities);
/*=================*/

/* output */
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
void mx_array_recursion_editor(r_list *list, int num_of_cities, char *array[num_of_cities], int arr_int[num_of_cities], int pure_arr_int[num_of_cities]);//функция, которая рекурсивно редактирует путь
/*=================*/

/* files */
char *mx_first_line_reader(char *str);
/*=================*/

/* lists */
int mx_list_value_validator(t_list **list, void *data);
r_list *mx_create_route_node(char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_push_route_back(r_list **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_push_route_front(r_list **list, char *start, char *middle, char *end, int s_distance, int m_distance, int e_distance);
void mx_sort_route_list(r_list *list, r_list *new_list, char **unique_cities, int num_of_cities);
void mx_sort_route_list2(r_list *new_route_list);
int mx_is_in_list(r_list *list, char *start, char *end); // проверяет наличие ноды с start и end в связном списке
r_list *mx_copy_r_list(r_list *list); //копирует связной список
r_list *mx_r_list_reverse(r_list *list); // переворачивает связной список
/*=================*/



/* Error Handling */
int mx_error_handler_module(int argc, char const *argv[]); // обрабатывает ошибки
int mx_error_0(int argc); // количество переданных аргументов
int mx_error_1(char const *argv[]); // существует ли данный файл
int mx_error_2(char const *argv[]); //пустой ли файл
int mx_error_3(char const *argv[]); //содержит ли первая строка недопустимые символы
int mx_error_4(char const *argv[]); //неправильный формат строки
int mx_error_5(char const *argv[]); // неправильное количество городов 
/*=================*/
