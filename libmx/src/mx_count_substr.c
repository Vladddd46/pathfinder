#include "libmx.h"

int mx_count_substr(const char *str, const char *sub){

	if (str == NULL || sub == NULL){
		return -1;
	}

	//считаем длинну needle для того, чтобы
	//потом пройтись по ней цыклом
	int len_sub = mx_strlen(sub);

	
	int i = 0;
	int counter = 0;
	//проходим по каждому символу str
	while(str[i]){

		//совпадение i-елемента str и нулевого елемента sub
		if (str[i] == sub[0]){

			//цикл, который проверяет дальнейшую схожесть символов
			int j = 0;
			int tmp = i;
			while (str[tmp] == sub[j]){

				//строка sub найдена в str
				if (j == len_sub - 1){
					counter++;
					break;
				}
				j++;
				tmp++;
			}
		}
		i++;
	}
	return counter;
}









