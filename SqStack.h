#pragma once

#include <iostream>
using namespace std;
# define MAXSIZE 15
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0
# define Null 0
typedef int Status;  /* Status 是函数类型，其值位函数执行结果的状态代码，如ERROR、OK、TRUE、FALSE等 */


typedef struct
{
	People data[MAXSIZE];
	int top;
}SqStack;


Status Push(SqStack &S, People e) // 插入函数,将新结点x压入栈S 
{
	if (S.top == MAXSIZE - 1) return ERROR;
	S.data[S.top + 1] = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S, People & e)  // 删除函数,从顺序表L中删除第i个结点 
{
	if (S.top == -1) return ERROR;
	e = S.data[S.top];
	S.top--;
	return OK;
}
