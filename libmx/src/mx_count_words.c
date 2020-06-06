#include "libmx.h"

int mx_count_words(const char *str, char c) {
	if(str == NULL) {
		return -1;
	}
	int i = 0;
	int count = 1;
	if(str[0] == c) {
		count--;
	}
	while(str[i] != '\0') {
		if(str[i + 1] == '\0' && str[i] == c) {
			count--;
		}
		if(str[i] == c && str[i + 1] != c) {
			count++;
		}
		i++;
	}
	return count;
}
