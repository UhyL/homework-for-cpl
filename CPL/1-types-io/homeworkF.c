//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
int main()
{
    const double G=6.674e-11 ;
    const double M=77.15 ;
    double m ;
    double r ;
    double N ;
    scanf("%lf %lf", &m , &r);
    N=(G*M*m)/(r*r);
    printf("%.3e",N);

    return 0;
}