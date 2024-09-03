//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
int  main()
{
    int price ;
    int  a1 , a2 ;
    int  b1 , b2 ;
    int  c1 , c2 ;
    int  d1 , d2 ;
    int  e1 ;
    scanf("%d",&price);
    a1=price/50 , a2=price%50 ;
    b1=a2/20 , b2=a2%20 ;
    c1=b2/10 , c2=b2%10 ;
    d1=c2/5  , d2=c2%5 ;
    e1=d2;
    printf("%d\n%d\n%d\n%d\n%d\n",a1,b1,c1,d1,e1);
    return 0 ;


}