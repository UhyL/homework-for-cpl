//选择排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 10005

int a[N];

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
	scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; ++i) {
	int minx = a[i];
	int minpos = i;
	for (int j = i + 1; j <= n; ++j) {
	  if (a[j] < minx) {
		minx = a[j];
		minpos = j;
	  }
	}
	swap(&a[minpos], &a[i]);
  }
  for (int i = 1; i < n; ++i) {
	printf("%d ", a[i]);
  }
  printf("%d\n", a[n]);
  return 0;
}
/*
选择排序和插入排序比较相似，都是将数组分为有序的部分和无序的部分
假设有序部分在无序部分的前面
我们将无序的部分从头到尾看一边，然后找到里面最小的，然后将它与无序部分的最前面一个交换
这样得来的这个数字，一定是比后面的数字都要小，比前面的数字都要大的（因为前面的数字也是原先无序部分当中最小的）
所以这个数字的位置是绝对正确的
当所有的数字都到了它应该到的位置，整个数组就是有序的了
*/