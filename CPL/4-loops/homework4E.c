//
// Created by 27756 on 2022/10/21.
//
#include <stdio.h>

int A[102][102] = {0};
int B[102][102] = {0};
int C[102][102] = {0};

int main() {
    int n, m, p;
    scanf("%d%d%d", &m, &n, &p);

    for (int i = 1; i <= m ; ++i) {
        for (int j = 1; j <=n ; ++j) {
            scanf("%d", &A[i][j]);
        }
    }//完成A的输入

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            scanf("%d", &B[i][j]);
        }
    }//完成B的输入

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= p; ++j) {
            for (int k = 1; k <=n ; ++k) {
                C[i][j] = C[i][j] +A[i][k]*B[k][j];
            }
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }//完成C的输出

    return 0;
}