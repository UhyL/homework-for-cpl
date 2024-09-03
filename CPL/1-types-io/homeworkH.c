//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
#include <math.h>
int main()
{
    int p , q;
    double x;
    scanf("%d%d", &p , &q);
    //if(p>0) {
     //    x = pow(-q / 2.0 + sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)), 1 / 3.0)
       //     - pow(q / 2.0 + sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)), 1 / 3.0);
    //}else if (q>0){
     //   x =- pow(q / 2.0 - sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)), 1 / 3.0)
     //           -pow(q / 2.0 + sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)), 1 / 3.0);
    //}else{
     //   x = pow(-q / 2.0 + sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)), 1 / 3.0)
     //       + pow(-q / 2.0 - sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)), 1 / 3.0);
    //}
    //printf("%.3f",x);
    //return 0;

    x = cbrt(-q / 2.0 + sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)))
        + cbrt(-q / 2.0 - sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)));
    printf("%.3f",x);
    return 0;

}