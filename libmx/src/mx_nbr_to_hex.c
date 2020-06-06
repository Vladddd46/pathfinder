#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr){
 
	//просто перемещаю переменную для дальнейшей работы.
	unsigned long number = nbr;

	// кейс с нулем
	if (number == 0){
		char *p = mx_strnew(1);
		p[0] = 48;
		return p;
	}

	/*Данный блок кода считает количиство цифер в числе
	1023 - в данном числе, количество цифер = 4
	123 - количество цифер = 3
	PS это нужно для того, чтобы выделить память для массива, который
	будет хранит hex-number
	*/
	unsigned long length_number = 0;
	unsigned long tmp = number;
	while(tmp != 0){
		tmp /= 16;
		length_number++;
	}


	/*
	Выделяем память для хранения hex-number. 
	length_number - количество цифер в числе
	*/
	char *arr = mx_strnew(length_number);

	/*
	алгоритм перевода из десятичной в шестнадцатиричную
	-> google
	*/
	for (unsigned long i = 0; number != 0; ++i, length_number--)
	{
		unsigned long rest = number % 16;
		number /= 16;
		if ( rest > 9 && rest < 16){
			arr[length_number-1] = rest + 87;
		}
		else if ( rest >= 0 && rest <= 9){
			arr[length_number-1] = rest + 48;
		}
	}


	return arr;
}


	 
