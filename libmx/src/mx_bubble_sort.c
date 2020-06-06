#include "libmx.h"

int mx_bubble_sort(char **arr, int size){
		
     int counter = 0;
     //size*size максимально возможное количество перестановок
     //с двойным for у меня неправильно считало counter
     int access = size * size;

     while(access){
         for (int i = 0; i < size - 1; ++i){
	    if (mx_strcmp(arr[i],arr[i+1]) > 0)
		{
		    char *tmp = arr[i];
		    arr[i] = arr[i+1];
		    arr[i+1] = tmp;
		    //считаем количество перестановок
	            counter++;
		}
	}
	access--;
	}

	return counter;
}



