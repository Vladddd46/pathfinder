#include "pathfinder.h"

/* функция рекурсивно печатает путь к городу C из A через x точки
-данная функция срабатывапет только в том случае: когда между A-X-C есть прямая связь
*/

void mx_array_printer(r_list *list, int num_of_cities, char *array[num_of_cities])
{
	//копия листа
	r_list *copy = mx_copy_r_list(list);
	//создаю копию массива
	char *tmp_arr[num_of_cities];
	for (int i = 0; i < num_of_cities; ++i)
	{
		tmp_arr[i] = array[i];
	}


	


	r_list *tmp = copy;
	while(tmp)
	{
		if (mx_strcmp(tmp_arr[0],tmp->s) == 0 && mx_strcmp(tmp_arr[2], tmp->e) == 0)
		{
			mx_printstr("========================================\n");
				
				char *path = "Path: ";
				char *arrow = " -> ";
				write(1,path,mx_strlen(path));
				write(1,tmp->s,mx_strlen(tmp->s));
				write(1,arrow,mx_strlen(arrow));
				write(1,tmp->e,mx_strlen(tmp->e));
				write(1,"\n",1);


				char *route = "Route: ";
				write(1,route,mx_strlen(route));
				write(1,tmp->s,mx_strlen(tmp->s));
				write(1,arrow,mx_strlen(arrow));
				write(1,tmp->m,mx_strlen(tmp->m));
				write(1,arrow,mx_strlen(arrow));
				write(1, tmp->e, mx_strlen(tmp->e));
				write(1,"\n",1);


				char *distance = "Distance: ";
				write(1,distance,mx_strlen(distance));
				char *a_distance = mx_itoa(tmp->a);
				write(1,a_distance, mx_strlen(a_distance));
				write(1," + ", 3);
				char *b_distance = mx_itoa(tmp->b);
				write(1,b_distance, mx_strlen(b_distance));
				write(1," = ", 3);
				char *r = mx_itoa(tmp->c);
				write(1,r,mx_strlen(r));
				write(1,"\n",1);
				
			mx_printstr("========================================\n");
		}
		tmp = tmp->next;
	}

}




