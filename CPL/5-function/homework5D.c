//
// Created by 27756 on 2022/10/28.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/**
 * 用于计算进制下的每一部分
 * @param n 表示p，q，r
 * @param a 表示进制
 * @return 返回值为计算的结果
 */

int counting(int n, int a);

/**
  * 布尔函数用于表示判断条件（p，q，r的每一位不能大于该进制数）
  * @param n 表示p，q，r
  * @param a 表示进制数
  * @return 返回值为真假
  */

bool Standard(int n, int a);

int main() {
    int p, q, r;
    scanf("%d%d%d", &p, &q, &r);
    for (int i = 2; i <= 40; ++i) {
        if ((Standard(p, i) && Standard(q,i) && Standard(r,i)) == 1) {
            if ((counting(p, i) * counting(q, i)) == counting(r, i)) {
                printf("%d", i);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}

int counting(int n, int a) {
    int sum;
    if (n < 10) {
        sum = n * pow(a, 0);
    } else {
        int j = n / 10, k = n % 10;
            sum = j * pow(a, 1) + k * pow(a, 0);
    }
    return sum;
}


bool Standard(int n, int a){
    if (n < 10) {
        if (n >= a) {
            return false;
        }
    } else {
        int j = n / 10, k = n % 10;
        if ((j >= a) || (k >= a)) {
            return false;
        }
    }
    return true;
}