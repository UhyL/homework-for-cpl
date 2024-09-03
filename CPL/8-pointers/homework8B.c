//
// Created by 27756 on 2022/11/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 100000
int main() {
  int len1 = 0, len2 = 0, count = 1;
  char *str1 = malloc(len * sizeof(*str1));
  char *str2 = malloc(len * sizeof(*str2));
  gets(str1);
  gets(str2);

  len1 = strlen(str1);
  len2 = strlen(str2);

  for (int i = 0; i < len1; ++i) {
	for (int j = i, k =0; k < len2; ++j, ++k) {
	  if (*(str1 + j) != *(str2 + k)){
		count = 0;
		break;
	  }
	}
	if(count){
	  printf("%d ", i);
	}

	count = 1;
  }

  free(str1);
  free(str2);

  return 0;

}


