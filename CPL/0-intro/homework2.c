//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
int main()
{
    int  i1 , i2 , i3 , i4 , i5 , i6 , i7 , i8 , i9 , i10 , i11 , i12 , a , b , c ,x;
    printf("Please enter your first number:");
    scanf("%d",&i1);
    printf("Please enter afterwards five numbers:");
    scanf("%d%d%d%d%d",&i2,&i3,&i4,&i5,&i6);
    printf("Please continue to enter five numbers:");
    scanf("%d%d%d%d%d",&i7,&i8,&i9,&i10,&i11);
    printf("Please enter the last number:");
    scanf("%d",&i12);
    // Inputting is done
    a=i1+i3+i5+i7+i9+i11;
    b=i2+i4+i6+i8+i10;
    c=(3*a+b-1)%10;
    x=9-c;

    //Counting is done
    if(x==i12){
        printf("Pass!\n");
    }else{
        printf("Fail!\n");
    }
    return 0;
}
