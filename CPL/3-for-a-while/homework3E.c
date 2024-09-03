//
// Created by 27756 on 2022/10/16.
//
#include <stdio.h>

int main() {
    int n = 0;
    int temp = 0;
    int a = 0, b = 0;
    char string[100001] = "";
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        scanf("%c", &string[i]);
    }

    for (int i = 1; i <= n / 2; ++i) {
        if (string[i] != string[n + 1 - i]) {
            if (string[i] == 63) {
                string[i] = string[n + 1 - i];
            } else {
                string[n + 1 -i] = string[i];
            }
        }
    }


    for (int i = 1; i <= n ; ++i) {
        if (string[i] == 63) {
            if (i <= n / 2) {
                printf("%.2d", temp);
                temp++;
            }
            else {
                temp--;
                a = temp / 10;
                b = temp % 10;
                printf("%d", b);
                printf("%d", a);
            }
        } else {
            printf("%c", string[i]);
        }

    }

    return 0;
}