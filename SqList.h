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

typedef struct   /* 顺序表SqList数据类型定义 */
{
	People data[MAXSIZE];
	int length;
}SqList;

Status ListDelete(SqList &L, string s)  /* 删除函数,从顺序表L中删除某个元素*/
{
	if (L.length == 0)
	{
		cout << "表为空！" << endl;
		return ERROR;
	}
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i].get_ID() == s)
		{
			L.data[i].address = '1';
			L.data[i].tem = '1';
			L.data[i].suspected = -1;
			return OK;
		}
	}
	return -1;
}

int ListFind(SqList &L, string s)
{
	char* id = new char[strlen(s.c_str()) + 1];
	strcpy(id, s.c_str());
	int wh = -1;
	if (id[3] == '0')
	{
		wh = id[4] - '0';
	}
	if (id[3] == '1')
	{
		int t = id[4] - '0';
		wh = 10 + t;
	}
	return wh - 1;
}
