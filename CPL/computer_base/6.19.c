//
// Created by 27756 on 2022/10/15.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[100] = "";
    gets(str);

    for (int i = 0; i < 100; ++i) {
        if ((str[i] >= 97) && (str[i] <= 122)) {
            str[i] = str[i] - 32;
            printf("%c", str[i]);
        } else if (str[i] != 0) {
            printf("%c", str[i]);
        } else{
            break;
        }

        
    }

    return 0;
}