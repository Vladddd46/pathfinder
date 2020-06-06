#include "libmx.h"

//функция извлекает из файла данные и создает список уникальных городов
void mx_make_unique_cities_array(char *file_name, char **unique_cities)
{

	//помещаю данные из файла в строку;
	char *file_data = mx_file_to_str(file_name);
	//чищу массив от ненужных символов (оставляю только названия городов)
	for (int i = 0; i < mx_strlen(file_data); ++i)
	{
		if (mx_isalpha(file_data[i]) == -1)
		{
			file_data[i] = ' ';
		}
	}
	//делая массив и всех городов в файле(города повторяются!)
	char **ununique_cities = mx_strsplit(file_data, ' ');
	//меняю города,которые повторяются, на deleted и впоследствии чищу их
	for (int i = 0; ununique_cities[i + 1] != NULL; ++i)
	{
		for (int j = i + 1; ununique_cities[j] != NULL; ++j)
		{
			if (mx_strcmp(ununique_cities[i],ununique_cities[j]) == 0)
			{
				ununique_cities[j] = "deleted";
			}
		}
	}
	//считаю длинну для массива с уникальными городами
	int q = 0;
	int len_of_array_with_unique_cities = 0;
	while (ununique_cities[q] != NULL)
	{
		if (mx_strcmp(ununique_cities[q], "deleted") != 0)
		{
			len_of_array_with_unique_cities++;
		}
		q++;
	}
	//массив с уникальными городами
	//unique_cities[len_of_array_with_unique_cities];
	//выбираю уникальные города из ununique_citiesue cities и помещаю в unique cities
	int index = 0;
	 for (int i = 0; ununique_cities[i] != NULL; ++i)
	 {
	 	if (mx_strcmp(ununique_cities[i], "deleted") != 0)
	 	{
	 		unique_cities[index] = ununique_cities[i];
	 		index++;
	 	}
	}
	unique_cities[index] = NULL;
}






