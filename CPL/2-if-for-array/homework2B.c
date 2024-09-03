//
// Created by 27756 on 2022/10/8.
//
#include <stdio.h>

int main() {
    int n = 0;
    int i = 1;
    int sum = 0;
    int sum1 = 1;
    int sum2 = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum1 = sum1 * (j % 10007);
            sum1 = sum1 % 10007;
        }
        sum1 = sum1 % 10007;
        sum = sum + sum1;
        sum1 = 1;
    }
    sum2 = sum % 10007;
    printf("%d", sum2);
    return 0;
}