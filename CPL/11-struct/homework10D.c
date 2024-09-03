//
// Created by 27756 on 2022/12/9.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 501

int hash(const char *s);

typedef struct node {
  char *str;
  struct node *prev;
} Node;

typedef struct array {
  Node *last;
} Array;

void Refresh_node(Node *node);

void Make_node(const char *str, Node **ptr_Last_node);

void find_node(Node *Last_node, const char *str);

int main() {
  int number_str = 0;
  int query_times = 0;
  scanf("%d%d", &number_str, &query_times);
  Array dict[N - 1];
  char *str = malloc(1000);
  for (int i = 0; i < number_str; ++i) {
	scanf("%s", str);
	int sign = hash(str);
	if (!dict[sign].last) {
	  Node *new_node = malloc(sizeof(Node));
	  Refresh_node(new_node);
	  new_node->str = malloc(strlen(str) + 1);
	  strcpy(new_node->str, str);
	  new_node->prev = NULL;
	  dict[sign].last = new_node;
	} else {
	  Make_node(str, &dict[sign].last);
	}
  }
  for (int i = 0; i < query_times; ++i) {
	scanf("%s", str);
	int sign = hash(str);
	if (!dict[sign].last) {
	  printf("No\n");
	} else {
	  find_node(dict[sign].last, str);
	}

  }
  free(str);
  return 0;
}

int hash(const char *s) {
  int len = (int)strlen(s);
  int ret = 0;
  for (int i = 0; i < len; i++)ret = (ret + s[i] * (i + 1)) % N;
  return ret;
}

void Refresh_node(Node *node) {
  node->prev = NULL;
}

void Make_node(const char *str, Node **ptr_Last_node) {
  Node *new_node = malloc(sizeof(Node));
  Refresh_node(new_node);
  new_node->str = malloc(strlen(str) + 1);
  strcpy(new_node->str, str);
  new_node->prev = (*ptr_Last_node);
  (*ptr_Last_node) = new_node;
}

void find_node(Node *Last_node, const char *str) {
  if (Last_node) {
	if (!strcmp(str, Last_node->str)) {
	  printf("Yes\n");
	} else {
	  find_node(Last_node->prev, str);
	}
  } else {
	printf("No\n");
  }
}
