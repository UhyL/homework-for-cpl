//
// Created by 27756 on 2023/2/15.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int contents;
  struct node *next;//表示下一个链表结构
  struct node *prev;//表示前一个链表结构
} Node;

typedef struct {
  Node *last_node;//指针指向栈底
  Node *first_node;//指针指向栈顶
  int size;//表示这一个栈中链表的个数
} Stack;

void init_label(Stack *label, int numbers);

Node *make_node(Node *stack_head, int contents);

void Pour_stack(Stack *label, int source, int target);//原始栈的下标，目标栈的下标

void Print_label(Stack *label, int numbers);//打印最后的答案结果

int main() {
  int numbers = 0;
  int steps = 0;
  scanf("%d%d", &numbers, &steps);
  Stack *label = malloc(numbers * sizeof(Stack));
  init_label(label, numbers);//初始话栈数组
  int x = 0;
  int y = 0;
  for (int i = 0; i < steps; ++i) {
	scanf("%d%d", &x, &y);
	Pour_stack(label, x, y);
  }
  Print_label(label, numbers);
  free(label);
  return 0;
}

Node *make_node(Node *stack_head, int contents) {
  Node *temp = malloc(sizeof(Node));
  temp->contents = contents;
  temp->prev = stack_head;
  temp->next = NULL;
  if (stack_head != NULL) stack_head->next = temp;
  return temp;
}

void init_label(Stack *label, int numbers) {
  for (int i = 0; i < numbers; ++i) {
	Node *temp = make_node(NULL, i);
	label[i].last_node = temp;
	label[i].first_node = temp;
	label[i].size = 1;
  }
}

void Pour_stack(Stack *label, int source, int target) {
  int here_steps = label[source].size;
  label[target].size += here_steps;
  label[source].size = 0;
  Node *index_source = label[source].first_node;
  Node *index_target = label[target].first_node;
  for (int i = 0; i < here_steps; ++i) {
	Node *temp = make_node(index_target, index_source->contents);
	label[target].first_node = temp;
	index_target = temp;
	Node *free_node = index_source;
	index_source = index_source->prev;
	free(free_node);
  }
  label[source].first_node = NULL;
  label[target].last_node = NULL;
}

void Print_label(Stack *label, int numbers) {
  for (int i = 0; i < numbers; ++i) {
	if (label[i].size == 0) {
	  printf("0\n");
	  continue;
	}
	Node *index = label[i].last_node;
	for (int j = 0; j < label[i].size; ++j) {
	  if (j == label[i].size - 1) printf("%d\n", index->contents);
	  printf("%d ", index->contents);
	  index = index->next;
	}
  }
}