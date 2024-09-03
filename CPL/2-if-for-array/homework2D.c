//
// Created by 27756 on 2022/10/8.
//
#include <stdio.h>

int main() {
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    int max = n;
    for (i = 0; n > 1; i++)
    {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        max = max > n ? max : n;
    }
    printf("%d %d", i, max);
    return 0;
}