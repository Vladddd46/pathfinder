#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle){

	//считаем длинну needle для того, чтобы
	//потом пройтись по ней цыклом
	int len_needle = mx_strlen(needle);

	
	int i = 0;
	//проходим по каждому символу haystack
	while(haystack[i]){

		//совпадение i-елемента haystack и нулевого елемента needle 
		if (haystack[i] == needle[0]){

			//цикл, который проверяет дальнейшую схожесть символов
			int j = 0;
			int tmp = i;
			while (haystack[tmp] == needle[j]){

				//строка needle найдена в haystack
				if (j == len_needle - 1){

					/*привидение типа к возвращаемому
					  функция должна возвращать char,
					  ,но haystack == const char
					*/
					char *p = (char *)&haystack[i];
					return p;
				}
				j++;
				tmp++;
			}
		}
		i++;
	}

	//возвращаем пустой поинтер, если needle не найден в haystack
	char *p = NULL;
	return p;
}









