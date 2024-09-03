//
// Created by 27756 on 2022/11/4.
//
#include <stdio.h>
#include <math.h>

char dict[100][100];

void paint(int n, int x, int x2, int y, char dict[][100]);

int main() {
  int n;
  scanf("%d", &n);


  paint(n, pow(2, n), pow(2, n) + 1, 1, dict);

  for (int i = 1; i <= pow(2, n); ++i) {
	for (int j = 1; j <= pow(2, n + 1); ++j) {
	  if (dict[i][j] == '\0') {
		printf(" ");
	  } else {
		printf("%c", dict[i][j]);
	  }
	}

	printf("\n");

  }

  return 0;
}

void paint(int n, int x1, int x2, int y, char dict[][100]) {
  if (n == 1) {
	dict[y][x1] = '/';
	dict[y][x2] = '\\';
	dict[y + 1][x1 - 1] = '/';
	dict[y + 1][x2 + 1] = '\\';
	dict[y + 1][x1] = '_';
	dict[y + 1][x2] = '_';
	return;
  }

  paint(n - 1, x1, x2, y, dict);
  paint(n - 1, x1 - pow(2, n - 1), x1 - pow(2, n - 1) + 1, y + pow(2, n - 1) , dict);
  paint(n - 1, x2 + pow(2, n - 1) - 1, x2 + pow(2, n - 1), y + pow(2, n - 1) , dict);
}