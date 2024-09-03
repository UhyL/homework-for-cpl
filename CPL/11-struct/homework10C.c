//
// Created by 27756 on 2022/12/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char name[11];
  struct node *next1;
  struct node *next2;
};

void make_node(char *str, struct node *Last_node);

void Refresh(struct node *Node);

struct node *find_node(char *str, struct node *start);

struct node *find_node2(char *str, struct node *start);

void Remove(struct node *start);

int count(struct node *start);

int main() {
  int numbers = 0;
  int steps = 0;
  scanf("%d %d", &numbers, &steps);
  struct node *first = NULL;//利用第一个节点的位置以及next指针代表整个链表
  first = malloc(sizeof(struct node));
  Refresh(first);
  char *str1 = malloc(10 * sizeof(*str1));
  char *str2 = malloc(10 * sizeof(*str2));

  for (int i = 0; i < steps + numbers; ++i) {
	scanf("%s", str1);
	scanf("%s", str2);

	if (!strcmp(str1, "remove")) {
	  struct node *curr = find_node(str2, first->next1);
	  struct node *prev = find_node2(str2, first->next1);
	  if (prev->next1 == curr) {
		prev->next1 = NULL;
		Remove(curr);
	  } else {
		prev->next2 = NULL;
		Remove(curr);
	  }
	} else if (!strcmp(str1, "query")) {
	  printf("%d\n", count(find_node(str2, first->next1)));
	} else {
	  if (!strcmp(str2, "~~~")) {
		make_node(str1, first);
	  } else {
		make_node(str1, find_node(str2, first->next1));
	  }
	}
  }
  Remove(first);
  free(str1);
  free(str2);
  return 0;
}

void Refresh(struct node *Node) {//函数用于将新开的节点中的
  Node->next1 = NULL;
  Node->next2 = NULL;
  memset(Node->name, '\0', 11);
}

void make_node(char *str, struct node *Last_node) {//建立新的链表
  struct node *new_node;
  new_node = malloc(sizeof(struct node));
  Refresh(new_node);
  strcpy(new_node->name, str);
  if (Last_node->next1 == NULL) {
	Last_node->next1 = new_node;
  } else {
	Last_node->next2 = new_node;
  }
}

struct node *find_node(char *str, struct node *start) {
  if (start == NULL) {
	return NULL;
  } else if (!strcmp(str, start->name)) {
	return start;
  } else {
	struct node *temp_node;
	if (temp_node = find_node(str, start->next1)) {
	  return temp_node;
	} else if (temp_node = find_node(str, start->next2)) {
	  return temp_node;
	} else {
	  return NULL;
	}
  }
}

struct node *find_node2(char *str, struct node *start) {
  if (start == NULL) {
	return NULL;
  } else if ((start->next1 != NULL) && (!strcmp(str, start->next1->name))) {
	return start;
  } else if ((start->next2 != NULL) && (!strcmp(str, start->next2->name))) {
	return start;
  } else {
	struct node *temp_node;
	if (temp_node = find_node2(str, start->next1)) {
	  return temp_node;
	} else if (temp_node = find_node2(str, start->next2)) {
	  return temp_node;
	} else {
	  return NULL;
	}
  }
}

int count(struct node *start) {
  if (start == NULL) {
	return 0;
  } else {
	return count(start->next1) + count(start->next2) + 1;
  }
}

void Remove(struct node *start) {
  if (start) {
	Remove(start->next1);
	Remove(start->next2);
	free(start);
  }
}