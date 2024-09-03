//
// Created by 27756 on 2022/11/18.
//
/**
*   上机测试 关注环境配置
 *  妈妈我想回家
 *  上周讲了递归和数据类型
 *
 *  今天讲指针---一种数据类型
 *  普边认为最困难， 但是勇敢牛牛不怕困难
 *  今天只讲三句话 + 两句话
 *  指针和数组关系紧密
 *  指针：先理解C语言在理解C++
 *  &variable 表示取地址
 *  %p表示取地址
 *  一个变量可以做为左值或右值用
 *  左值：指变量占据的空间
 *  右值：指变量的值
 *  指针定义：A pointer is a variable that contains the address of a variable
 *  如何声明
 *  int *ptr_radius = &radius
 *  将radius的地址赋给ptr_radius
 *  type: int*; value: &radius; address: &ptr_radius
 *  很抽象呀
 *  *ptr_radios behaves like radius
 *  * 间接寻址/解引用运算符  *ptr_radius = radius 这两个东西等价
 *  可以通过修改*ptr_radius来改变radius的值
 *  指针变量作为左值和右值有啥含义
 *  左值：同等类型的变量赋值， 导致地址指向发生改变
 *  右值：
 *
 *  表达式：调用一个函数时f（）函数调用运算符
 *  数组名就是首元素的地址
 *  及array=&array[0]
 *  真是神奇
 *  int array[] 和 int * array 竟然是等价的
 *  怎么回事捏
 *
 *  arr[n]又是什么含义呢
 *  n 表示指针地址加上4*n 如果没有猜错的话应该是这个意思
 *  数组的空间是连续的
 *  array[i] = * （array + i）
 *  &array[i] = array + i
 *
 *  选择排序
 *  解决数组开大了浪费的问题
 *  变长数组不能用；怎么用捏
 *  malloc函数（加头文件<stdlib.h>）
 *  int *numbers = malloc(len * sizeof (int));
 *  int *numbers = malloc(len * sizeof (*numbers));
 *  好处：也没啥
 *  坏处：好像也没啥
 *
 *  如果空间不够了
 *  返回一个空指针 赶紧结束程序
 *  测试是不是空指针
 *
 *  如何测试
 *  if (numbers == NULL) {
 *  return 0;
 *  }
 *
 *  赋值后再使用这段空间
 *  for (int i  = 0; i < len , i ++) [
 *  scanf("%d", numbers + i )
 *
 *  自动变量：随着函数的释放一起释放，储存在函数的空间
 *
 *
 *  malloc定义的指针需要人为释放
 *  free（numbers）；
 *  不可多次释放，也不可释放后再访问
 *
 *  malloc 和 free 是一对一的
 *  如果强行释放也是未定义行为
 *
 *  一个数组名不是变量
 *  不能修改数组名指向的位置
 *  不可 array++；
 *   指针指向常量的定义方式
 *   const int * const_radius = &radius;上下是一个含义，指不能通过指针解引用修改
 *                                                    但还是可以更改地址中的数据
 *   int const * const_radius = &radius;
 *   int * const * const_raddius = &ra0dius;
 *   const int *const const _radius = &radius;
 *
*/