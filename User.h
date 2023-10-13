#pragma once

#include "stdafx.h"
#include "Graph.h"

void Stu(void)   //用户系统
{
	//system("clear");
	printf("欢迎进入用户查询系统，请输入您需要进行的操作:\n");
	while (1)
	{
		int a;
		printf("1.地点介绍 \n2.查找所属地点到附近医院的最短路径 \n3.查找任意两个地点之间的最短路径 \n4.退出用户系统\n");
		scanf("%d", &a);
		switch (a) {
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
			return;
		default:
			printf("输入错误，请重新输入（1，2，3，4）！\n");
			break;
		}
	}
}