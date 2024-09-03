//
// Created by 27756 on 2022/9/30.
//
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
    char first_name[10];//最多只能有9个字符的字符串
    char last_name[10];
    char gender;

    int birth_year;
    int birth_month;
    int birth_day;
    char weekday[10];

    int c_score;
    int music_score;
    int medicine_score;
    int rank;

    scanf("%9s%9s %c %d-%d-%d %9s %d%d%d %*f%*f %d%%",//"s"表示字符串，"c"表示字符  用"-"匹配掉输入的"-"   "%%"匹配掉输入的%
          first_name, last_name, &gender,//&存放到gender所在的位置中去  使用类似first_name这种语法本身就含地址
          &birth_year, &birth_month, &birth_day, weekday,//在这里除了有方括号的都要加地址"&"
          &c_score, &music_score, &medicine_score,
          &rank);
/*备注：scanf函数不是很安全，用户输入的不规范会导致系统崩溃
 *     未被赋值的变量时垃圾值
 *     %s：先忽略用户输入前面的空白符，从第一个非白符开始扫描，一直扫描非空白符直至下一个空白符为止，"s"表示字符串
 *    空白符可以匹配任 %c：不会忽略空白符，需要空白符以匹配用户输入的空白符（可以是零个或任意一个），也就是说scanf中的一个意长度空白符也可以匹配换行符等
 *     %d：先忽略掉可能有的空白符，匹配下一个整数
 *     %lf: 先忽略前面的空白符，匹配下一个double类型的值，其中l指存储f的size，如果用"*f"（表示只识别不储存），可不需要"l"
 *     %9s：指只选取输入的9位，剩下的只识别匹配不存储
 *
 * 参考阅读：https://en.cppreference.com/w/c/io/fsanf
 *          Chapter12:<stdio.h>,P263~P268
 *          */




    double mean = (c_score + music_score + medicine_score) / 3.0;

    double sd = sqrt(((pow(c_score - mean, 2)
                       + pow(music_score - mean, 2)
                       + pow(medicine_score - mean, 2))) / 3.0);


    printf("%s %s \t %c\n"
           "%.2d-%d-%d \t %.3s.\n"
           "%d \t %d \t %d\n"
           "%.1f \t %.2f %d%%\n",
           first_name, last_name, toupper(gender),
           birth_month, birth_day, birth_year, weekday,
           c_score, music_score, medicine_score,
           mean, sd, rank);

    return 0;
}
