// HighSchool1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "People.h"
#include "Class.h"
#include "Grade.h"
#include "School.h"
#include "ReadFile.h"
#include "community.h"
#include "Graph.h"
#include "Admin.h"
#include "User.h"

using namespace std;

#define CRT_SECURE_NO_WARNINGS



int main()
{
	CreateGraph();

	string filename = "school1.txt";
	//cout << "�������ļ���ַ���ļ�����" << endl;
	//cin >> filename;
	People* every;
	int num_of_peo;
	every = read_file(filename, num_of_peo);
	num num1 = num(filename);
	School school1 = School(filename, num1);
	school1.set_grade();
	school1.set_suspected();
	string stuI;

	int a;
	printf("2020�꣬6��11�գ������·����г������¹����顣������н���������İ����ϼ���¹ڲ�����ȫ������¼ܽ��������㡣����6��14��13ʱ�����������ۼƱ���62��ȷ�ﲡ�������־��б����·��������г��ʷ���й���Ա�Ӵ�ʷ��\n***        ��ӭ����ʹ�ã�       ***\n");
	while (1) {
		printf("***        ��ѡ���������        ***\n1.��ͨ�û� 2.����Ա 3.ѧ�� 0.�˳�ϵͳ\n");
		scanf("%d", &a);
		switch (a) {
		case 1:
			isAdmin = false;
			Stu();
			break;
		case 2:
			if (flag)
			{
				printf("���������Ա���롣�����û�ϵͳ��ֱ������1��\n");
				char password[20];
				scanf("%s", password); getchar();
				if (strcmp(password, "1") == 0)
				{
					isAdmin = false;
					Stu();
					break;
				}
				int count = 0;
				while (strcmp(password, PASSWORD) != 0)
				{
					count++;
					if (count >= 3)
					{
						flag = 0;
						printf("�����������ﵽ���Σ�����Ա�˻��ѱ�����������ϵѧУ���н���!\n");
						break;
					}
					printf("���������������������.���������������������룬����Ա�˻�����������\n");
					scanf("%s", password);
				}
			}
			else
				printf("�����������ﵽ���Σ�����Ա�˻��ѱ�����������ϵѧУ���н���!\n");
			if (flag)
				isAdmin = true;

			char xt;
			cout << "��ѡ�����ѧУ��Ϣϵͳ���ͼϵͳ" << endl;
			cout << "x, x ----- ѧУ��Ϣϵͳ" << endl;
			cout << "t, t ----- ��ͼϵͳ" << endl;
			cin >> xt;

			if (xt == 'x')
			{
				char cmd;
				do
				{
					cout << endl << "��ѡ�������" << endl;
					cout << "a, a ----- ��ʾ������ع���ϵͳ��ǰ��Ϣ" << endl;
					cout << "b, b ----- ����ѧ��" << endl;
					cout << "c, c ----- ɾ��ѧ��" << endl;
					cout << "d, d ----- ����ѧ����Ϣ" << endl;
					cout << "e, e ----- �˳�ϵͳ" << endl;
					do
					{
						cmd = getchar();
					} while ((cmd != 'a' && cmd != 'b' && cmd != 'c' && cmd != 'd' && cmd != 'e'));
					if (cmd == 'a')
					{
						school1.show_suspected_all();
					}
					if (cmd == 'b')
					{
						string ID;
						string name;
						string sex;
						string grade;
						string classNo;
						string address;
						string tem;
						cout << "\nplease input the student information: " << endl << "ID: " << endl;
						cin >> ID;
						int exist = school1.find_ID(ID);
						if (exist != -1) {
							cout << "��ID�Ѿ����ڣ�" << endl;
							continue;
						}
						cout << "\nname: " << endl;
						cin >> name;
						cout << "\nsex" << endl;
						cin >> sex;
						cout << "\ngrade" << endl;
						cin >> grade;
						cout << "\nclass number: " << endl;
						cin >> classNo;
						cout << "\naddress" << endl;
						cin >> address;
						cout << "\ntemperature: " << endl;
						cin >> tem;
						People newStu = People(ID, name, sex, grade, classNo, address, tem);
						int g = stoi(grade) - 1;
						int c = stoi(classNo) - 1;
						school1.clas[g][c].add_student(newStu);
						school1.clas[g][c].num_of_students++;
						if (SequenceSearch(community, address, 10))
							school1.clas[g][c].add_suspected(newStu);
						school1.set_grade();
						school1.set_suspected();
					}
					if (cmd == 'c')
					{
						string ID1;
						cout << "\nplease input the student information: " << endl << "ID: " << endl;
						cin >> ID1;
						int wh = school1.find_ID(ID1);
						if (wh == -1)
						{
							cout << "��ID�����ڣ�" << endl;
							continue;
						}
						char* id1 = new char[strlen(ID1.c_str()) + 1];
						strcpy(id1, ID1.c_str());
						int gr = id1[1] - '0';
						int cl = id1[2] - '0';
						int old_s = school1.clas[gr - 1][cl - 1].Students.data[wh].suspected;
						if (old_s == 1)
						{
							school1.clas[gr - 1][cl - 1].Students.data[wh].suspected = -1;
							school1.clas[gr - 1][cl - 1].delete_suspected(ID1);
						}
						school1.clas[gr - 1][cl - 1].delete_student(ID1);
						school1.delete_student(ID1);
					}
					if (cmd == 'd')
					{
						string ID2;
						cout << "������Ҫ����ѧ����ID��" << endl;
						cin >> ID2;
						int exis = school1.find_ID(ID2);
						if (exis == -1)
						{
							cout << "��ID�����ڣ�" << endl;
							continue;
						}
						char* id2 = new char[strlen(ID2.c_str()) + 1];
						strcpy(id2, ID2.c_str());
						int gra = id2[1] - '0';
						int cla = id2[2] - '0';
						char cho;
						cout << "��ѡ��Ҫ���ĵ���Ϣ��" << endl << "1 ----- ��ַ" << endl << "2 ----- ����" << endl;
						cin >> cho;
						string cha;
						cout << "����������Ϣ��" << endl;
						cin >> cha;
						school1.change_suspected(ID2, cho, cha);
						school1.clas[gra - 1][cla - 1].change_student(ID2, cho, cha);
					}
					if (cmd == 'e')
						break;
				} while (cmd != 'e');
			}
			if (xt == 't')
			{
				Admin();
			}

			break;
		case 3:

			cout << "��ӭͬѧ������������ѧ�ţ�" << endl;
			cin >> stuI;
			Dijkstra1(school1, stuI);
		case 0:
			printf("�˳����������ݽ��ָ�ԭʼ״̬���༭������ݻᶪʧ���Ƿ�ȷ�ϣ����ȷ�ϣ������·����� QUEREN ����д���������ȷ�ϣ����������������ݼ��ɷ��ء�\n");
			char code[100];
			scanf("%s", code); getchar();
			if (strcmp(code, CONFIRMATION) == 0)
			{
				printf("��лʹ�ã��´��ټ���\nCreated by �����������ա����ʷ� 2020��6��All rights reserved.\n���س����˳�����...\n");
				getchar();
				return 0;
			}
			else
				continue;
		default:
			printf("�����������������룡\n");
			continue;
		}

	}





	return 1;
}


