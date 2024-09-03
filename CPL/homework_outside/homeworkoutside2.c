//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
int main()
{
    double i1;
    double i2;
    printf("Please enter your real money:");
    scanf("%lf",&i1);
    if(i1<750)
    {
        i2=0.01*i1;
    }else if(i1<2250){
        i2=7.5+0.02*(i1-750);
    }else if(i1<3750){
        i2=37.5+0.03*(i1-2250);
    }else if (i1<5250){
        i2=82.5+0.04*(i1-3750);
    }else if (i1<7000){
        i2=142.5+0.05*(i1-5250);
    }else{
        i2=230+0.06*(i1-7000);
    }
    printf("Your real taxes is %f",i2);
    return 0;
}