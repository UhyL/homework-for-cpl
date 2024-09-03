//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
#include <math.h>
#include <ctype.h>//引入toupper是的头指令
/*要求：每组信息占一行
 *      各项信息使用\t间隔，\t表示使用"type"形成的空格
 *      各项信息遵循特定的格式要求
 *      */

int main() {
    char first_name[] = "Tayu";//字符串用双引号+方括号，C语言会自动在输入的字符串后面输入"\0"占用一个字符空间，"\0"表示字符串到这里结束了
    char last_name[] = "Lo";//方括号中的数字表示字符串的最大长度+1（因为"\0"占据了一个字符空间）
    char gender = 'm';//一个字符用单引号

    int birth_year = 1954;
    int birth_month = 7;
    int birth_day = 20;
    char weekday[] = "Tuesday";

    int c_score = 50;
    int music_score = 99;
    int medicine_score = 78;

    double mean = (c_score + music_score + medicine_score) / 3.0;
    double sd = sqrt(((pow(c_score - mean, 2)
                       + pow(music_score - mean, 2)
                       + pow(medicine_score - mean, 2))) / 3.0);//计算方差，sqrt计算方差
    int rank = 10;

    printf("%s %s \t %c\n"
           "%.2d-%d-%d \t %.3s.\n"//".3s."中".3"表示最多输出三个字符，s后的"."照常输出，在此表示“日期缩写”           ".2d"表示整数输出时最少要两位
           "%d \t %d \t %d\n"
           "%.1f \t %.2f %d%%\n",//"%%"表示输出一个%
           first_name, last_name, toupper(gender),//"toupper"可让小写变大写  加入头文件#includ <type.h>
           birth_month, birth_day, birth_year, weekday,
           c_score, music_score, medicine_score,
           mean, sd, rank);

    return 0;
}
/*备注：char 表示的字符本身就是一个又一个的数字，可对于一个字符进行加减乘除，但可能没什么意义
 *     C语言允许这么做，其设计初衷就是充分相信程序员
 *     字符"0"对应为48 "A"对应为65 "a"对应为97
 *参考阅读：https://en.cppreference.com/w/c/io/fprintf
 *         Chapter 12:<stdio.h>,P257~262
 *         */