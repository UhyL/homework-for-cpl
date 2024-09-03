//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
int main()
{
    int i1=1 ;
    int i2=0 ;
    printf("Enter a number:");
    scanf("%d",&i1);
    do {
        i1=i1/10;
        i2++;
    } while (i1>0);

    printf("The number has %d digits.",i2);
    return 0;

}
