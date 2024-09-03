//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
int main() {
    const double MOL = 6.02e23;//科学计数法"e"
    const int MOL_PER_GRAM = 32;
    int mass = 6;

    double quantity = mass * 1.0 / MOL_PER_GRAM * MOL;//*1.0是变浮点数常用的技巧

    printf("quantity = %.3e\nquantity = %.5g\n",//科学计数法表示".3e指用科学计数法且小数点保留3位" ".5g表示用科学计数法且保留有效位数为5位"
           quantity, quantity);//详见 cppreference

    return 0;
}