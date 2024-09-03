//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
int main() {
    // const: constant
    const double PI = 3.14159;
    int radius = 10;

    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    printf("circumference = %.2f\narea = %.2f\n",//".2"表示小数点保留后两位
           circumference, area);

    return 0;
}