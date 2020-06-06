#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){

	if (str == NULL || sub == NULL || replace == NULL)
	{
		return NULL;
	}
	if (mx_strcmp(str, "") == 0 || mx_strcmp(sub, "") == 0 || mx_strcmp(replace, "") == 0)
	{
		return NULL;
	}


	//длинна str,sub,replace
	int len_str = mx_strlen(str);	
	int len_sub = mx_strlen(sub);
	int len_replace = mx_strlen(replace);

	//на случай, если sub и replace имеют различную длинну
	int difference = len_replace - len_sub;
	int number_of_substr = mx_count_substr(str,sub);
	int difference_in_memory = difference * number_of_substr;

	//выделяю память под строку, которую верну впоследствии
	char *new_str = mx_strnew(len_str + difference_in_memory);

	//алгоритм замены
	int str_step = 0;
	int end_of_new_str = 0;
	while(str[str_step]){
		//совпадение i-елемента str и нулевого елемента sub
		if (str[str_step] == sub[0])
		{
			//цикл, который проверяет дальнейшую схожесть символов
			int j = 0;
			int tmp = str_step;
			while (str[tmp] == sub[j]){
				//строка sub найдена в str - делаем добавляем replace в new_str и перескакиваем (str_step) на длинну sub
				if (j == len_sub - 1)
				{
					int repl = 0;
					while(replace[repl])
					{
						new_str[end_of_new_str] = replace[repl];
						repl++;
						end_of_new_str++;
					} 
					str_step += len_sub;
				}
				j++;
				tmp++;
			}
		}
		else
		{
		new_str[end_of_new_str] = str[str_step];
		end_of_new_str++;
		str_step++;
		}
	}
	return new_str;
}

