//
// Created by 27756 on 2022/11/18.
//
#include <stdio.h>
#include <stdlib.h>
#define len 8

int main() {
  int In_put = 0;

  int * number = &In_put;
  float * number1 =&In_put;

  scanf("%x", &In_put);



  printf("%d\n%u\n%f\n%.3e", *number, *number, *number1,*number1);


  return 0;
}
