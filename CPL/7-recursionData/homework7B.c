//
// Created by 27756 on 2022/11/14.
//
#include <stdio.h>

/**
 * Magic_Print 1 2 分别代表board与height的三种情况
 * @param length 长
 * @param board  宽
 * @param height 高
 */

void Magic_Print1(int length, int board, int height);
void Magic_Print2(int length, int board, int height);

int main() {
  int T = 0;
  int length[51] = {0}, board[51] = {0}, height[51] = {0};

  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
	scanf("%d%d%d", &length[i], &board[i], &height[i]);
  }

  for (int i = 1; i <= T; ++i) {
	if (board[i] <= height[i]) {
	  Magic_Print1(length[i], board[i], height[i]);
	} else {
	  Magic_Print2(length[i], board[i], height[i]);
	}
  }

  return 0;
}

void Magic_Print1(int length, int board, int height) {
  for (int i = 1; i <= 2 * board + 2 * height + 1; ++i) {
	if (i < 2 * board + 1) {
	  for (int j = 1; j <= 2 * board + 1 - i; ++j) {
		printf(" ");
	  }
	  if (i % 2 == 0) {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("/");
		  } else {
			printf(" ");
		  }
		}
		for (int j = 1; j < i; ++j) {
		  if (j % 2 == 0) {
			printf("/");
		  } else {
			printf("|");
		  }
		}
	  } else {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("+");
		  } else {
			printf("-");
		  }
		}
		for (int j = 1; j < i; ++j) {
		  if (j % 2 == 0) {
			printf("+");
		  } else {
			printf(" ");
		  }
		}
	  }
	} else if (i > 2 * height + 1) {
	  if (i % 2 == 0) {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("|");
		  } else {
			printf(" ");
		  }
		}
		for (int j = 1; j <= 2 * board + 2 * height + 1 - i; ++j) {
		  if (j % 2 == 0) {
			printf("|");
		  } else {
			printf("/");
		  }
		}
	  } else {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("+");
		  } else {
			printf("-");
		  }
		}
		for (int j = 1; j <= 2 * board + 2 * height + 1 - i; ++j) {
		  if (j % 2 == 0) {
			printf("+");
		  } else {
			printf(" ");
		  }
		}
	  }
	} else {
	  if (i % 2 == 0) {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("|");
		  } else {
			printf(" ");
		  }
		}
		for (int j = 0; j < board; j = j + 1) {
		  printf("/|");
		}
	  } else {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("+");
		  } else {
			printf("-");
		  }
		}
		for (int j = 0; j < board; j = j + 1) {
		  printf(" +");
		}
	  }
	}
	printf("\n");
  }
}
void Magic_Print2(int length, int board, int height) {
  for (int i = 1; i <= 2 * board + 2 * height + 1; ++i) {
	if (i < 2 * height +1 ) {
	  for (int j = 1; j <= 2 * board + 1 - i; ++j) {
		printf(" ");
	  }
	  if (i % 2 == 0) {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("/");
		  } else {
			printf(" ");
		  }
		}
		for (int j = 1; j < i; ++j) {
		  if (j % 2 == 0) {
			printf("/");
		  } else {
			printf("|");
		  }
		}
	  } else {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("+");
		  } else {
			printf("-");
		  }
		}
		for (int j = 1; j < i; ++j) {
		  if (j % 2 == 0) {
			printf("+");
		  } else {
			printf(" ");
		  }
		}
	  }
	} else if (i > 2 * board + 1 ) {
	  if (i % 2 == 0) {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("|");
		  } else {
			printf(" ");
		  }
		}
		for (int j = 1; j <= 2 * board + 2 * height + 1 - i; ++j) {
		  if (j % 2 == 0) {
			printf("|");
		  } else {
			printf("/");
		  }
		}
	  } else {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("+");
		  } else {
			printf("-");
		  }
		}
		for (int j = 1; j <= 2 * board + 2 * height + 1 - i; ++j) {
		  if (j % 2 == 0) {
			printf("+");
		  } else {
			printf(" ");
		  }
		}
	  }
	} else {
	  for (int j = 1; j <= 2 * board + 1 - i; ++j) {
		printf(" ");
	  }
	  if (i % 2 == 0) {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("/");
		  } else {
			printf(" ");
		  }
		}
		for (int j = 1; j <= 2 * height; ++j) {
		  if (j % 2 == 0) {
			printf("/");
		  } else {
			printf("|");
		  }
		}
	  } else {
		for (int j = 1; j <= 2 * length + 1; ++j) {
		  if (j % 2 == 1) {
			printf("+");
		  } else {
			printf("-");
		  }
		}
		for (int j = 1; j <= 2 * height; ++j) {
		  if (j % 2 == 0) {
			printf("+");
		  } else {
			printf(" ");
		  }
		}
	  }

	}
	printf("\n");
  }
}




