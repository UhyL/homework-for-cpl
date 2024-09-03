//
// Created by 27756 on 2022/10/8.
//
#include <stdio.h>
#include <math.h>

int main() {
    int n = 1;
    double x = 1.0;
    double sum = 0.0;
    double y = 0.0;
    scanf("%lf %d", &x, &n);
    for (int i = 0; i <= n; i++) {
        sum = sum + ((pow(-1, i) * pow(x, 2 * i + 1)) * 1.0) / (2 * i + 1);
    }
    y = 4 * sum;
    printf("%.10f", y);

    return 0;
}