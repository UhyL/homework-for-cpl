//
// Created by 27756 on 2022/11/4.
//
/*递归：思维上的不适应
 * 很难，但不是重点
 * 可以用大学四年了解
 * 考核时不会出现递归，平时作业可能会有
 *
 * 语法特别简单:在自己的函数调用自己
 * ？？：为什么捏 怎么敢的 怎么做到的 有没有可能一直调用
 * 语法上不限制（C语言可以使用） main 函数 可以调用 main 函数
 * warning ：不要在main 函数中调用main 函数
 * 为什么要用递归 ：
 *  1. 本质一样， 但不完全一样 （我要解决一个任务，依赖于更小的任务）
 *  直到规模最小的任务（不需要再分解了）
 *  2. what's a smaller task?
 *  3. how to solve the task given the solution to the smaller one?
 *  4. what is the smallest task?
 *  5.按照从下往上的方法来写
 *  6.从上往下思考(thinking recursively , thinking like a computer)
 */

// 调用一个函数 ： 生成一个栈帧， 函数完成时栈帧消失
//求数组中元素的个数 sizeof array / sizeof (int)
// sizeof 求数组占用的空间  sizeof int 求int 类型 所占空间
//sizeof array / sizeof array [0]
//递归运算时重复计算效率较差
//递归思维 跟着动画写一下


