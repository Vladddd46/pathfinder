#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2){
	while (s1 && s2){
		int len_s1 = mx_strlen(s1);
		int len_s2 = mx_strlen(s2);
		int length = len_s1 + len_s2;
		char *concatenated_str = mx_strnew(length);
		int i = 0;
		while (s1[i]){
			concatenated_str[i] = s1[i];
			i++;}
		int j = 0;
		while (s2[j]){
			concatenated_str[i] = s2[j];
			j++;
			i++;}
		return concatenated_str;}
	if (s1){
		return (char *)s1;}
	else if (s2){
		return (char *)s2;}
	return NULL;}



