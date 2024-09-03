//冒泡排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 10005

int a[N];

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i > 1; --i) {
        for (int j = 1; j <= i; ++j) {
            if (a[i] < a[j]) {
                swap(&a[i], &a[j]);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
    return 0;
}
/*

呃，冒泡排序是这样的：
把数组想象成一串气泡，气泡的大小取决于那个位置上数字的大小
而我们将一个数组排序（默认从小到大），就是希望排在右边的泡泡比左边的泡泡都要大
怎么解决这个问题呢？
我们使用“冒泡的方式”：
    从第一个泡泡开始往后看，如果这个泡泡比后面的泡泡要大，那就将它进行“上浮”操作，也就是将这个泡泡和它后面那个泡泡交换位置。
    然后我们看向第二个泡泡，作相同的处理。
    这样从头看到尾，我们就会发现，上浮到最右端的，一定是前面序列当中最大的那个泡泡。
    像这样多次进行上浮操作（因为之前上浮到顶端的泡泡已经不会再移动，所以可以不再管它），我们最终就能够得到有序的数组

*/