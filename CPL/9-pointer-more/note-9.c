//
// Created by 27756 on 2022/11/26.
//
/*写程序malloc忘了free
 * 小程序不会造成内存泄露
 * 大程序的时候要注意
 */
//在windows下CTRL+Z不奏效时，输入重定向
/*指针和字符串-专题
 *访问了不该访问的地方：segv/sigsegv
 *有可能被储存在只读的空间里，如果强行更改出现未定义行为
 *指针减法的含义
 *dest[i] = *(dest + i) = *(dest ++)
 *解引用和加加结合
 *怎么解释：先做了加加再做了解引用
 *查看优先级
 * dest++的意思是对dest进行加加，但返回值确是加加之前的值
 * 前缀返回值是加加后的值
 * 运算符的优先级值得考虑
 * 在cpp reference上查找
 * 表示空字符还是使用'\0'
 * c标准库写法，返回值是dest的好处在于方便直接进行计算长度
 *strlen (strcpy(dest, src))直接进行复制和计算长度
 *如何理解最开始的意思
 *
 *strcpy 假设足够的空间来将src放入dest
 * 比较 如果大了则返回正 如果小了则返回负 如果相等返回零
 *
 *
 * C语言中没有规定char是否有符号
 *
 * 情况很多的情况下
 * 分析清楚十分重要、
 * 这么多种情况如何分析
 * 在这种情况下 /0 可以在ASCII码中 表示为 0
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main () {
  int len = 3;
  char   *str = malloc(3 * sizeof(*str));
}