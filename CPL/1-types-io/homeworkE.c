//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
int main()
{
    int number , a1 , a2 , a3 , a4 , a5   ;
    scanf("%d",&number);
    a1= number/10000 ;
    a2= number/1000%10 ;
    a3= number/100%10 ;
    a4= number/10%10 ;
    a5= number%10 ;
    printf("%d%d%d%d%d", a3 , a2 , a1 , a5 , a4 );
    return 0 ;
}