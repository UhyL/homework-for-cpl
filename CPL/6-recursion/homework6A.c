//
// Created by 27756 on 2022/11/4.
//
#include <stdio.h>

int count(int a, int b);

int main() {
  int a = 0, b = 0;
  scanf("%d %d", &a, &b);

  printf("%d", count( a -1 , b -1));

  return 0;
}

int count(int a, int b) {
  if ( (a == b) || b == 0) {
	return 1;
  }

  return count(a - 1, b) + count(a - 1, b - 1);

}