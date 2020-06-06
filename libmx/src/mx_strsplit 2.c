#include "libmx.h"

static int get_word_length(const char *s, char c) {
 int word_length = 0;
 char *copy_s = (char *)s;

 while((*copy_s++ != c) && (*copy_s != '\0')) {
  word_length++;
 }
 return word_length;
}

char **mx_strsplit(const char *s, char c) {
 int words_count = 0;
 int word_length = 0;
 int i = 0;
 char **arr = NULL;

 if (!s) {
  return NULL;
 }
 words_count = mx_count_words(s, c);
 arr = (char **)malloc((words_count + 1) * sizeof(char *));
 while(*s && *s != '\0') {
  if (*s == c) {
   s++;
   continue;
  }
  word_length = get_word_length(s, c);
  arr[i] = mx_strnew(word_length);
  arr[i] = mx_strncpy(arr[i], s, word_length);
  s += word_length;
  i++;
 }
 arr[i] = NULL;
 return arr;
}


