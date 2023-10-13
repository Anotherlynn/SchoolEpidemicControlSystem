#pragma once

#include <iostream>
#include <string>
#include "SqList.h"
#include "SqStack.h"
#include "People.h"
using namespace std;

/*
班级类，存储每个班的学生信息，有年级、班级号、学生列表、怀疑的学生栈这几个成员变量；
成员函数有：初始化学生列表、增加学生、删除学生、改变学生信息、初始化怀疑学生的栈、显示怀疑学生、增加怀疑学生以及删除怀疑学生
*/
class Class {
public:
	string grade;
	string classNo;
	int num_of_students;
	SqList Students;
	SqStack suspected_students;

	Class(string gra, string clas, int num)
	{
		grade = gra;
		classNo = clas;
		num_of_students = num;

	}
	Class() {};
	~Class() {};

	//初始化学生列表
	void init_students(People* stu)
	{
		Students.length = 0;
		int i = 0;
		for (i = 0; i < num_of_students; i++)
		{
			Students.data[i] = stu[i];
			Students.length++;
		}
	}

	//增加学生
	void add_student(People stu)
	{
		Students.data[num_of_students] = stu;
		num_of_students += 1;
	}

	//删除学生
	void delete_student(string stu_ID)
	{
		ListDelete(Students, stu_ID);
		num_of_students -= 1;
	}

	//改变学生信息，可以改变住址和体温
	void change_student(string stu_ID, char item, string ch)
	{
		int i = ListFind(Students, stu_ID);
		int old_s = Students.data[i].suspected;
		if (item == '1')
		{
			string old_a = Students.data[i].address;
			Students.data[i].address = ch;
			if ((SequenceSearch(community, ch, 10) != 1) && (SequenceSearch(community, old_a, 10) == 1))
			{
				delete_suspected(stu_ID);
				Students.data[i].suspected = -1;
			}
			if ((SequenceSearch(community, ch, 10) == 1) && (SequenceSearch(community, old_a, 10) != 1))
			{
				Students.data[i].suspected = 1;
				add_suspected(Students.data[i]);
			}
		}
		if (item == '2')
		{
			double old_temp = atof(Students.data[i].tem.c_str());
			Students.data[i].tem = ch;
			double new_temp = atof(ch.c_str());
			if (old_temp > 37.4 && new_temp <= 37.4)
			{
				delete_suspected(stu_ID);
				Students.data[i].suspected = -1;
			}
			if (old_temp <= 37.4 && new_temp > 37.4)
			{
				add_suspected(Students.data[i]);
				Students.data[i].suspected = 1;
			}
		}
		if (item != '1' && item != '2')
		{
			cout << "输入信息有误，请重新输入1或2" << endl;
		}
		int new_s = Students.data[i].suspected;
		if (old_s == 1 && new_s != 1)
		{
			delete_suspected(stu_ID);
		}
	}

	//初始化怀疑学生栈
	void get_suspected()
	{
		suspected_students.top = -1;
		int i = 0;
		for (i; i < num_of_students; i++) {
			Students.data[i].set_suspected();
			if (Students.data[i].suspected == 1)
				Push(suspected_students, Students.data[i]);
		}
	}

	//显示怀疑的学生
	void show_suspected()
	{
		int i;
		cout << grade << "年级" << classNo << "班" << "目前建议去医院检查的同学有：" << endl;
		for (i = suspected_students.top; i >= 0; i--)
		{
			cout << suspected_students.data[i].get_ID() << "  " << suspected_students.data[i].get_name() << "  " << suspected_students.data[i].address << " " << suspected_students.data[i].tem << endl;
		}
		cout << endl;
	}

	//增加怀疑学生
	void add_suspected(People a)
	{
		Push(suspected_students, a);
	}

	//删除怀疑学生
	void delete_suspected(string ID1)
	{
		char* id1 = new char[strlen(ID1.c_str()) + 1];
		strcpy(id1, ID1.c_str());
		int wh;
		if (id1[3] == '0')
		{
			wh = id1[4] - '0';
		}
		if (id1[3] == '1')
		{
			int t = id1[4] - '0';
			wh = 10 + t;
		}
		SqStack s; //定义新栈s并初始化
		s.top = -1;
		int i = 0;
		//逐个判断当前suspected_students栈中的学生的ID是否等于需要删除的学生的ID，如果不相等就入s栈
		while (i < suspected_students.top + 1)
		{
			string ID2 = suspected_students.data[i].get_ID();
			char* id2 = new char[strlen(ID2.c_str()) + 1];
			strcpy(id2, ID2.c_str());
			int wh2 = 0;
			if (id2[3] == '0')
			{
				wh2 = id2[4] - '0';
			}
			if (id2[3] == '1')
			{
				int t = id2[4] - '0';
				wh2 = 10 + t;
			}
			if (wh2 != wh)
				Push(s, suspected_students.data[i]);
			i++;
		}
		suspected_students = s;
	}
};
