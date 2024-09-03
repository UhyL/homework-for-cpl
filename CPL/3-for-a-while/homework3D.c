//
// Created by 27756 on 2022/10/16.
//
#include <stdio.h>
#include <math.h>

int main() {
    int N = 0, len = 0, sum = 0, legal = 1;
    scanf("%d%d", &len, &N);
    getchar();
    char string[31] = "";

    for (int i = 0; i < len; ++i) {
        scanf("%c", &string[i]);

    }

    if (N <= 10) {
        for (int i = 0; i < len; ++i) {
            if (string[i] > (N + 47)) {
                legal = 0;
                break;
            } else {
                sum = sum + (string[i] - 48) * pow(N, len - 1 - i);
            }

        }
    } else {
        for (int i = 0; i < len; ++i) {
            if ((string[i] <= 57) && (string[i] >= 48)) {
                sum = sum + (string[i] - 48) * pow(N, len - 1 - i);
            } else if ((string[i] <= 54 + N) && (string[i] >= 65)) {
                sum = sum + (string[i] - 55) * pow(N, len - 1 - i);
            } else {
                legal = 0;
                break;
            }

        }

    }

    if (legal == 0) {
        printf("Error");
    } else {
        printf("%d", sum);
    }

    return 0;
}