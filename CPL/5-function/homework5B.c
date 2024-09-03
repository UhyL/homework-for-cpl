//
// Created by 27756 on 2022/10/28.
//
#include <stdio.h>
#include <math.h>


int sum = 0;

/**
 * @param index 表示长度
 * @param base 表示底数
 * @return 返回值为前几项之和
 */

int capital(int index, int base);

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n ; ++i) {
        capital(i, t);
    }

    printf("%d", sum);
    return 0;
}



int capital(int index, int base) {
    for (int i = 1; i <= index ; ++i) {
        sum = sum + base * pow(10, i-1);
    }
    return sum;
}