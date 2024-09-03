//
// Created by 27756 on 2022/10/26.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[10000] = "";
    int arry[10000] = {0};
    scanf("%s",str);
    int n = 0, temp = 0;
    n = strlen(str);
    strncpy(arry, str, n);

    for (int i = 0; i < n; ++i) {
        temp = (temp + str[i]) % 9;
    }

    printf("%d", temp);

    return 0;

}