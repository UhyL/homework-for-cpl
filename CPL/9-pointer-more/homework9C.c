//
// Created by 27756 on 2022/11/26.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define len 10000

int main() {
  char *str1 = malloc(len * sizeof(*str1));//用于储存输入的第一行字符串
  char *str2 = malloc(len * sizeof(*str2));//用于储存输入的第二行的单独一段
  char *str_special_word1 = malloc(len * sizeof(*str_special_word1));//用于存储后面带冒号的字符
  char *str_name = malloc(len * sizeof(*str_name));//用于保存程序名称的字符串
  char *str_print = malloc(len * sizeof(*str_print));//用于打印的字符串
  char *str_value = malloc(len * sizeof(*str_value));//用于储存需要参数的值

  scanf("%s", str1);
  int len_total = strlen(str1);//用于记录第一行输入字符串的长度
  int len_special_word1 = 0;//用于记录后面带冒号的字符的个数
  int count = 0;//用于记录需要打印的字符穿的大小

  for (int i = 1; i < len_total; ++i) {
	if (*(str1 + i) == ':') {
	  *(str_special_word1 + len_special_word1) = *(str1 + i - 1);
	  len_special_word1++;
	}
  }
  *(str_special_word1 + len_special_word1) = '\0';

  scanf("%s", str_name);

  while (scanf("%s", str2) != EOF) {
	if (*(str2) == '-') {
	  int judge = 0;
	  for (int i = 0; i < len_total; ++i) {
		if (*(str2 + 1) == *(str1 + i)) {
		  judge = 1;
		  for (int j = 0; j < len_special_word1; ++j) {
			if (*(str2 + 1) == *(str_special_word1 + j)) {
			  if (scanf("%s", str_value) != EOF) {
				judge = 3;
			  } else {
				judge = 2;
			  }
			  break;
			}
		  }
		}
	  }

	  switch (judge) {
		case 0 : {
		  printf("%s: invalid option -- '%c'", str_name, *(str2 + 1));
		  return 0;
		}
		case 1: {
		  *(str_print + count) = *(str2 + 1);
		  *(str_print + count + 1) = '\n';
		  count = count + 2;
		  break;
		}
		case 2: {
		  printf("%s: option requires an argument -- '%c'", str_name, *(str2 + 1));
		  return 0;
		}
		case 3: {
		  *(str_print + count) = *(str2 + 1);
		  *(str_print + count + 1) = '=';
		  int number = 1;//用来表示打印字符串增加的长度
		  for (int i = 0, j = count + 2; *(str_value + i) != '\0'; ++i, ++j) {
			*(str_print + j) = *(str_value + i);
			number++;
		  }
		  *(str_print + count + number + 1) = '\n';
		  count = count + number + 2;
		  break;
		}
	  }
	}
  }

  printf("%s\n", str_name);
  for (int i = 0; i < count; ++i) {
	printf("%c", *(str_print + i));
  }

  free(str2);
  free(str_print);
  free(str1);
  free(str_name);
  free(str_value);
  free(str_special_word1);
  return 0;
}
