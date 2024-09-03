//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
#include <math.h>

int main() {
    const double PI = 3.14159;
    int radius = 100;

    // surfaceArea
    double surface_area = 4 * PI * pow(radius, 2);//引入math函数时需要在CMAKE中链接
    double volume = 4.0 / 3 * PI * pow(radius, 3);

    // 15: minimum width  +表示右对齐   -表示左对齐
    printf("%-15.4f : surface_area\n%-15.4f : volume\n",
           surface_area, volume);

    return 0;
}