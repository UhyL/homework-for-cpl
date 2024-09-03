//
// Created by 27756 on 2022/12/9.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define len 1000

typedef struct {
  char name[32];
  struct {
	int att_scores;
	int def_scores;
	int min_scores;
  } score;
} Value;

typedef struct {
  char name[32];
  double ave_scores;
} Average;

void sort(Average *arr, int n);

int main() {
  int number = 0;
  scanf("%d", &number);
  char country_name[len][32];//char *country_name[len]
  Value (*scores)[12] = malloc((number + 1) * 12 * sizeof(*scores));
  Average *att_ave = malloc(number * sizeof *att_ave);
  Average *def_ave = malloc(number * sizeof *def_ave);
  Average *min_ave = malloc(number * sizeof *min_ave);
  for (int i = 0; i < number; ++i) {
	int sum_att = 0;
	int sum_def = 0;
	int sum_min = 0;
	scanf("%s", country_name[i]);
	for (int j = 0; j < 11; ++j) {
	  scanf("%s", scores[i][j].name);
	  scanf("%d%d%d", &scores[i][j].score.att_scores,
			&scores[i][j].score.def_scores, &scores[i][j].score.min_scores);
	  sum_att = sum_att + scores[i][j].score.att_scores;
	  sum_def = sum_def + scores[i][j].score.def_scores;
	  sum_min = sum_min + scores[i][j].score.min_scores;
	}
	memset(att_ave[i].name, '\0', 32);
	memset(def_ave[i].name, '\0', 32);
	memset(min_ave[i].name, '\0', 32);
	strcpy(att_ave[i].name, country_name[i]);
	att_ave[i].ave_scores = sum_att * 1.0 / 11;
	strcpy(def_ave[i].name, country_name[i]);
	def_ave[i].ave_scores = sum_def * 1.0 / 11;
	strcpy(min_ave[i].name, country_name[i]);
	min_ave[i].ave_scores = sum_min * 1.0 / 11;
  }

  sort(att_ave, number);
  sort(def_ave, number);
  sort(min_ave, number);

  for (int i = 0; i < number; ++i) {
	printf("%s ", att_ave[i].name);
  }
  printf("\n");
  for (int i = 0; i < number; ++i) {
	printf("%s ", def_ave[i].name);
  }
  printf("\n");
  for (int i = 0; i < number; ++i) {
	printf("%s ", min_ave[i].name);
  }
  free(scores);
  free(att_ave);
  free(def_ave);
  free(min_ave);
  return 0;
}

void sort(Average *arr, int n) {
  for (int i = 0; i < n - 1; ++i) {
	int max_index = i;
	for (int j = i + 1; j < n; ++j) {
	  if (arr[j].ave_scores > arr[max_index].ave_scores) {
		max_index = j;
	  }
	}
	if (i != max_index) {
	  Average temp = arr[i];
	  arr[i] = arr[max_index];
	  arr[max_index] = temp;
	}
  }
}