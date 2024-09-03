//
// Created by 27756 on 2022/10/21.
//sudoku.c
//
#include <stdio.h>
#include <math.h>

#define SIZE  9
int cube[SIZE][SIZE] = {0};


int main() {
    int number = 0;
    int legal = 1;


    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &cube[i][j]);
            if (cube[i][j] > 9) {
                legal = 0;
                break;
            }
        }
    }//检查每个数字是否小于9

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            number = number + cube[i][j];
            for (int k = j + 1; k < 9; ++k) {
                if (cube[i][j] == cube[i][k]) {
                    legal = 0;
                    break;
                }
            }
        }
        if (number != 45) {
            legal = 0;
            break;
        }
        number = 0;
    }//检查每一行是否符合要求

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            number = number + cube[j][i];
            for (int k = j + 1; k < 9; ++k) {
                if (cube[j][i] == cube[k][i]) {
                    legal = 0;
                    break;
                }
            }
        }
        if (number != 45) {
            legal = 0;
            break;
        }
        number = 0;
    }//检查每一列是否正确

    for (int i = 0; i < 9; i = i + 3) {
        for (int j = 0; j < 9; j = j + 3) {
            number = pow(cube[i][j], 2) + pow(cube[i][j + 1], 2) + pow(cube[i][j + 2], 2) + pow(cube[i + 1][j], 2) +
                     pow(cube[i + 1][j + 1], 2) + pow(cube[i + 1][j + 2], 2) + pow(cube[i + 2][j], 2) +
                     pow(cube[i + 2][j + 1], 2) + pow(cube[i + 2][j + 2], 2);
            if (number != 285) {
                legal = 0;
                break;
            }

        }


    }


    if (legal) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

