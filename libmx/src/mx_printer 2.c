#include "libmx.h"

/*
функция для вывода, на случай, если между городами
есть прямая связь
*/

void mx_printer(char *s, char *e, int result)
{	

	char *path = "Path: ";
	char *arrow = " -> ";
	write(1,path,mx_strlen(path));
	write(1,s,mx_strlen(s));
	write(1,arrow,mx_strlen(arrow));
	write(1,e,mx_strlen(e));
	write(1,"\n",1);

	char *route = "Route: ";
	write(1,route,mx_strlen(route));
	write(1,s,mx_strlen(s));
	write(1,arrow,mx_strlen(arrow));
	write(1,e,mx_strlen(e));
	write(1,"\n",1);

	char *distance = "Distance: ";
	write(1,distance,mx_strlen(distance));
	char *r = mx_itoa(result);
	write(1,r,mx_strlen(r));
	write(1,"\n",1);
	

}



