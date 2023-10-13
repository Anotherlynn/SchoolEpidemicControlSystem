#pragma once

#include <iostream>
#include <string>
#include "Class.h"
#include "SqQueue.h"
#include "Grade.h"
#include "ReadFile.h"

using namespace std;

//shool��
class School {
public:
	int stu_num[3][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } };
	int class_num[3] = { 0,0,0 };
	int people_num;
	Class clas[3][5]; //��Ա����clas�����ڴ洢���а༶
	Grade grad[3]; //��Ա����grad�����ڴ洢�����꼶

	//���캯��������������ļ��Լ������ļ������numʵ������ÿ���༶��ѧ��������
	School(string filena, num num2)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
				stu_num[i][j] = num2.stu_num[i][j];
		}
		for (int i = 0; i < 3; i++)
			class_num[i] = num2.class_num[i];

		int num_of_p;
		People* all = read_file(filena, num_of_p);
		people_num = num_of_p;
		int i = 0, j = 0, k = 0;
		while (k < num_of_p)
		{
			string ID = all[k].get_ID();
			char * id = new char[strlen(ID.c_str()) + 1];
			strcpy(id, ID.c_str());
			j = 0;
			while (id[1] == i + 1 + '0')
			{
				while (id[1] == i + 1 + '0' && id[2] == j + 1 + '0')
				{
					string g(1, i + 1 + '0');
					string c(1, j + 1 + '0');
					clas[i][j] = Class(g, c, stu_num[i][j]);
					clas[i][j].num_of_students = 0;
					while (k - j * 12 - i * 60 < stu_num[i][j])
					{
						clas[i][j].add_student(all[k]);
						k++;
					}
					clas[i][j].get_suspected();
					if (k < num_of_p)
					{
						ID = all[k].get_ID();
						id = new char[strlen(ID.c_str()) + 1];
						strcpy(id, ID.c_str());
					}
					else break;
				}
				j++;
				if (j > 5)
					break;
			}
			i++;
			if (j > 5)
				break;
		}
	}

	School() {};
	~School() {};

	//��school������ѧ����Ѱ��ĳ��ID���ҵ��ͷ���1��δ�ҵ�����-1
	int find_ID(string Id)
	{
		char * id = new char[strlen(Id.c_str()) + 1];
		strcpy(id, Id.c_str());
		int gr = id[1] - '0';
		int cl = id[2] - '0';
		int wh = ListFind(clas[gr-1][cl-1].Students, Id);
		if (wh >=0 && wh < clas[gr - 1][cl - 1].num_of_students)
			return wh;
		else return -1;
	}

	//����clas��ʼ����school�е�grad��Ա����
	void set_grade()
	{
		for (int k = 0; k < 3; k++)
		{
			grad[k] = Grade(k);
		}
		for (int k = 0; k < 3; k++)
		{
			for (int m = 0; m < 5; m++)
			{
				grad[k].classes[m] = clas[k][m];

			}
		}
	}

	//��school�и���IDɾ��ĳ��ѧ��
	void delete_student(string ID)
	{
		char* id1 = new char[strlen(ID.c_str()) + 1];
		strcpy(id1, ID.c_str());
		int gr = id1[1] - '0';
		int cl = id1[2] - '0';
		grad[gr - 1].delete_student(ID);
		clas[gr - 1][cl - 1].delete_student(ID);
	}

	//��ʼ��clas��ÿ���༶��suspected_students
	void set_suspected()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				clas[i][j].get_suspected();
			}
		}
		for (int i = 0; i < 3; i++)
			grad[i].set_suspected_class();
	}

	//�ı�ѧ����Ϣ����ַ�����£�ʱ�����suspected�Ƿ���Ҫ�ı䣬��������Ӧ�ı�
	void change_suspected(string IDi, char cho, string cha)
	{
		char* id2 = new char[strlen(IDi.c_str()) + 1];
		strcpy(id2, IDi.c_str());
		int gra = id2[1] - '0';
		int cla = id2[2] - '0';
		int wh = ListFind(clas[gra - 1][cla - 1].Students, IDi);

		if (cho == '1')
		{
			string old_address = clas[gra - 1][cla - 1].Students.data[wh].address;
			string new_address = cha;
			clas[gra - 1][cla - 1].Students.data[wh].address = cha;
			if (SequenceSearch(community, old_address, 10) != -1 && SequenceSearch(community, new_address, 10) == -1)
			{
				clas[gra - 1][cla - 1].Students.data[wh].suspected = -1;
				clas[gra - 1][cla - 1].delete_suspected(IDi);
			}
			if (SequenceSearch(community, old_address, 10) == -1 && SequenceSearch(community, new_address, 10) != -1)
			{
				clas[gra - 1][cla - 1].Students.data[wh].suspected = 1;
				clas[gra - 1][cla - 1].add_suspected(clas[gra - 1][cla - 1].Students.data[wh]);
			}
		}
		if (cho == '2')
		{
			string old_tem = clas[gra - 1][cla - 1].Students.data[wh].tem;
			string new_tem = cha;
			clas[gra - 1][cla - 1].Students.data[wh].tem = cha;
			double old_temp = atof(old_tem.c_str());
			double new_temp = atof(new_tem.c_str());
			if (old_temp > 37.4 && new_temp <= 37.4)
			{
				clas[gra - 1][cla - 1].Students.data[wh].suspected = -1;
				clas[gra - 1][cla - 1].delete_suspected(IDi);
			}
			if (old_temp <= 37.4 && new_temp > 37.4)
			{
				clas[gra - 1][cla - 1].Students.data[wh].suspected = 1;
				clas[gra - 1][cla - 1].add_suspected(clas[gra - 1][cla - 1].Students.data[wh]);
			}
		}
	}

	//����Class���е�show_suspected()��������ʾ���а༶�Ľ���ȥҽԺ��ѧ��������Ϣ
	void show_suspected_all()
	{
		for (int j = 0; j < 3; j++)
			grad[j].show_suspected_class();
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				clas[i][j].show_suspected();
	}
};

void Dijkstra1(School schoo, string ID)
{
	int wh = schoo.find_ID(ID);
	if (wh == -1)
		cout << "û���ҵ���ID";
	else
	{
		char * id = new char[strlen(ID.c_str()) + 1];
		strcpy(id, ID.c_str());
		int gr = id[1] - '0';
		int cl = id[2] - '0';
		People som = schoo.clas[gr - 1][cl - 1].Students.data[wh];
		int sus = som.suspected;
		if (sus == 1)
		{
			cout << "������ȥҽԺ" << endl << "������С����ҽԺ�У�" << endl;
			string AD = som.address;
			char * ad = new char[strlen(AD.c_str()) + 1];
			strcpy(ad, AD.c_str());
			int a = (int)ad[0] - 96;
			while (a<1 || a>XFD.vn)
			{
				printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n", XFD.vn);
				scanf("%d", &a);
			}
			int final[Max];
			int P[Max];
			int D[Max];
			int i, j = 0, k, min, pre;
			final[a - 1] = 1;
			for (int i = 0; i < XFD.vn; i++)
			{
				D[i] = XFD.edge[a - 1][i];
				P[i] = a - 1;
			}
			D[a - 1] = 0; final[a - 1] = 1; P[a - 1] = -1;
			for (i = 1; i < XFD.vn; i++)
			{
				min = INFINITY + 1;
				for (k = 0; k < XFD.vn; k++)
					if (final[k] == 0 && D[k] < min)
					{
						j = k;
						min = D[k];
					}
				final[j] = 1;
				for (k = 0; k < XFD.vn; k++)
					if (final[k] == 0 && (D[j] + XFD.edge[j][k] < D[k]))
					{
						D[k] = D[j] + XFD.edge[j][k];
						P[k] = j;
					}
			}
			int judge = 1;
			for (i = 0; i < XFD.vn; i++)
			{
				if (i != a - 1)
				{
					if (D[i] != INFINITY)
					{
						judge = 0;
						printf("%d�� : %s", D[i], XFD.vex[i].name);
						pre = P[i];
						while (pre >= 0)
						{
							printf("<-%s", XFD.vex[pre].name);
							pre = P[pre];
						}
						printf("\n");
					}
				}
			}
			if (judge)
				printf("%s���κεص�䶼û�е�·!\n", XFD.vex[a - 1].name);
			printf("�ٴβ�ѯ������1�������������ּ����˳�\n");
			int flag;
			scanf("%d", &flag);
			if (flag == 1)
				Dijkstra();
		}
		if (sus == -1)
		{
			cout << "����ʱ����ҪȥҽԺ���, " << "��ע�ⰲȫ��" << endl;
		}
	}
}
