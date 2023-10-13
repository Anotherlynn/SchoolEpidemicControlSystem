#pragma once


#include <iostream>
#include <string>
#include "SequenceSearch.h"
#include "community.h"
using namespace std;

/*
人员People类，内含ID、姓名、性别、年级、班级、地址、体温和怀疑（及是否需要去医院检查）五个成员变量，
以及计算是否需要去医院的成员函数
*/
class People {
public:
	People(string a, string b, string c, string d, string e, string f, string g)
	{
		ID = a;
		name = b;
		sex = c;
		grade = d;
		classNo = e;
		address = f;
		tem = g;
	};


	People() {}
	People get_People();
	~People() {}
	void set_ID(int id) {
		ID = id;
	}
	void set_sex(string se) {
		sex = se;
	}
	void set_name(string na) {
		name = na;
	}

	//计算是否需要去医院，如果体温大于37.4度或者居住在高危小区二者满足其一，则需要
	void set_suspected() {
		int is_in = SequenceSearch(community, address, 10);
		int fever = -1;
		double temp = atof(tem.c_str());
		if (temp > 37.4)
			fever = 1;
		if (fever == 1 || is_in != -1)
			suspected = 1;
		if (fever == -1 && is_in == -1)
			suspected = -1;
	}
	string get_ID();
	string get_name();
	string get_sex();
	void details();
	string grade;
	string classNo;
	string address;
	string tem;
	int suspected;

private:
	string ID;
	string name;
	string sex;
};

inline string People::get_ID() {
	return ID;
}

inline string People::get_name() {
	return name;
}

inline string People::get_sex() {
	return sex;
}

void People::details() {
	cout << "ID: " << ID << endl;
	cout << "name: " << name << endl;
	cout << "sex: " << sex << endl;
}

People People::get_People() {
	int ID;
	cout << "Please enter the ID of the people:";
	cin >> ID;
	ID = ID;
	return *this;
}
