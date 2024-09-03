//
// Created by 27756 on 2022/11/14.
//
#include <stdio.h>

#define Stack_Size  100000

int contents[Stack_Size] = {0};
// 定义‘栈’

int first_item = 0;
//栈的顶部序号

void push(char i);
//执行入栈

void pop(void);
//执行出栈

int main() {
  int T = 0;
  scanf("%d", &T);
  getchar();

  char str[T][Stack_Size];

  for (int i = 0; i < T; ++i) {
	scanf("%s", str[i]);
  }

//完成数据的输入

  for (
	  int i = 0;
	  i < T;
	  ++i) {
	int standard = 0;


//当输入的是空序列时
	for (
		int j = 0;
		j < Stack_Size; ++j) {
	  if ((str[i][j] == '{') || (str[i][j] == '[') || (str[i][j] == '(')) {
		push(str[i][j]);
	  } else if (str[i][j] == ')') {
		if (contents[first_item - 1] != '(') {
		  standard = 0;
		  for (
			  int k = first_item - 1;
			  k >= 0; --k) {
			contents[k] = 0;
		  }
		  break;
		} else {
		  pop();
		  standard = 1;
		}
	  } else if (str[i][j] == ']') {
		if (contents[first_item - 1] != '[') {
		  standard = 0;
		  for (
			  int k = first_item - 1;
			  k >= 0; --k) {
			contents[k] = 0;
		  }
		  break;
		} else {
		  pop();
		  standard = 1;
		}

	  } else if (str[i][j] == '}') {
		if (contents[first_item - 1] != '{') {
		  standard = 0;
		  for (
			  int k = first_item - 1;
			  k >= 0; --k) {
			contents[k] = 0;
		  }
		  break;
		} else {
		  pop();
		  standard = 1;
		}
	  } else {
		break;
	  }
	}

	if (first_item != 0) {
	  standard = 0;
	}
//当栈中还有元素时同样不合理
	if (standard) {
	  printf("True\n");
	} else {
	  printf("False\n");
	}
//输出是否为合理序列
	for (
		int k = first_item - 1;
		k >= 0; --k) {
	  contents[k] = 0;
	}
	first_item = 0;
//栈清空
  }
  return 0;
}

void push(char i) {
  contents[first_item++] = i;
}

void pop(void) {
  contents[first_item--] = 0;
}