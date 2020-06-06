#include "libmx.h"

char *mx_strtrim(const char *str){

	if (str == NULL)
	{
		return NULL;
	}


	//i -  первый элемент с которого начинается строка(с помощью цикла исключаем  whitespace characters)
	int i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32){
		i++;
	}


	//j - последний элемент, которым заканчивается срока(с помощью цикла исключаем  whitespace characters)
	int len_str = mx_strlen(str);
	int j = len_str - 1;
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == 32){
		j--;
	}

	//считаю количество памяти, которую надо выделить под новую строку
	int len_new_str = 0;
	int tmp = i;
	for (; tmp <= j; ++tmp)
	{
		len_new_str++;
	}

	//выделяю память и заполняю строкой
	char *memory = mx_strnew(len_new_str);
	if (memory == NULL){
		return NULL;
	}

	//заполняю новую строку нужными значениями
	int q = 0;
	while (q < len_new_str){
		memory[q] = str[i];
		i++;
		q++;
	}


	str = NULL;
	
	return memory;
}





