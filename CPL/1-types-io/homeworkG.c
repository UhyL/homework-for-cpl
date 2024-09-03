//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
int main()
{
    int day , month , year , a , y , m , JDN;
    scanf("%d%d%d", &year , &month , &day);
    a= (14-month)/12;
    y=year+4800-a;
    m=month+12*a-3;
    JDN=day+ (153*m+2)/5+365*y+ y/4- y/100+ y/400-32045;
    printf("%d",JDN);
    return 0 ;
}