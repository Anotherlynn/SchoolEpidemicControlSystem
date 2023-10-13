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
	Class data[MAXSIZE];
	int front;
	int rear;
} SqQueue;


/* ���г�ʼ�� */
Status InitQueue(SqQueue &Q)
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

/* ����г��� */
int QueueLength(SqQueue &Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* ��Ԫ��e ����� */
Status EnQueue(SqQueue &Q, Class e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

/* Ԫ��e������ */
Status DeQueue(SqQueue &Q, Class &e)
{
	if (Q.front == Q.rear) return ERROR;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
