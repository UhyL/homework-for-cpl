//
// Created by 27756 on 2022/10/26.
//
#include <stdio.h>
#include <math.h>

int main() {
    int R = 0;
    double S_O = 0.0;
    double S_taxi = 0.0;
    const double PAI = 3.14159265358979323;
    scanf("%d", &R);

    S_O = PAI * pow(R, 2);
    S_taxi = 2 * pow(R, 2);

    printf("%f\n%f", S_O, S_taxi);

    return 0;
}