//
// Created by 27756 on 2022/11/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len 1000

void mystrcat(char *str1, char *str2);

int main() {
  int n;
  scanf("%d", &n);

  char *str1 = malloc(len * sizeof(*str1));
  char *str2 = malloc(len * sizeof(*str2));

  for (int i = 0; i < n; ++i) {
	scanf("%s", str1);
	scanf("%s", str2);
	mystrcat(str1, str2);
  }

  free(str1);
  free(str2);

  return 0;
}

void mystrcat(char *str1, char *str2) {
  int len1 = strlen(str1), len2 = strlen(str2);
  for (int i = (len1 > len2 ? 0 : len2 - len1); i < len2; ++i) {
	if (!strncmp(str1 + i + len1 - len2, str2, len2 - i)) {
	  strcat(str1, str2 + len2 - i);
	  puts(str1);

	  return;
	}
  }
  strcat(str1, str2);
  puts(str1);

  return;
}

