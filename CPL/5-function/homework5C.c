//
// Created by 27756 on 2022/10/28.
//
#include <stdio.h>
#include <math.h>

/**
 * 用于判断是不是素数
 * @param x 输入的需要判断值
 * @return 返回值为 是（1） 或 否（0）
 */

int Is_Prime(int x);

int main() {
  int n = 0, count = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
	if (i < 10) {
	  if (Is_Prime(i)) {
		count++;
	  }
	} else if ((10 < i) && (i < 100)) {
	  int j = i / 10, k = i % 10;
	  if ((Is_Prime(i)) && Is_Prime(10 * k + j)) {
		count++;
	  }

	} else if ((100 < i) && (i < 1000)) {
	  int j = i / 100, k = (i % 100) / 10, p = (i % 100) % 10;
	  if ((Is_Prime(i)) && Is_Prime(100 * p + 10 * k + j)) {
		count++;
	  }
	}
  }
  printf("%d", count);
  return 0;
}

int Is_Prime(int x) {
  int flag = 1;
  for (int i = 2; i <= sqrt(x + 0.5); i++) {
	if (x % i == 0) {
	  flag = 0;
	  break;
	}
  }
  return flag;
}