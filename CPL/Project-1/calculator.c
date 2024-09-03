//
// Created by 27756 on 2022/11/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define len 400
#define Variable 1
#define Integer 2
#define Operator 3
#define Float 4
/**
 * 对任何输入都对应着一个输出，将这三种不同类型的值封装起来
 */
typedef struct {
  char name[32];
  enum {
	INT,
	FLOAT,
	ERROR
  } type;
  union {
	int iVal;
	double fVal;
  } val;
} Value;//第一种数据结构：表示最后答案的数据类型

typedef struct {
  int type;
  char str[32];
} Token;//第二种数据结构（用于储存）：包含输入结构的类型以及具体的内容

Token tokens[1024];
int count_tokens = 0;//用来表示tokens数据结构中含有token的数目

Value const_assignments[128];//用来储存原先被赋值的变量的基本信息
int count_assignments = 0;

Value new_assignments[128];//用于储存在表达式中涉及运算的变量
int count_new_assignments = 0;

Value error;

Value refresh;

Value value;//用于定义最后输出的答案类型

void printValue(Value v);

void Refresh(void);

Value eval(int l, int r);

Value evaAssign(int l, int r, int count_assignments1);

Value meetValue(Value v1, Value v2, char op);//合并运算

int check_parentheses(int l, int r);

int check_minus(int l, int r);

int op_index(int l, int r);

int main() {
  char *str = malloc(len * sizeof(*str));
  error.type = ERROR;
  refresh.type = INT;
  //处理输入部分
  while (gets(str) != NULL) {//输入完结束
	value.type = INT;
	int count_str = 0;//用来表示某个token中含有的字符个数
	int len_str = (int)strlen(str);//用len_str代表字符串的长度
	for (int j = 0; j < len_str; ++j) {
	  int start_step = j;
	  if ((*(str + j) > '0') && (*(str + j) <= '9')) {//当输入是非0的数字时
		int float_judge = 1;//定义一个判断符是否需要定义为float型
		tokens[count_tokens].type = Integer;//先定义类型为int型
		for (int k = j + 1; k <= len_str; ++k) {//循环判断每个字符
		  if ((*(str + k) >= '0') && (*(str + k) <= '9')) j = k;//如果还是数字，继续执行
		  else if ((*(str + k) == ' ') || (*(str + k) == '\0')) {//如果是空格，就退出
			j = k;
			break;
		  } else if ((*(str + k) == '.') && float_judge) {//当小数点只出现过一次的时候
			tokens[count_tokens].type = Float;
			float_judge = 0;
			j = k;
			if ((*(str + k + 1) == '\0') || (*(str + k + 1) == ' ')) {
			  value.type = ERROR;
			}
		  } else {//其他情况
			value.type = ERROR;
			break;
		  }
		}
		if (value.type == ERROR) break;
		else {
		  for (int k = start_step; k < j; ++k) {
			tokens[count_tokens].str[count_str++] = *(str + k);//如果没有问题则循环赋值
		  }
		}
		count_tokens++;
		count_str = 0;
	  } else if (*(str + j) == '0') {//当出现的是数字0时
		tokens[count_tokens].type = Float;
		if ((*(str + j + 1) == ' ') || (*(str + j + 1) == '\0')) {
		  tokens[count_tokens].type = Integer;
		  j = j + 1;
		} else if (*(str + j + 1) != '.') {//如果之后的不是'.'时
		  value.type = ERROR;
		} else {
		  for (int k = j + 2; k <= len_str; ++k) {//如果出现的是数字
			if ((*(str + k) >= '0') && (*(str + k) <= '9')) j = k;
			else if ((*(str + k) == ' ') || (*(str + k) == '\0')) {
			  j = k;
			  break;
			} else {
			  value.type = ERROR;
			  break;
			}
		  }
		}
		if (value.type == ERROR) break;
		else {
		  for (int k = start_step; k < j; ++k) {
			tokens[count_tokens].str[count_str++] = *(str + k);
		  }
		}
		count_tokens++;
		count_str = 0;
	  } else if ((*(str + j) == '=') || (*(str + j) == '+') || (*(str + j) == '-') || (*(str + j) == '*')
		  || (*(str + j) == '/')
		  || (*(str + j) == '(') || (*(str + j) == ')')) {//如果是操作符
		tokens[count_tokens].type = Operator;
		if ((*(str + j + 1) == ' ') || (*(str + j + 1) == '\0')) {
		  j = j + 1;
		} else {
		  value.type = ERROR;
		}

		if (value.type == ERROR) break;
		else {
		  for (int k = start_step; k < j; ++k) {
			tokens[count_tokens].str[count_str++] = *(str + k);
		  }
		  count_tokens++;
		  count_str = 0;
		}
	  } else if ((*(str + j) == '_') || ((*(str + j) >= 'A') && (*(str + j) <= 'Z'))
		  || ((*(str + j) >= 'a') && (*(str + j) <= 'z'))) {//关于变量的概念
		tokens[count_tokens].type = Variable;
		for (int k = j + 1; k <= len_str; ++k) {
		  if ((*(str + k) == '_') || ((*(str + k) >= 'A') && (*(str + k) <= 'Z'))
			  || ((*(str + k) >= 'a') && (*(str + k) <= 'z'))
			  || ((*(str + k) >= '0') && (*(str + k) <= '9')))
			j = k;
		  else if ((*(str + k) == ' ') || (*(str + k) == '\0')) {
			j = k;
			break;
		  } else {
			value.type = ERROR;
			break;
		  }
		}
		if (value.type == ERROR) break;
		else {
		  for (int k = start_step; k < j; ++k) {
			tokens[count_tokens].str[count_str++] = *(str + k);
		  }
		  count_tokens++;
		  count_str = 0;
		}
	  } else {
		value.type = ERROR;
	  }
	}
	//成功将词法正确的表达式输入程序
	//开始进行数据的处理
	if (value.type == ERROR) {
	  printf("Error\n");
	  for (int j = 0; j < count_tokens; ++j) {
		tokens[j].type = 0;
		for (int i = 0; tokens[j].str[i] != '\0'; ++i) {
		  tokens[j].str[i] = '\0';
		}
	  }
	  count_tokens = 0;
	} else {
	  int count_assignments1 = 0;
	  printValue(evaAssign(0, count_tokens - 1, count_assignments1));
	  //一行代码涉及的变量变化:如果是已经存在的变量进行更新；如果是不存在的变量进行储存
	  for (int j = 0; j < count_tokens; ++j) {
		tokens[j].type = 0;
		for (int i = 0; tokens[j].str[i] != '\0'; ++i) {
		  tokens[j].str[i] = '\0';
		}
	  }
	  count_tokens = 0;
	}
  }
  free(str);
  return 0;
}

void printValue(Value v) {
  switch (v.type) {
	case INT: {
	  printf("%d\n", v.val.iVal);
	  Refresh();
	  break;
	}
	case FLOAT: {
	  printf("%.6f\n", v.val.fVal);
	  Refresh();
	  break;
	}
	case ERROR: {
	  printf("Error\n");
	  for (int i = 0; i < count_new_assignments; ++i) {
		new_assignments[i] = refresh;
	  }
	  count_new_assignments = 0;
	  break;
	}
  }
}//打印最后的答案

Value eval(int l, int r) {
  if (l > r) {//如果左下标比右下标大的话
	return error;
  } else if (l == r) {//如果表达式中只存在一个tokens时
	if (tokens[l].type == Integer) {//如果是int类型
	  Value int_op;
	  int_op.type = INT;
	  int sum_number = 0;
	  int len_int_tokens = (int)strlen(tokens[l].str);
	  for (int i = 0; i < len_int_tokens; ++i) {
		sum_number = sum_number + (tokens[l].str[i] - '0') * (int)pow(10, len_int_tokens - 1 - i);
	  }
	  int_op.val.iVal = sum_number;
	  return int_op;
	} else if (tokens[l].type == Variable) {//如果是变量类型
	  for (int i = 0; i < count_assignments; ++i) {
		if (strcmp(tokens[l].str, const_assignments[i].name) == 0) {
		  return const_assignments[i];
		}
	  }
	  return error;
	} else if (tokens[l].type == Float) {//如果是浮点数类型
	  Value float_op;
	  float_op.type = FLOAT;
	  double sum_number = 0;
	  int float_index = 0;//标记小数点的位置
	  int len_float_tokens = (int)strlen(tokens[l].str);
	  for (int i = 0; i < len_float_tokens; ++i) {
		if (tokens[l].str[i] == '.') {
		  float_index = i;
		  break;
		}
	  }
	  for (int i = 0; i < float_index; ++i) {
		sum_number = sum_number + (tokens[l].str[i] - '0') * pow(10, float_index - 1 - i);
	  }
	  for (int i = float_index + 1; i < len_float_tokens; ++i) {
		sum_number = sum_number + (tokens[l].str[i] - '0') / pow(10, i - float_index);
	  }
	  float_op.val.fVal = sum_number;
	  return float_op;
	} else {
	  return error;
	}
  } else if (check_parentheses(l, r)) {
	return eval(l + 1, r - 1);
  } else if (check_minus(l, r)) {
	Value minus_op;
	Value change_op = eval(l + 1, r);
	minus_op.type = change_op.type;
	if (change_op.type == INT) {
	  minus_op.val.iVal = -change_op.val.iVal;
	} else if (change_op.type == FLOAT) {
	  minus_op.val.fVal = -change_op.val.fVal;
	} else {
	  return error;
	}
	return minus_op;
  } else {//如果即非自反也非被括号包围
	if (!op_index(l, r)) {//如果找不到主运算符
	  return error;
	} else {
	  return meetValue(eval(l, op_index(l, r) - 1), eval(op_index(l, r) + 1, r), tokens[op_index(l, r)].str[0]);
	}
  }
}//分析tokens（l ~ r）

Value meetValue(Value v1, Value v2, char op) {
  Value v3 = v1;
  Value v4 = v2;
  if ((v3.type == ERROR) || (v4.type == ERROR)) {
	return error;
  } else {
	Value sum_value;
	if (v3.type != v4.type) {
	  sum_value.type = FLOAT;
	  if (v3.type == INT) {
		switch (op) {
		  case '+':sum_value.val.fVal = v3.val.iVal + v4.val.fVal;
			break;
		  case '-':sum_value.val.fVal = v3.val.iVal - v4.val.fVal;
			break;
		  case '*':sum_value.val.fVal = v3.val.iVal * v4.val.fVal;
			break;
		  case '/':sum_value.val.fVal = v3.val.iVal / v4.val.fVal;
			break;
		  default:return error;
		}
	  } else {
		switch (op) {
		  case '+':sum_value.val.fVal = v3.val.fVal + v4.val.iVal;
			break;
		  case '-':sum_value.val.fVal = v3.val.fVal - v4.val.iVal;
			break;
		  case '*':sum_value.val.fVal = v3.val.fVal * v4.val.iVal;
			break;
		  case '/':sum_value.val.fVal = v3.val.fVal / v4.val.iVal;
			break;
		  default:return error;
		}
	  }
	} else {
	  if (v3.type == INT) {
		sum_value.type = INT;
		switch (op) {
		  case '+':sum_value.val.iVal = v3.val.iVal + v4.val.iVal;
			break;
		  case '-':sum_value.val.iVal = v3.val.iVal - v4.val.iVal;
			break;
		  case '*':sum_value.val.iVal = v3.val.iVal * v4.val.iVal;
			break;
		  case '/':sum_value.val.iVal = v3.val.iVal / v4.val.iVal;
			break;
		  default:return error;
		}
	  } else {
		sum_value.type = FLOAT;
		switch (op) {
		  case '+':sum_value.val.fVal = v3.val.fVal + v4.val.fVal;
			break;
		  case '-':sum_value.val.fVal = v3.val.fVal - v4.val.fVal;
			break;
		  case '*':sum_value.val.fVal = v3.val.fVal * v4.val.fVal;
			break;
		  case '/': sum_value.val.fVal = v3.val.fVal / v4.val.fVal;
			break;
		  default:return error;
		}
	  }
	}
	return sum_value;
  }
}//进行四则运算

int check_parentheses(int l, int r) {
  if ((tokens[l].str[0] != '(') || (tokens[r].str[0]) != ')') {
	return 0;
  } else {
	int left_parentheses_count = 0;
	for (int i = l + 1; i < r; ++i) {
	  if (tokens[i].str[0] == '(') {
		left_parentheses_count++;
	  } else if (tokens[i].str[0] == ')') {
		if (left_parentheses_count == 0) {
		  return 0;
		} else {
		  left_parentheses_count--;
		}
	  }
	}
	if (left_parentheses_count > 0) {
	  return 0;
	} else {
	  return 1;
	}
  }
}//检测表达式是否被括号包围

int check_minus(int l, int r) {
  if (tokens[l].str[0] == '-') {
	for (int i = l + 1; i <= r; ++i) {
	  if (tokens[i].str[0] == '(') {
		int another_index = i + 1;
		int judge = 1;
		for (int j = i + 1; j <= r; ++j) {
		  if (check_parentheses(i, j)) {
			another_index = j;
			judge = 0;
			break;
		  }
		}
		i = another_index;
		if (judge) {
		  return 0;
		}
	  } else if (tokens[i].str[0] == '+') {
		return 0;
	  } else if (tokens[i].str[0] == '-') {
		if ((tokens[i - 1].str[0] != '+') && (tokens[i - 1].str[0] != '-') && (tokens[i - 1].str[0] != '*')
			&& (tokens[i - 1].str[0] != '/')) {
		  return 0;
		}
	  }
	}
	return 1;
  } else {
	return 0;
  }
}//用于判断负号是否为自反符号

int op_index(int l, int r) {
  int main_op_index = l;
  for (int i = l; i <= r; ++i) {
	if (tokens[i].type == Operator) {
	  if (tokens[i].str[0] == '(') {
		int another_index = i + 1;
		int judge = 1;
		for (int j = i + 1; j <= r; ++j) {
		  if (check_parentheses(i, j)) {
			another_index = j;
			judge = 0;
			break;
		  }
		}
		i = another_index;
		if (judge) {
		  return 0;
		}
	  } else if (tokens[i].str[0] == '+') {
		main_op_index = i;
	  } else if (tokens[i].str[0] == '-') {
		if (i > 0) {
		  if ((tokens[i - 1].str[0] != '-') && (tokens[i - 1].str[0] != '+') && (tokens[i - 1].str[0] != '*')
			  && (tokens[i - 1].str[0] != '/')) {
			main_op_index = i;
		  }
		}
	  } else if ((tokens[i].str[0] == '*') || (tokens[i].str[0] == '/')) {
		if ((tokens[main_op_index].str[0] != '+') && (tokens[main_op_index].str[0] != '-')) {
		  main_op_index = i;
		}
	  }
	}
  }
  if (main_op_index == l) {
	return 0;
  } else {
	return main_op_index;
  }
}//用于查找主运算符

Value evaAssign(int l, int r, int count_assignments1) {
  if (l > r) {
	return error;
  }
  int judge = 0;//用于判断是否有等号
  int equal_index = l;
  for (int i = l; i <= r; ++i) {
	if (tokens[i].str[0] == '=') {
	  judge = 1;
	  equal_index = i;
	  break;
	}
  }
  if (judge) {
	if ((equal_index == l + 1) && (tokens[equal_index - 1].type == Variable)) {
	  count_assignments1++;
	  count_new_assignments = count_assignments1 > count_new_assignments ? count_assignments1 : count_new_assignments;
	  Value temp_value = evaAssign(equal_index + 1, r, count_assignments1);
	  strcpy(new_assignments[count_assignments1 - 1].name, tokens[equal_index - 1].str);
	  new_assignments[count_assignments1 - 1].type = temp_value.type;
	  if (temp_value.type == INT) {
		new_assignments[count_assignments1 - 1].val.iVal = temp_value.val.iVal;
	  } else {
		new_assignments[count_assignments1 - 1].val.fVal = temp_value.val.fVal;
	  }
	  return temp_value;
	} else {
	  return error;
	}
  } else {//如果没有等号直接返回eval分析函数
	return eval(l, r);
  }
}//判断表达式的形式

void Refresh(void) {
  for (int i = 0; i < count_new_assignments; ++i) {
	int index = 0;
	int new_or_old = 0;
	for (int j = 0; j < count_tokens; ++j) {
	  if (strcmp(new_assignments[i].name, const_assignments[j].name) == 0) {
		index = j;
		new_or_old = 1;
		break;
	  }
	}
	if (new_or_old) {
	  const_assignments[index] = new_assignments[i];
	  new_assignments[i] = refresh;
	} else {
	  const_assignments[count_assignments++] = new_assignments[i];
	  new_assignments[i] = refresh;
	}
  }
  count_new_assignments = 0;
}//一行代码涉及的变量变化:如果是已经存在的变量进行更新；如果是不存在的变量进行储存；如果是错误表达式直接舍弃这组数据