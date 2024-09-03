//
// Created by 27756 on 2022/11/4.
//
#include <stdio.h>

void Maxseg(int l, int r, int array[], int ans[][2]);

int main() {
  int n = 0;
  scanf("%d", &n);
  int array[100001] = {0};

  int ans[100001][2] = {0};

  for (int i = 1; i <= n; ++i) {
	scanf("%d", &array[i]);
  }

  Maxseg(1,n,array,ans);

  for (int i = 1; i <= n; ++i) {
	printf("%d %d\n", ans[i][0], ans[i][1]);
  }

  return 0;
}

void Maxseg(int l, int r, int array[], int ans[][2]) {
  if (l == r) {
	ans[l][0] = l;
	ans[l][1] = l;
  }
  if (l < r){
	int max = array[l];
	int index_max = l;
	for (int i = l + 1; i <= r; ++i) {
	  if (array[i] > max) {
		index_max = i;
		max = array[i];
	  }
	}
	ans[index_max][0] = l;
	ans[index_max][1] = r;

	Maxseg(l, index_max - 1, array, ans);
	Maxseg(index_max + 1, r, array, ans);
  }
}


