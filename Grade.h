#pragma once

#include <iostream>
#include <string>
#include "Class.h"
#include "SqQueue.h"
using namespace std;

//年级类
class Grade {
public:
	int num_of_class;
	int grade;
	Class classes[5];
	SqQueue suspected_class;
	Grade(int gra, int num = 5)
	{
		num_of_class = num;
		grade = gra;
	}
	Grade() {};
	~Grade() {};
	void delete_student(string ID)
	{
		char* id = new char[strlen(ID.c_str()) + 1];
		strcpy(id, ID.c_str());
		int gr = id[1] - '0';
		int cl = id[2] - '0';
		classes[cl - 1].delete_student(ID);
	}

	void set_suspected_class()
	{
		InitQueue(suspected_class);
		int i = 0;
		for (i; i < num_of_class; i++)
		{
			if (classes[i].suspected_students.top != -1)
				EnQueue(suspected_class, classes[i]);
		}
	}

	void show_suspected_class()
	{
		int i = suspected_class.front;
		int j = 0;
		cout << grade + 1 << "年级" << "目前关注的班级有：" << endl;

		for (i = suspected_class.front; i <= suspected_class.rear; i++)
		{
			cout << suspected_class.data[i].classNo << "  ";
		}
		cout << endl;
	}

	void add_suspected_class(Class c)
	{
		EnQueue(suspected_class, c);
	}

	void delete_suspected_class(string class_no)
	{
		SqQueue q;
		InitQueue(q);
		int i = 0;
		while (i < QueueLength(suspected_class))
		{
			if (suspected_class.data[i].classNo != class_no)
				EnQueue(q, suspected_class.data[i]);
			i++;
		}
		suspected_class = q;
	}
};

