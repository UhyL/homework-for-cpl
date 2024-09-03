//
// Created by 27756 on 2022/11/4.
//
#include <stdio.h>

int f[100001];
int find(int x);

int main() {
  int n = 0;
  scanf("%d", &n);

  for (int i = 1; i <= n ; ++i) {
	scanf("%d", &f[i]);
  }

  for (int i = 1; i <= n ; ++i) {
	printf("%d ", f[find(i)]);
  }
}

int find (int x){
  if ( f[x] == x) {
	return x;
  } else {
	return  find(f[x]);
  }
}