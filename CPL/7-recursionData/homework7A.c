//
// Created by 27756 on 2022/11/14.
//
#include <stdio.h>
/**
 * 用于查找目前剩余鸡尾酒中价值最大那款的下标
 * @param array1 用于代表价值数组
 * @param array2 用于代表数量数组
 * @param n 表示数组长度
 * @return 返回值为最大价值的下标
 */
int Find_Max(int array1[], int array2[], int n);

int main() {
  int n, l;
  int Total_Price = 0;
  scanf("%d%d", &n, &l);
  const int Price[10000];
  int Amount[10000];

  for (int i = 0; i < n; ++i) {
	scanf("%d", &Price[i]);
  }

  for (int i = 0; i < n; ++i) {
	scanf("%d", &Amount[i]);
  }

  while (l > 0) {
	int temp = Find_Max(Price, Amount, n);
	if (l >= Amount[temp]) {
	  l = l - Amount[temp];
	  Total_Price = Total_Price + Price[temp] * Amount[temp];
	  Amount[temp] = 0;
	} else if (l < Amount[temp]) {
	  Total_Price = Total_Price + Price[temp] * l;
	  l = 0;
	}
  }

  printf("%d", Total_Price);

  return 0;

}

int Find_Max(int array1[], int array2[], int n) {
  int max = 0;
  for (int i = 0; i < n; ++i) {
	if (((array2[i] > 0) && array1[i] > array1[max]) || array2[max] == 0)
	  max = i;
  }
  return max;
}