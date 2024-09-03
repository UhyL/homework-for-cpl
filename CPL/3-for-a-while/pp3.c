//
// Created by 27756 on 2022/10/17.
//
#include <stdio.h>

int main()     {
    int n, k, temp,  l = 0;
    int string[100] = {0};
    scanf("%d%d", &n, &k);
    int r = n - 1;
    int p = k;
    int q = k;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &string[i]);
    }//读取数组

    for (; l < r -1;) {
        while (l < r -1) {
            if (string[l] >= string[k - 1]) {
                for (; r > k - 1; r--) {
                    if (string[r] < string[k - 1]) {
                        temp = string[l];
                        string[l] = string[r];
                        string[r] = temp;
                        temp = 0;
                        break;
                    }
                }
            }
            if (string[r] < string[k - 1]) {
                for (; l < k - 1; l++) {
                    if (string[l] >= string[k - 1]) {
                        temp = string[l];
                        string[l] = string[r];
                        string[r] = temp;
                        temp = 0;
                        break;
                    }
                }
            }
            if ((r - l) == 1) {
                break;
            }
            l++;
            r--;
        }
    }//遍历数组，使左右能交换的先进行交换，不能交换的仍然保存在数组中

    for (int i = 0; i < p-1; i++) {
        if (string[i] >= string[p-1]) {
            for (int j = i;j < p-1; ++j) {
                temp = string[j];
                string[j] = string[j + 1];
                string[j +1] = temp;

            }
            p--;
            i=0;
        }
    }//先遍历pivot左边的元素。若发现大于等于pivot的元素，通过依次交换的方式移动到pivot的右边，注意此时pivot的数组下标会减1
    if ((p == 2) && (string[0] >= string[1])) {
        temp = string[0];
        string[0] = string[1];
        string[1] = temp;
    }//发现上面的循环无法将pivot移动至最左边，所以在这里使用特殊情况



    for (int i = n-1; i > q-1; --i) {
        if (string[i] < string[q-1]) {
            for (int j = i; j > q-1; --j) {
                temp = string[j];
                string[j] = string[j - 1];
                string[j - 1] = temp;
            }
            q++;
            i=n-1;
        }
    }//同上左
    if ((q ==n-1) && (string[n-1] < string[n-2])) {
        temp = string[n-1];
        string[n-1] = string[n-2];
        string[n-2] = temp;
    }//同上左

    for (int i = 0; i < n; ++i) {
        printf("%d ", string[i]);
    }

    return 0;
}