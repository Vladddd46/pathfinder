#include "libmx.h"

//ВСЕ РАБОТАЕТ КОРРЕКТНО! НИЧЕГО НЕ ТРОГАЙ!!!!!!!!!!

/* функция делит строку на 3 части по делиметрам '-' , ',' 
arr[0] == city1;
arr[1] == city2;
arr[2] == distance;
*/

void mx_elements_of_line(char *line, char *result[3])
{
	int i = 0;
	int index = 0;
	int delim1_index;
	int delim2_index;
	while (line[i])
	{
		if (line[i] == '-')
		{
			delim1_index = i;
			char *word = mx_strnew(i);
			int tmp1 = 0;
			while(line[tmp1] != '-')
			{
				word[tmp1] = line[tmp1];
				tmp1++;
			}
			result[index] = word;
			index++;
		}
		else if (line[i] == ',')
		{
			delim2_index = i;
			char *word = mx_strnew(i - (delim1_index + 1));
			int tmp2 = delim1_index + 1;
			int x = 0;
			while(line[tmp2] != ',')
			{
				word[x] = line[tmp2];
				x++;
				tmp2++;
			}
			result[index] = word;
			index++;
		}
		else if (mx_isdigit(line[i]) != -1)
		{
			int tmp3 = delim2_index + 1;
			int len = 0;
			while(line[delim2_index])len++, delim2_index++;
			char *word = mx_strnew(len);
			int y = 0;
			while(line[tmp3])
			{
				word[y] = line[tmp3];
				y++;
				tmp3++;
			}
			result[index] = word;
			index++;
		}
		i++;
	}
}



