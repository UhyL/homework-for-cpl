//
// Created by 27756 on 2022/10/21.
//
#include <stdio.h>
int count = 0;
char board[102][102] = {"o"};



int main() {
    int n = 0;

    int vectors[8][2] = {{0,  1},{0,  -1},{1,  0},{-1, 0},
                         {1,  1},{1,  -1},{-1, 1},{-1, -1}};

    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%c", &board[i][j]);
        }
        getchar();
    }//完成方阵的输入

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] == '*') {
                printf("%c", board[i][j]);
            } else {
                for (int k = 0; k < 8; ++k) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    if (board[newI][newJ] == '*') {
                        count++;
                    }
                }
                printf("%d", count);
                count = 0;
            }
        }
        printf("\n");
    }


    return 0;
}