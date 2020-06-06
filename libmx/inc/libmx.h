#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

typedef struct s_list {
	void *data;
	struct s_list *next;
}   t_list;


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

