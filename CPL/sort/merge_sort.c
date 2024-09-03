//归并排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 500005

int a[N], b[N];

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if ((j > r && i <= mid) || (i <= mid && a[i] <= a[j])) {
            b[k] = a[i++];
        }
        else {
            b[k] = a[j++];
        }
    }
    for (int k = l; k <= r; ++k) {
        a[k] = b[k];
    }
}

void mergeSort(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    mergeSort(1, n);
    for (int i = 1; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
    return 0;
}
/*
归并排序很快，非常的快
它快的原因在于相较于前面这几种排序算法，它利用二分序列的方式，将其中的一重本为n次的循环，变成了logn次，快了不少。
但是我们复习的重点并不在递归上，所以这里我们主要解析一下合并过程：
    合并过程说起来很简单，左边一个有序数组，右边一个有序数组，需要把这两个数组合起来，变成一个新的有序数组
    但是实现起来好像有点绕
    我们把问题分开来看：
    先开一个等长的空数组，用来存储合并出来的数组
    然后看这两个分开的数组
    如果两个数组都还有，那么比较这两个数组的最前面的还没有被添加的元素，选择更小的添加到当前合并数组的末尾
    如果其中一个数组没了，那么就继续塞另一个数组里面没有塞完的元素
    然后就得到了合并好的有序的数组，这个时候把这个数组拷贝到原来的位置上就行了。
*/