//
// Created by 27756 on 2022/12/28.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int number;
  struct node *Next;
  struct node *Prev;
} Node;

typedef struct list {
  Node *point;
} Linkedlist;

void Forward(Linkedlist *list, int number);

void Backward(Linkedlist *list, int number);

void Remove(Linkedlist *list);

void Print(const Linkedlist *list);

void Make_new_node(Linkedlist *list);

void Insert(Linkedlist *list, int numbers);

void Return(Linkedlist *list);

void Free(Linkedlist *list);

int main() {
  int n;
  int steps;
  int numbers = 0;
  Linkedlist list;
  list.point = NULL;
  scanf("%d%d", &n, &steps);
  for (int i = 0; i < n; ++i) {
	Make_new_node(&list);
  }
  Return(&list);
  char *str = malloc(10);
  for (int i = 0; i < steps; ++i) {
	scanf("%s", str);
	if (str[0] == 'F') {
	  scanf("%d", &numbers);
	  Forward(&list, numbers);
	} else if (str[0] == 'B') {
	  scanf("%d", &numbers);
	  Backward(&list, numbers);
	} else if (str[0] == 'P') {
	  Print(&list);
	} else if (str[0] == 'R') {
	  Remove(&list);
	} else if (str[0] == 'I') {
	  scanf("%d", &numbers);
	  Insert(&list, numbers);
	} else {
	  printf("error");
	}
  }
  Free(&list);
  free(str);
  return 0;
}

void Forward(Linkedlist *list, int number) {
  if ((list->point == NULL) || (list->point->Next == NULL) || (list->point->Prev == NULL)) {
	return;
  }
  for (int i = 0; i < number; ++i) {
	list->point = list->point->Next;
  }
}

void Backward(Linkedlist *list, int number) {
  if ((list->point == NULL) || (list->point->Next == NULL) || (list->point->Prev == NULL)) {
	return;
  }
  for (int i = 0; i < number; ++i) {
	list->point = list->point->Prev;
  }
}

void Make_new_node(Linkedlist *list) {
  Node *new_node = malloc(sizeof(Node));
  if (list->point == NULL) {
	new_node->number = 1;
	list->point = new_node;
	list->point->Prev = NULL;
	list->point->Next = NULL;
  } else if (list->point->Next == NULL) {
	new_node->number = 2;
	new_node->Prev = list->point;
	new_node->Next = list->point;
	list->point->Next = new_node;
	list->point->Prev = new_node;
	list->point = new_node;
  } else {
	new_node->number = list->point->number + 1;
	new_node->Next = list->point->Next;
	new_node->Prev = list->point;
	list->point->Next->Prev = new_node;
	list->point->Next = new_node;
	list->point = new_node;
  }
}

void Print(const Linkedlist *list) {
  if (list->point == NULL) {
	return;
  } else {
	printf("%d\n", list->point->number);
  }
}

void Insert(Linkedlist *list, int numbers) {
  Node *new_node = malloc(sizeof(Node));
  new_node->number = numbers;
  if (list->point == NULL) {
	new_node->number = 1;
	list->point = new_node;
	list->point->Prev = NULL;
	list->point->Next = NULL;
  } else if (list->point->Next == NULL) {
	new_node->Prev = list->point;
	new_node->Next = list->point;
	list->point->Next = new_node;
	list->point->Prev = new_node;
  } else {
	new_node->Next = list->point->Next;
	new_node->Prev = list->point;
	list->point->Next->Prev = new_node;
	list->point->Next = new_node;
  }
}

void Remove(Linkedlist *list) {
  if ((list->point == NULL) || (list->point->Next == NULL) || (list->point->Prev == NULL)) {
	return;
  } else if (list->point->Next == list->point->Prev) {
	Node *cur = list->point;
	cur->Next->Prev = NULL;
	cur->Prev->Next = NULL;
	list->point = cur->Next;
	free(cur);
  } else {
	Node *cur = list->point;
	cur->Next->Prev = cur->Prev;
	cur->Prev->Next = cur->Next;
	list->point = cur->Next;
	free(cur);
  }
}

void Free(Linkedlist *list) {
  if (list->point == NULL) {
	return;
  }
  while ((list->point->Next != NULL) && (list->point->Prev != NULL)) {
	Remove(list);
  }
  free(list->point);
}

void Return(Linkedlist *list) {
  if ((list->point == NULL) || (list->point->Next == NULL) || (list->point->Prev == NULL)) {
	return;
  }
  list->point = list->point->Next;
}