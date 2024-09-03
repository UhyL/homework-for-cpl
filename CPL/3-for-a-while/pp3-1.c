//
// Created by 27756 on 2022/10/21.
//
#include <stdio.h>

#define LEN 8
int numbers[LEN] = {6, 5, 3, 1, 8, 7, 2, 4};

int main() {
    /**
     * bubble sort
     */
    int number = 1;
    int temp = 0;

    while (number < LEN) {
        for (int i = 0; i < LEN; ++i) {
            if(numbers[i] >= numbers[i + 1]) {
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i +1] = temp;
            }
        }
        number++;
    }

    for (int i = 0; i < LEN; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
