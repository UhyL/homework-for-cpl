//
// Created by 27756 on 2022/12/17.
//
// 函数的声明和实现要分开
/**
 * .h的头文件一般都是声明
 * .c头文件一般是实现
 * <>如果是C语言函数库的头文件时使用
 * ""如果是自己声明的函数头文件进行使用
 */

/**
 * 面向声明来实现
 * 先构建框架
 * 再实现框架中的每个函数
 */
/**
* 链表：指针和结构体的结合
 * 添加节点，删除节点  往往是改变指针的指向
 * A：单向链表
 * B：双向链表：可以顺着指针向前或者向后访问
 * C:循环链表： 最后一个节点指向头节点而非空指针
 * D:双向循环链表：
 * 先声明一个结构体
 *  typedef struct node {
 *  int val;
 *  struct node *next;
 *  } Node;
 *  Node *head;
 *  Node *tail;
 * 只需要头尾指针即可访问整个单向循环链表
 *所以为了提高代码的可读性：
 * typedef struct list{
 *  Node *head;
 *  Node *tail;
 * } Linked_list;
 *
 * 需要的操作
 * 定义操作：
 * 添加节点：
 *   所谓添加，即是对链表的指针做出改变
 *   调整指针的指向（需要确定实现时候指针更改的顺序）
 *   （如何高效实现需要认真思考）
 * 需要好好理解链表几步操作的作用
 *
 *
 * 初始化循环链表；
 * 销毁链表；
 * 在任何指定的地方插入一个节点
 * 在指针中找val为特点值的那个节点
 * 删减节点：
 *  所谓删减，其实也是对指针发生改变
 *  想要删除node节点
 *  将node之前的指针指向node指向的区域
 * 如何得到prev节点
 * 如果是单向链表:
 * 设计delete函数时实际是找到需要删除的node之前的那个节点
 * next，cur和prev
 * 定位到cur和next
 * Node *cur = prev -> next;
 * Node *next = cur ->next;
 * prev->next = next;
 * 如果恰好动了head 和 tail 指针时
 * 如果删除的就是head节点：
 *
 * 如果删除除的就是tail节点时：
 *
 * 如果被删掉的即是head也是tail时：
 * 只剩下一个节点了
 * head和tail都要指向空指针
 *
 * 还有哪里有问题：
 *（1）如果是空的链表 ，什么动作都不做
 *     可以和只有一个元素的链表头尾指针的情况类似
 *（2）原本被删掉的节点需要即时的free掉
 * 遍历链表：
 * 先拿到头指针
 * 再顺着next查找
 * （何时结束：判断next）
 *
*/

//SIGSEGV：segmentation fault（指针常见错误，越界访问了不该访问的空间）
/*写完链表要看是否具有普适性
 * 比如空链表
 *
 * 先考虑通用的再考虑特殊性（空链表或者只有一个节点的链表）
 *  一般情况和特殊情况的共同部分需要提出
 *  如何判断一个循环链表是否为空
 */

/**
*assert的含义：需要引用函数库<assert.h>
 * 先判断传入的条件是否成立，如果成立进行下一步，如果不成立程序终止报错
 *一般在debug的时候使用,进行正常实现时一般会禁用
 */
/**
* ll.h的实现
*/

/**
*  #include 如何工作的：
 * 将文件内容拷贝一份替换这一行
 * 为了避免出现这种问题
 * 在声明的时候添加三行
 * #ifndef……
 * #define……
 *
 * #enddef……（具体的名字唯一且最好有意义，clion中直接命名为文件路径）
*/

/**
*链表的更多内容需要更多的了解
*期末机试会考捏
*课程网站会有相关教材的讲解
*/