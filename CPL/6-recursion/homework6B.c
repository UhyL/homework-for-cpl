//
// Created by 27756 on 2022/11/4.
//
#include <stdio.h>

int sorts(int n);

int main() {
  int n = 0;
  scanf("%d", &n);

  printf("%d",  sorts(n));

  return 0;
}

int sorts(int n) {
  if (n ==2) {
	return 2;
  }

  if (n == 1) {
	return 1;
  }

  return sorts(n-1) + sorts(n -2);
}