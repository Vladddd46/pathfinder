#include "libmx.h"

char *mx_itoa(int number)
{
	if(number == -2147483648){
		char *result = mx_strnew(11);
		result = "-2147483648";
		return result;
	}
	if(number == 0) {
		char *result = mx_strnew(1);
		result[0] = '0';
		return result;
	}
	long number2 = number;
	if(number < 0) {
		number2 *= -1;
	}
	int len = 0;
	while(number2 != 0){
		number2 = number2/10;
		len++;
	}
	if(number < 0) {
		len++;
	}
	char *result = mx_strnew(len);
	if(number < 0) {
		result[0] = '-';
		number *= -1;
	}
	while(number != 0){
		result[len - 1] = number % 10 + 48;
		number = number / 10;
		len--;
	}
	return result;
}
