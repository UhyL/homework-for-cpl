//
// Created by 27756 on 2022/11/18.
//
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define Stack_Size  10000

#define len 6

int contents[Stack_Size] = {0};
int first_item = 0;

bool is_empty(void);
void push(char i);
void pop(void);
void stack_underflow(void);
void top(void);
void print();

int main() {
  int n = 0;
  char str[5];
  scanf("%d", &n);

  getchar();
  for (int i = 0; i < n ; ++i) {
	scanf("%s", str);
	if (str[0] == 116) {
	  top();
	} else if (str[1] == 114) {
	  print();
	} else if (str[1] == 111) {
	  pop();
	} else if (str[1] == 117) {
	  getchar();
	  char arr;
	  scanf("%c", &arr);
	  push(arr);
	}
	for (int j = 0; j < 5; ++j) {
	  str[j] = '\0';
	}
  }


  return 0;
}

bool is_empty(void) {
  return first_item == 0;
}

void push(char i) {
  contents[first_item++] = i;
}

void pop(void) {
  if (is_empty()) {
	stack_underflow();
  } else {
	contents[first_item--] = 0;
  }
}

void stack_underflow(void) {
  printf("Empty\n");
}

void top(void) {
  if (is_empty()) {
	stack_underflow();
  } else {
	printf("%c\n", contents[first_item]);
  }
}

void print(void) {
  if (is_empty()) {
	stack_underflow();
  } else {
	int count = first_item - 1;
	while (count >= 0) {
	  printf("| %c |\n", contents[count]);
	  count--;
	}

	printf("|===|\n");
  }
}
