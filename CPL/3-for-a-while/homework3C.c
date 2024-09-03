//
// Created by 27756 on 2022/10/15.
//
#include <stdio.h>

int main() {
    int string[501] = {0};
    int k = 0;
    int n = 0;
    int p = 0;
    int x = 0;
    scanf("%d%d", &n, &k);
    x=n;

    while (x > 1) {
        x = n;
        for (int j = 1; j <= n; ++j) {
            if (string[j] == 0) {
                p++;
                if (p == k) {
                    string[j] = 1;
                    p = 0;
                }
            }

        }
        for (int i = 1; i <= n; ++i) {
            if (string[i] == 1) {
                x--;
            }

        }


    }


    for (int i = 1; i <= n; ++i) {
        if (string[i] == 0) {
            printf("%d", i);
        }

    }

    return 0;


}