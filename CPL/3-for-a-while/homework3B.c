//
// Created by 27756 on 2022/10/16.
//
#include <stdio.h>

int main() {
    int n = 0, x = 0, max = 0, number = 0;
    int string[123] = {0};

    scanf("%d", &n);
    getchar();

    for (int i = 1; i <= n; ++i) {
        scanf("%c", &x);
        string[x]++;
        max = (max > string[x] ? max : string[x]);
    }

    for (int i = 65; i <= 122; ++i) {
        string[i] = string[i] - max;
    }

    for (int i = 1; i <= max; ++i) {
        for (int j = 97; j <= 122; ++j) {
            if (string[j] > -max) {
                if (string[j] >= 0) {
                    printf("=");
                } else {
                    printf(" ");
                }
                string[j]++;
                if (string[j - 32] > -max) {
                    if (string[j - 32] >= 0) {
                        printf("= ");
                    } else {
                        printf("  ");
                    }
                    string[j - 32]++;
                } else {
                    printf(" ");
                }
            } else {
                if (string[j - 32] > -max) {
                    if (string[j - 32] >= 0) {
                        printf("=");
                    } else {
                        printf(" ");
                    }
                    string[j - 32]++;
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    for (int i = 65; i <= 90; ++i) {
        if ((string[i] > 0) && (string[i + 32] > 0)) {
            number = number + 3;
        } else if ((string[i] > 0) || (string[i + 32] > 0)) {
            number = number + 2;
        }
    }

    for (int i = 1; i <= number - 1; ++i) {
        printf("-");
    }

    printf("\n");

    for (int i = 97, j =0; i <= 122; ++i) {
        j = i -32;
        if (string[i] > 0) {
            printf("%c", i);
            if (string[i - 32] > 0) {
                printf("%c ", j);
            } else {
                printf(" ");
            }
        } else if (string[i - 32] > 0) {
            printf("%c ", j);
        }

    }

    return 0;
}