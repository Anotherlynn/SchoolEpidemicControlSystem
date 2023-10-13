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
	//cout << "请输入文件地址及文件名：" << endl;
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
	printf("2020年，6月11日，北京新发地市场出现新冠疫情。随后，在切进口三文鱼的案板上检出新冠病毒，全国多地下架进口三文鱼。截至6月14日13时，北京市已累计报告62例确诊病例，发现均有北京新发地批发市场活动史或有关人员接触史。\n***        欢迎您的使用！       ***\n");
	while (1) {
		printf("***        请选择您的身份        ***\n1.普通用户 2.管理员 3.学生 0.退出系统\n");
		scanf("%d", &a);
		switch (a) {
		case 1:
			isAdmin = false;
			Stu();
			break;
		case 2:
			if (flag)
			{
				printf("请输入管理员密码。进入用户系统，直接输入1：\n");
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
						printf("密码错误次数达到三次！管理员账户已被锁定，请联系学校进行解锁!\n");
						break;
					}
					printf("密码输入错误！请重新输入.如果连续三次输入错误密码，管理员账户将被锁定！\n");
					scanf("%s", password);
				}
			}
			else
				printf("密码错误次数达到三次！管理员账户已被锁定，请联系学校进行解锁!\n");
			if (flag)
				isAdmin = true;

			char xt;
			cout << "请选择进入学校信息系统或地图系统" << endl;
			cout << "x, x ----- 学校信息系统" << endl;
			cout << "t, t ----- 地图系统" << endl;
			cin >> xt;

			if (xt == 'x')
			{
				char cmd;
				do
				{
					cout << endl << "请选择操作：" << endl;
					cout << "a, a ----- 显示疫情防控管理系统当前信息" << endl;
					cout << "b, b ----- 增加学生" << endl;
					cout << "c, c ----- 删除学生" << endl;
					cout << "d, d ----- 更改学生信息" << endl;
					cout << "e, e ----- 退出系统" << endl;
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
							cout << "该ID已经存在！" << endl;
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
							cout << "该ID不存在！" << endl;
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
						cout << "请输入要更改学生的ID：" << endl;
						cin >> ID2;
						int exis = school1.find_ID(ID2);
						if (exis == -1)
						{
							cout << "该ID不存在！" << endl;
							continue;
						}
						char* id2 = new char[strlen(ID2.c_str()) + 1];
						strcpy(id2, ID2.c_str());
						int gra = id2[1] - '0';
						int cla = id2[2] - '0';
						char cho;
						cout << "请选择要更改的信息：" << endl << "1 ----- 地址" << endl << "2 ----- 体温" << endl;
						cin >> cho;
						string cha;
						cout << "请输入新信息：" << endl;
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

			cout << "欢迎同学，请输入您的学号：" << endl;
			cin >> stuI;
			Dijkstra1(school1, stuI);
		case 0:
			printf("退出后所有数据将恢复原始状态，编辑后的数据会丢失。是否确认？如果确认，请在下方输入 QUEREN （大写），如果不确认，输入任意其他内容即可返回。\n");
			char code[100];
			scanf("%s", code); getchar();
			if (strcmp(code, CONFIRMATION) == 0)
			{
				printf("感谢使用，下次再见！\nCreated by 李欣怡、徐菡、唐仁凡 2020年6月All rights reserved.\n按回车键退出程序...\n");
				getchar();
				return 0;
			}
			else
				continue;
		default:
			printf("输入有误！请重新输入！\n");
			continue;
		}

	}





	return 1;
}


