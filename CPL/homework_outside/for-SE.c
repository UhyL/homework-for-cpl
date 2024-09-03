//
// Created by 27756 on 2022/12/15.
//
#include <stdio.h>

int main() {
  printf("My heart had been wandering: \n");
  printf("An ant found it\n");
  printf("It divided my heart into five parts\n");
  const char my_heart1[50] = "**     *       *  *      *  ******  ******";
  const char my_heart2[50] = "* *    *       *  *      *  *       *     ";
  const char my_heart3[50] = "*  *   *       *  *      *  ******  ******";
  const char my_heart4[50] = "*    * *       *  *      *       *  *     ";
  const char my_heart5[50] = "*     **  ******  ********  ******  ******";
  printf("When I found my heart again,\n");
  printf("it is:\n");
  printf("%s\n%s\n%s\n%s\n%s",my_heart1,my_heart2,my_heart3,my_heart4,my_heart5);
}
