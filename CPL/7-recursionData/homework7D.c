//
// Created by 27756 on 2022/11/14.
//
#include <stdio.h>
#include <math.h>

int Judge(int a);

int main() {
  int n, q, number = 1;
  //number 用来表示内存链条的个数，也同样用来表示节点的个数
  scanf("%d", &n);
  scanf("%d", &q);
  //用n代替2^n，每次分内存则减1

  int count[100000] = {0};
  int array[100000] = {0};

  count[0] = n;
  array[0] = 0;
  //array用于储存数据
  //count 表示内存
  getchar();

  int str[10000][4] = {0};

  for (int i = 0; i < q; ++i) {
	for (int j = 0; j < 2; ++j) {
	  scanf("%c", &str[i][j]);
	}
	if (str[i][1] == 32) {
	  scanf("%d%d", &str[i][2], &str[i][3]);
	  getchar();
	}
  }
  for (int i = 0; i < q; ++i) {
	if (str[i][0] == 'Q') {
	  printf("%d\n", number);
	  for (int j = 0; j < number; ++j) {
		printf("%d ", array[j]);
	  }
	  printf("\n");
	} else {
	  int temp1 = str[i][2];
	  double temp2 = str[i][3];
	  for (int j = 0; j < number; ++j) {
		if ((count[j] >= Judge(temp2)) && (array[j] == 0)) {
		  if (count[j] == Judge(temp2)) {
			array[j] = temp1;
			break;
		  } else {
			number++;
			for (int k = number - 2; k > j; --k) {
			  count[k + 1] = count[k];
			  array[k + 1] = array[k];
			}
			count[j + 1] = count[j] - 1;
			count[j] = count[j] - 1;
			array[j + 1] = array[j];
			j = j -1;
		  }
		}
	  }
	}
  }
  return 0;
}
int Judge(int a) {
  int temp;
  for (int i = 0;; ++i) {
	if ((int)pow(2, i) >= a) {
	  temp = i;
	  break;
	}
  }
  return temp;
}