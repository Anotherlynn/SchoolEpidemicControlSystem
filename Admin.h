#pragma once


#include "stdafx.h"
#include "Graph.h"


using namespace std;

#define CRT_SECURE_NO_WARNINGS

void Admin(void)   //����Աϵͳ
{
	//system("clear");
	printf("��ӭ�������Աϵͳ������������Ҫ���еĲ���:\n");
	while (1)
	{
		int a;
		printf("1.�ص����\n2.���������ص㵽����ҽԺ�����·��\n3.�������������ص�֮������·�� \n4.�޸����еص���Ϣ \n5.����µص� \n6.ɾ���ص� \n7.��ӵ�· \n8.ɾ����· \n9.�˳�����Աϵͳ \n0.�ָ���ʼ����\n");
		scanf("%d", &a);
		switch (a) {
		case 0:
			printf("ȷ��Ҫ�ָ���ʼ������ȷ��=1����������=���ء�\n");
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
			{
				printf("���ڻָ�...\n");
				for (long long i = 0; i < DELAY; i++);
				CreateGraph();
				printf("���ݻָ���ϣ�\n");
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
			printf("����������������룡��1-9��\n");
			break;
		}
	}
}