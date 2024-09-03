//
// Created by 27756 on 2022/10/15.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str [100] = "";
    gets(str);

    for (int i = 0; i < 990; ++i) {
        if (str[i] == 32) {

        } else if  (str[i] == 0) {
            break;
        } else {
            printf("%c", str[i]);
        }

    }


    return 0;
}