//
// Created by 27756 on 2022/10/16.
//
#include <stdio.h>

int main() {
    int n, k, temp, l = 0;
    int string[100] = {0};
    scanf("%d%d", &n, &k);
    int r = n - 1;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &string[i]);
    }
    int pivot = string[k - 1];

    while (l != r) {
        while(l != r) {
            if ((l == r) || (string[l] >= pivot)) {
                break;
            }
            l++;
        }

        while(l != r) {
            if((l == r) || (string[r] <pivot)) {
                break;
            }
            r--;
        }
        if(l != r) {
            temp = string[l];
            string[l] = string[r];
            string[r] = temp;
            if (l == k-1) {
                k = r + 1;
            }
        }




    }

    for (int i = 0; i < k - 1; i++) {
        if (string[i] >= pivot) {
            temp = string[i];
            string[i] = string[k - 1];
            string[k - 1] =temp;
            break;
        }
    }





    for (int i = 0; i < n; ++i) {
        printf("%d ", string[i]);
    }

    return 0;
}
