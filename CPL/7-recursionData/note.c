//
// Created by 27756 on 2022/11/11.
//
/* 首先写mergesort
 *递归的思想做排序
 *当递归到最小的元素(即只剩下一个元素)时进行merge操作
 * 思考如何一层层分解
 * 在得到原问题的解
 * */
/* Data Types
 * 不同类型提供不同的取值范围，以及使用方式
 * 目前接触int， double ， char ， bool
 * 整型和浮点型
 * 了解陷阱
 * short (int)
 * int
 * long (int)
 * long long (int) 规定至少八个字节
 * signed & unsigned 类型
 * 查头文件 #include <limits.h>
 * 查看类型的数字范围
 * 溢出 : 有符号溢出未定义行为
 *        无符号出现回绕现象：MAX + 1 = 0  1-2 = 0
 *        特别需要注意 ；混合使用有符号和无符号整型会出问题
 *        有符号和无符号运算时会先变成无符号的类型
 *        -1 = MAX -1
 *        明确知道用法可使用
 * typedef
 * 引入clock_t
 *
 * 可以使用 （类型）变量 进行 强制类型转换
 *
 * char : use only for representing characters
 * char 可以认为是更小的int ， 根据系统判断是否有符号
 *
 * 类型转换 Be careful about narrowing conversion
 * 类型提升 ：把操作数往大的提升
 * 函数定义时， 初始化 ， 赋值
 * 函数调用时
 * 函数返回时
 * double 和 int 容易转换
 *
 * float(F)  : float pi = 3.1415926F
 * 查看 #include <float.h>
 * EPSION 表示 最小的两个可表示数之间的gap
 * 很多程序都碰不到float
 * use math.h 尽可能的使用库里的函数
 *
 * under flow  / over flow
 * 太大或离零太近都无法表示
 * MIN 和 Ture_MIN（非规范化）
 * 有些浮点数无法精确表示
 * 不要两个浮点数比大小，除非你能接受
  */