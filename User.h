#pragma once

#include "stdafx.h"
#include "Graph.h"

void Stu(void)   //�û�ϵͳ
{
	//system("clear");
	printf("��ӭ�����û���ѯϵͳ������������Ҫ���еĲ���:\n");
	while (1)
	{
		int a;
		printf("1.�ص���� \n2.���������ص㵽����ҽԺ�����·�� \n3.�������������ص�֮������·�� \n4.�˳��û�ϵͳ\n");
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
			printf("����������������루1��2��3��4����\n");
			break;
		}
	}
}