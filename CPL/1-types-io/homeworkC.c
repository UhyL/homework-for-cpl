//
// Created by 27756 on 2022/10/1.
//
#include <stdio.h>
int main()
{
    char month[10];
    int day , year , hour , minute , second  ;
    char weekday[10];
    scanf("%s%d%d%s%d%d%d", month , &day , &year , weekday , &hour , &minute , &second);
    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d ", weekday , month , day , hour , minute , second , year);
    return 0;
}