//
// Created by 27756 on 2022/10/14.
//
#include <stdio.h>

int main() {
    int string[2001] = {0};

    int len = 0;
    scanf("%d", &len);

    for (int i = 1; i <= len; ++i) {
        for (int j = i; j <= len; ++j) {
            if (j % i == 0) {
                if (string[j] == 0) {
                    string[j] = 1;
                } else {
                    string[j] = 0;
                }
            }
        }
    }

    for (int i = 1; i < len; ++i) {
        if (string[i] == 1) {
            printf("%d ", i);
        }
    }

    return 0;

}