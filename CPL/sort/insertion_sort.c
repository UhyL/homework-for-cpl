//插入排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 10005

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main(int argc, char *argv[]) {
  int a[N];
  int n;
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; ++i) {
	scanf("%d", &a[i]);
  }

  for (int i = 2; i <= n; ++i) {
	int key = a[i];
	int j = i - 1;
	while (a[j] > key && j >= 1) {
	  a[j + 1] = a[j];
	  --j;
	}
	a[j + 1] = key;
  }
  for (int i = 1; i < n; ++i) {
	printf("%d ", a[i]);
  }
  printf("%d\n", a[n]);
  return 0;
}
/*
呃，插入排序是这样的：
我们把一个数组的前面一部分看作是有序的，后面一部分看作是无序的
显然，刚开始有序的部分只有这个数组的第一个元素
然后我们想要将无序数组中的元素一个一个插进这个有序的数组里面，并使它仍然保持有序
具体怎么实现:
    选中无序数组当中的一个元素（为简便，我们假设我们一直选中第一个元素）
    然后我们通过类似冒泡排序当中提到的“上浮”的方式，将这个元素先添加到有序数组的末尾，然后慢慢往前挪
    （使用这种方式是因为，C语言的数组是连续的，并不能很方便地实现删除和插入单个元素，所以只能用这种方式来模拟插入操作）
    挪到相应的位置上，此时我们发现有序数组变长了，而无序数组变短了。
    重复这样的操作，就能完成排序
*/