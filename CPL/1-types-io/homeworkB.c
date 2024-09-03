//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
#include <math.h>
int main()
{
    double pi1 , pi2 ;
    pi1=(4*atan(1.0/5)- atan(1.0/239))*4;
    pi2= log(pow(640320,3)+744)*1.0/ sqrt(163);
    printf("%.15f\n%.15f\n", pi1 , pi2 );


    return 0;
}