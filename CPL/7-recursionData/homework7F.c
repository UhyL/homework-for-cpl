//
// Created by 27756 on 2022/11/14.
//
#include <stdio.h>

int main() {
  int a, b, c, x1 = 0, x2 = 0, y1 = 0, y2 = 0, z = 0, count = 0;
  scanf("%d%d%d", &a, &b, &c);
  x2 = a, y2 = b, z = c;
  getchar();
  char array[1001] = "";
  scanf("%s", array);
  while(array[count] != 0) {
	int temp = 0;
	if (array[count] == 87) {
	  temp = z;
	  z = x2 - x1;
	  x2 = x1;
	  x1 = x1 - temp;
	} else if (array[count] == 83) {
	  temp = z;
	  z = x2 - x1;
	  x1 = x2;
	  x2 = x2 + temp;
	} else if (array[count] == 68) {
	  temp = z;
	  z = y2 -y1;
	  y1 = y2;
	  y2 = y2 + temp;
	} else {
	  temp = z;
	  z = y2 -y1;
	  y2 = y1;
	  y1 = y1 - temp;
	}

	count = count + 1;
  }

  printf("%d %d %d %d", x1, x2, y1, y2);

  return 0;
}