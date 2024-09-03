//
// Created by 27756 on 2022/10/21.
//


// 作业会好些
/* 多维数组
 * 以表格的形式（行，列）
 * 更为详细在指针中讲解*/
//game-of-life  元胞自动机
//Any live cell living with two or three neighbors survives.
//Dead cell meets three live neighbors refreshes.
//Other live cells will die.
/* 思路：周围8个之和为2或3.
  *如何考虑边界情况：再开一圈数组（边长plus2）
  * 棋盘交替可只需两个棋盘，利用循环和赋值实现。
  */
//* Windows: clrscr(); (#include <conio.h>)  应该是这个，但单位是毫秒 可以延迟输出