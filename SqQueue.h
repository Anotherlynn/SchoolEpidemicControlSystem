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
	Class data[MAXSIZE];
	int front;
	int rear;
} SqQueue;


/* 队列初始化 */
Status InitQueue(SqQueue &Q)
{
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

/* 求队列长度 */
int QueueLength(SqQueue &Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* 新元素e 入队列 */
Status EnQueue(SqQueue &Q, Class e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}

/* 元素e出队列 */
Status DeQueue(SqQueue &Q, Class &e)
{
	if (Q.front == Q.rear) return ERROR;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
