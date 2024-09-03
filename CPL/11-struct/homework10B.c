//
// Created by 27756 on 2022/12/9.
//
#include <stdio.h>

typedef struct {
  int max_stair;
  int stairs[20001];
} P;

void and_count(P p1, P p2, char str[]);

void minus_count(P p1, P p2, char str[]);

void multiply_count(P p1, P p2, char str[]);

void print(P p, char str[]);

int main() {
  char variable_name[11];
  P p1;
  P p2;
  //获取p1和p2的阶以及变量名称
  scanf("%d%d", &p1.max_stair, &p2.max_stair);
  scanf("%s", variable_name);
  //完成p1各项的输入
  for (int i = p1.max_stair; i >= 0; --i) {
	scanf("%d", &p1.stairs[i]);
  }
  //完成p2各项系数的输入
  for (int i = p2.max_stair; i >= 0; --i) {
	scanf("%d", &p2.stairs[i]);
  }
  //进行加减乘法的运算
  and_count(p1, p2, variable_name);
  minus_count(p1, p2, variable_name);
  multiply_count(p1, p2, variable_name);

  return 0;
}

void and_count(P p1, P p2, char str[]) {
  P ans_p;
  ans_p.max_stair = p1.max_stair > p2.max_stair ? p1.max_stair : p2.max_stair;
  if (p1.max_stair >= p2.max_stair) {
	for (int i = p1.max_stair; i > p2.max_stair; --i) {
	  ans_p.stairs[i] = p1.stairs[i];
	}
	for (int i = p2.max_stair; i >= 0; --i) {
	  ans_p.stairs[i] = p1.stairs[i] + p2.stairs[i];
	}
  } else {
	for (int i = p2.max_stair; i > p1.max_stair; --i) {
	  ans_p.stairs[i] = p2.stairs[i];
	}
	for (int i = p1.max_stair; i >= 0; --i) {
	  ans_p.stairs[i] = p1.stairs[i] + p2.stairs[i];
	}
  }
  print(ans_p, str);
  printf("\n");
}

void minus_count(P p1, P p2, char str[]) {
  P ans_p;
  ans_p.max_stair = p1.max_stair > p2.max_stair ? p1.max_stair : p2.max_stair;
  if (p1.max_stair >= p2.max_stair) {
	for (int i = p1.max_stair; i > p2.max_stair; --i) {
	  ans_p.stairs[i] = p1.stairs[i];
	}
	for (int i = p2.max_stair; i >= 0; --i) {
	  ans_p.stairs[i] = p1.stairs[i] - p2.stairs[i];
	}
  } else {
	for (int i = p2.max_stair; i > p1.max_stair; --i) {
	  ans_p.stairs[i] = -p2.stairs[i];
	}
	for (int i = p1.max_stair; i >= 0; --i) {
	  ans_p.stairs[i] = p1.stairs[i] - p2.stairs[i];
	}
  }
  print(ans_p, str);
  printf("\n");
}

void multiply_count(P p1, P p2, char str[]) {
  P ans_p;
  ans_p.max_stair = p1.max_stair + p2.max_stair;
  for (int i = ans_p.max_stair; i >= 0; --i) {
	int sum_stair = 0;
	for (int j = i <= p1.max_stair ? i : p1.max_stair; j >= 0; --j) {
	  sum_stair = p1.stairs[j] * p2.stairs[i - j] + sum_stair;
	}
	ans_p.stairs[i] = sum_stair;
  }
  print(ans_p, str);
}

void print(P p, char str[]) {
  if (p.stairs[p.max_stair] != 0) {
	if (p.stairs[p.max_stair] == 1) {
	  printf("%s^%d", str, p.max_stair);
	} else if (p.stairs[p.max_stair] == -1) {
	  printf("-%s^%d", str, p.max_stair);
	} else {
	  printf("%d%s^%d", p.stairs[p.max_stair], str, p.max_stair);
	}
  }

  for (int i = p.max_stair - 1; i > 1; --i) {
	if (p.stairs[i] != 0) {
	  if (p.stairs[i] == 1) {
		printf("+%s^%d", str, i);
	  } else if (p.stairs[i] == -1) {
		printf("-%s^%d", str, i);
	  } else if (p.stairs[i] < 0) {
		printf("%d%s^%d", p.stairs[i], str, i);
	  } else {
		printf("+%d%s^%d", p.stairs[i], str, i);
	  }
	}
  }
  if (p.stairs[1] != 0) {
	if (p.stairs[1] == 1) {
	  printf("+%s", str);
	} else if (p.stairs[1] == -1) {
	  printf("-%s", str);
	} else if (p.stairs[1] < 0) {
	  printf("%d%s", p.stairs[1], str);
	} else {
	  printf("+%d%s", p.stairs[1], str);
	}
  }
  if (p.stairs[0] != 0) {
	if (p.stairs[0] > 0) {
	  printf("+%d", p.stairs[0]);
	} else {
	  printf("%d", p.stairs[0]);
	}
  }
}

