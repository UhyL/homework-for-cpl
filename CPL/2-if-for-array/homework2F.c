//
// Created by 27756 on 2022/10/9.
//
#include <stdio.h>

int main() {
    int n = 1;
    char string[10000001] = "handsome";
    int k = 1;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        scanf("%c", &string[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        printf("%c", string[k - 1 - i]);
    }
    for (int i = 0; i < n - k; ++i) {
        printf("%c", string[n - 1 - i]);
    }

    return 0;
}