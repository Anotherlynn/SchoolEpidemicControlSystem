#pragma once


#include "stdafx.h"
#include "Graph.h"


using namespace std;

#define CRT_SECURE_NO_WARNINGS

void Admin(void)   //管理员系统
{
	//system("clear");
	printf("欢迎进入管理员系统，请输入您需要进行的操作:\n");
	while (1)
	{
		int a;
		printf("1.地点介绍\n2.查找所属地点到附近医院的最短路径\n3.查找任意两个地点之间的最短路径 \n4.修改已有地点信息 \n5.添加新地点 \n6.删除地点 \n7.添加道路 \n8.删除道路 \n9.退出管理员系统 \n0.恢复初始数据\n");
		scanf("%d", &a);
		switch (a) {
		case 0:
			printf("确定要恢复初始数据吗？确认=1，其他数字=返回。\n");
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
			{
				printf("正在恢复...\n");
				for (long long i = 0; i < DELAY; i++);
				CreateGraph();
				printf("数据恢复完毕！\n");
				break;
			}
			else
				isAdmin = true;
			Admin();
			break;
		case 1:
			intro();
			break;
		case 2:
			Dijkstra();
			break;
		case 3:
			Floyd();
			break;
		case 4:
			alter();
			break;
		case 5:
			addSpot();
			break;
		case 6:
			delSpot();
			break;
		case 7:
			addPath();
			break;
		case 8:
			delPath();
			break;
		case 9:
			return;
		default:
			printf("输入错误，请重新输入！（1-9）\n");
			break;
		}
	}
}