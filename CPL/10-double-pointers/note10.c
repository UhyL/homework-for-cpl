//
// Created by 27756 on 2022/12/2.
//

// 双重指针
/**
 * Pointer Arrays
 * Pointers and 2D Arrays（指针和二维数组的关系）
 * Function Pointers（函数指针） 可指向一个函数，有什么用
 * 双重指针：很容易搞错，但不知道为什么，了解概念
 * 这节课比较难
 * 程序本身不是很复杂，但是概念很复杂
 * 很容易遇到程序很复杂，使用了二维指针数组或双重指针，需要概念清楚才能来理解
 *
 *
 *A：
 * 指针数组： 大的结构上是一个数组，但是数组中的每个元素是一个指针
 *
 * 选择排序：在剩下的数据中选出最小的
 *
 * 能够对字符串数组排序的选择排序
 * 实际上是数组的每一个元素放一个char*（指向一段连续空间的首地址）
 *（C语言规定方括号的优先级是高于*的优先级）
 *  char *musicians[len] = {
 *   （这里定义了一个数组，数组中的元素是char类型的一个指针）
 *  }
 *  此类型在函数调用时，应该也是char*arr[]的方式调用
 *  arr[i] 中的元素实际上是指针，及字符类数组的首地址
 *  *(arr + i)解引用后实际上还是一个数组
 *  arr可以理解为指针的指针、
 *  char arr[] : char * arr
 *  char *arr[] : char **arr(这个一般都不会使用)这就是双重指针的概念
 *   字符串大小以什么标准比较大小？
 *   交换字符串？（看起来不太可能发生的事情）
 *   但是交换指针的指向地址似乎会简单
 *   交换地址而非元素
 *   Void Swap(char **left, char **right)实际上是指向一个char*的指针
 *   所以应该是char **类型而非char *类型
 *   Void Swap(char **left, char **right) {
 *   char *temp = *left;  声明变量是char*的类型指向字符类型数组的首地址
 *   *left = *right;    left指针指向另一个指针所指的空间
 *   *right = temp;     temp是一个指针，temp指向的空间为*right所指向的空间
 *    }
 *    再拷贝上做操作行吗
 *    直接传递指针获得的只是这两个指针的拷贝
 *     想要改变指针的指向需要指针的首地址
 *
 *     关于const(在做类型转换的时候不要丢了const)
 *     const char *musician[len]这个数组里面包含很多指针，每个指针指向的字符串数组是一个const
 *     char *const musician[len]表示这个数组的内容是常量指针，即指针指向的区域不能更改
 *
 *B ： int main (int argc, char *argv[]) {
 *  (argc 帮助数传进参数的个数)
 *  (argv 记录传进的参数)
 *  argv[0] 运行程序的名字
 *  argv[1]……argv[argc -1] 记录传入的数据
 *  argv[argc] = NULL
 *  echo
 *  for (int i = 1, i < argc; i ++) {
 *  printf("%s\n",argv[i]);
 *  }
 *
 *  for(char**ptr = argv + 1； *ptr ！= NULL; ptr ++) {
 *  printf("%s\n", *ptr);
 *  }
 *  或者改为while类型的循环
 * }
 *
 *C ：指针和二维数组
 *  int[y][x] :{
 * [0]: ……
 * [~]：……
 * [y]: ……
 * }
 *
 * 二维数组的读法
 * int (table[])[cols]  （是左结合：即从左向右读）
 * 解释一下：C语言读取内容是需要基本功的
 * int *table[]: 表示一个table类型的数组，数组中的每个元素都是int*型的指针
 * int (*table)[]：二维数组的写法
 *
 * 本质上没有二维数组，只是数组中的每个元素还是一个数组
 * table[i][j]:*((*(table + i)) + j)是等价的
 *  指针类型是不同的table+i是指向数组的指针
 *  *(table + i)才是指向第一个元素的地址
 *   table是一个指针，指针指向一个数组
 *  本质上没有二维数组，都是一维数组
 *  table是指向元素的首地址，而这个元素又是一个数组
 * 如何为二维数组申请空间
 *  int *scores = malloc(rows * cols * sizeof(*scores))
 *  当作一维数组来使用
 *
 *  int (*scores)[cols] = malloc(rows * cols * sizeof(**scores))
 *  可正常当作二维数组使用
 *
 * free()；
 *下面两次课包括链表，结构体
 * 如何解释如此高超的东西
 * 语言设计的问题
 * 如何解读这些深奥的概念
 */

