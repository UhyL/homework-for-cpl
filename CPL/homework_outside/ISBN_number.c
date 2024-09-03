//
// Created by 27756 on 2022/10/26.
//
#include <stdio.h>

int main() {
    int part2, part3;
    int num[10];
    int legal = 0;
    int text_number = 0;
    scanf("%d", &num[0]);
    getchar();
    scanf("%d", &part2);
    getchar();
    scanf("%d", &part3);
    getchar();
    scanf("%d", &num[9]);

    num[1] = part2/100;
    num[2] = (part2%100)/10;
    num[3] = (part2%100)%10;

    num[4] = part3/10000;
    num[5] = (part3%10000)/1000;
    num[6] = ((part3%10000)%1000)/100;
    num[7] = (((part3%10000)%1000)%100)/10;
    num[8] = (((part3%10000)%1000)%100)%10;

    for (int i =1 ; i < 10; ++i) {
        text_number = text_number + i * num[i-1];
    }

    text_number = text_number % 11;

    if (text_number == 10) {
        if (num[9] != 88) {
            legal = 1;
        }
    } else {
        if ( text_number != num[9]) {
            legal = 1;
        }
    }

    if(legal == 0) {
        printf("Right");
        return 0;
    } else if (text_number == 10){
        printf("%d-%d%d%d-%d%d%d%d%d-%c", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7],
               num[8], text_number + 78);
    } else {
        printf("%d-%d%d%d-%d%d%d%d%d-%d", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7],
               num[8], text_number);
    }

    return 0;
}