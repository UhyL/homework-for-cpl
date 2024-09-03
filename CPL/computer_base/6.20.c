//
// Created by 27756 on 2022/10/15.
//
#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int string[32] = {0};
    int x = n;

    for (int i = 31; i >= 0; --i) {
        if (x % 2 == 1) {
            string[i]++;
        }
        x = x / 2;
        if (x == 0) {
            break;
        }
    }

    for (int i = 0; i <= 31; ++i) {
        printf("%d", string[i]);

    }

    return 0;
}