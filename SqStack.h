#pragma once

#include <iostream>
using namespace std;
# define MAXSIZE 15
# define ERROR 0
# define OK 1
# define TRUE 1
# define FALSE 0
# define Null 0
typedef int Status;  /* Status �Ǻ������ͣ���ֵλ����ִ�н����״̬���룬��ERROR��OK��TRUE��FALSE�� */


typedef struct
{
	People data[MAXSIZE];
	int top;
}SqStack;


Status Push(SqStack &S, People e) // ���뺯��,���½��xѹ��ջS 
{
	if (S.top == MAXSIZE - 1) return ERROR;
	S.data[S.top + 1] = e;
	S.top++;
	return OK;
}

Status Pop(SqStack &S, People & e)  // ɾ������,��˳���L��ɾ����i����� 
{
	if (S.top == -1) return ERROR;
	e = S.data[S.top];
	S.top--;
	return OK;
}
