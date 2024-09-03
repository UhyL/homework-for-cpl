//
// Created by 27756 on 2022/11/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  len 100000

int main() {
  int true_len;
  char *str = malloc(len * sizeof(*str));

  gets(str);
  true_len = strlen(str);

  for (int i = 0; i < true_len; ++i) {
	if (*(str + i) >= 97) {
	  *(str + i) = *(str + i) - 32;
	}

	for (int j = i + 1; j < true_len; ++j) {
	  if(*(str + j) == 32 ) {
		i = j ;
		break;
	  } else if (*(str+ j) < 97) {
		*(str + j) = *(str + j) + 32;
		i = j;
	  } else {
		i = j;
	  }
	}
  }

  printf("%s", str);

  free(str);

  return 0;

}

