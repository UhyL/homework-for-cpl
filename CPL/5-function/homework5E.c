//
// Created by 27756 on 2022/10/28.
//
#include <stdio.h>

int n, count = 1;

/**
 * 用于查找递降后缀
 * @param array 所给出的一段序列
 * @param len 数组的长度
 * @param n 输入序列的长度
 */

void Circle1 (int array[], int len, int n);

/**
 * 找到最长递降后缀的之前的那个数，再找出递降中比其大的最小数进行交换
 * @param array 所给出的一段序列
 * @param len 数组的长度
 * @param n 输入序列的长度
 * @param standard 最长递降后缀的之前的那个数计为standard
 */

void Circle2 (int array[], int len, int n, int standard);

/**
 *将交换后的递降序列中的数翻转
 * @param array
 * @param lenlen 数组的长度
 * @param n 输入序列的长度
 */

void Circle3 (int array[], int len, int n);


int main() {

    int array[2000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

	Circle1(array, 2000, n);
    Circle2(array, 2000, n, array[n-1-count]);
	Circle3(array, 2000, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}


void Circle1 (int array[], int len, int n){
  for (int i = n-1; i > 0; --i) {
	if(array[i] < array[i-1]) {
	  count ++;
	} else {
	  break;
	}
  }
}

void Circle2 (int array[], int len, int n, int standard ) {
  for (int i = n-1; i > 0; --i) {
	if (array[i] > standard) {
	  int temp;
	  temp = array[i];
	  array[i] = array[n-1-count];
	  array[n-1-count] = temp;
	  break;
	}
  }
}

void Circle3 (int array[], int len, int n) {
  for (int i = n-1; i > (n-count + n-1 )/2; --i) {
	int temp;
	temp = array[i];
	array[i] = array[2*n - count -1 -i];
	array[2*n - count -1 -i] = temp;
  }
}