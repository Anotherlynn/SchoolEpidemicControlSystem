#pragma once

#include "stdafx.h"
#include "People.h"
#include "Class.h"
#include "Grade.h"
#include "School.h"
#include "ReadFile.h"
#include "community.h"

void create(void) {
	string filename = "../school1.txt";
	//cout << "请输入文件地址及文件名：" << endl;
	//cin >> filename;
	People* every;
	int num_of_peo;
	every = read_file(filename, num_of_peo);
	num num1 = num(filename);
	School school1 = School(filename, num1);
	school1.set_grade();
	school1.set_suspected();
}

