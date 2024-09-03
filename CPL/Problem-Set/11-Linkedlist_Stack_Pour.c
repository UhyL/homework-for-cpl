//
// Created by 27756 on 2023/1/4.
//
#include <stdio.h>
#include <stdlib.h>
#define stack_size 10000

typedef struct stack {
  int top_index;
  int total_index;
  int stack_elements[stack_size];
} Stack;

typedef struct node {
  Stack stack;
  struct node *Prev;
  struct node *Next;
} Node;

typedef struct list {
  Node *point;
} Linkedlist;

void Make_node(Linkedlist *list);

void Print(Node *node, Linkedlist *list);

Node *Find(Node *node, int des);

void Operate(Node *sou_node, Node *des_node);

void Free(Linkedlist *list);

int main() {
  int numbers;
  int steps;
  int des_number = 0;
  int sou_number = 0;
  scanf("%d%d", &numbers, &steps);
  Linkedlist list;
  list.point = NULL;
  for (int i = 0; i < numbers; ++i) {
	Make_node(&list);
  }
  for (int i = 0; i < steps; ++i) {
	scanf("%d%d", &sou_number, &des_number);
	Operate(Find(list.point, sou_number), Find(list.point, des_number));
  }
  Print(Find(list.point, 1), &list);
  Free(&list);
  return 0;
}

void Make_node(Linkedlist *list) {
  Node *new_node = malloc(sizeof(Node));
  if (list->point == NULL) {
	new_node->stack.stack_elements[0] = 1;
	new_node->stack.total_index = 1;
	new_node->Prev = NULL;
  } else {
	new_node->stack.stack_elements[0] = list->point->stack.stack_elements[0] + 1;
	new_node->stack.total_index = new_node->stack.stack_elements[0];
	list->point->Next = new_node;
	new_node->Prev = list->point;
  }
  new_node->Next = NULL;
  new_node->stack.top_index = 0;
  list->point = new_node;
}

Node *Find(Node *node, int des) {
  if (node == NULL) {
	return NULL;
  } else if (node->stack.total_index == des) {
	return node;
  } else {
	return Find(node->Prev, des);
  }
}

void Operate(Node *sou_node, Node *des_node) {
  if ((sou_node == NULL) || (des_node == NULL)) {
	return;
  } else if (sou_node->stack.stack_elements[0] == 0) {
	return;
  } else if (des_node->stack.stack_elements[0] == 0) {
	for (int i = 0, j = sou_node->stack.top_index; i <= sou_node->stack.top_index; ++i, --j) {
	  des_node->stack.stack_elements[i] = sou_node->stack.stack_elements[j];
	  sou_node->stack.stack_elements[j] = 0;
	}
	des_node->stack.top_index = des_node->stack.top_index + sou_node->stack.top_index;
	sou_node->stack.top_index = 0;
  } else {
	for (int i = des_node->stack.top_index + 1, j = sou_node->stack.top_index;
		 i <= des_node->stack.top_index + sou_node->stack.top_index + 1; ++i, --j) {
	  des_node->stack.stack_elements[i] = sou_node->stack.stack_elements[j];
	  sou_node->stack.stack_elements[j] = 0;
	}
	des_node->stack.top_index = des_node->stack.top_index + sou_node->stack.top_index + 1;
	sou_node->stack.top_index = 0;
  }
}

void Print(Node *node, Linkedlist *list) {
  Node *cur = node;
  do {
	for (int i = 0; i <= cur->stack.top_index; ++i) {
	  printf("%d ", cur->stack.stack_elements[i]);
	}
	printf("\n");
	cur = cur->Next;
  } while (cur != NULL);
}

void Free(Linkedlist *list) {
  while (list->point->Prev != NULL) {
	Node *cur = list->point;
	list->point = cur->Prev;
	free(cur);
  }
  free(list->point);
}