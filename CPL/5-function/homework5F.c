//
// Created by 27756 on 2022/10/28.
//
#include <stdio.h>

/**
 *用于输出排放后的数组
 * @param array 最后的方阵数组的样式
 * @param len 长度
 * @param n 方阵的边长
 */

void PutOut(int array[][100], int len, int n);

/**
 *用于循环将值输入二维数组中的对应位置
 * @param array 方阵组成的数组
 * @param len1 方正数组的长度
 * @param flag 用于定义是否有数字存在
 * @param len2 判断数组长度
 * @param x1 起始坐标x
 * @param x2 终点坐标x
 * @param y1 起始坐标y
 * @param y2 终点坐标y
 * @param n 方正的边长
 */

void Circle(int array[][100], int len1, int flag[][100], int len2, int x1, int x2, int y1, int y2, int n);

int main() {
  int array[100][100] = {0};
  int flag[100][100] = {0};
  int n = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;

  scanf("%d", &n);
  x1 = (n + 1) / 2, y1 = 1;
  array[y1][x1] = 1;
  flag[y1][x1] = 1;


   Circle( array, 100,  flag, 100,  x1,  x2,  y1,  y2,  n);
   PutOut( array, 100, n);

  return 0;

}



void Circle(int array[][100], int len1, int flag[][100], int len2, int x1, int x2, int y1, int y2, int n){
  for (int i = 2; i <= n * n; ++i) {
	//  map(i);
	x2 = x1 + 1, y2 = y1 - 1;
	if (x2 > n) {
	  x2 = 1;
	}
	if (y2 < 1) {
	  y2 = n;
	}
	if (flag[y2][x2]) {
	  y2 = y1 + 1;
	  x2 = x1;
	  if (y2 > n) {
		y2 = 1;
	  }
	}
	array[y2][x2] = i, flag[y2][x2] = 1, x1 = x2, y1 = y2;
  }
}



void PutOut(int array[][100], int len, int n) {
  for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= n; ++j) {
	  printf("%d ", array[i][j]);
	}
	printf("\n");
  }
}




