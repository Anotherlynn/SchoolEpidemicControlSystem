#pragma once

#include <iostream>
#include "People.h"
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace std;

//根据输入的字符串数组建立一个People实例
People create_people(string* school)
{
	People each;
	string ID = school[0];
	char * id = new char[strlen(ID.c_str()) + 1];
	strcpy(id, ID.c_str());
	each = People(school[0], school[1], school[2], school[3], school[4], school[5], school[6]);
	return each;
}

//读入学生信息的txt文件，建立所有学生的People实例数组
People *read_file(string file_name, int & num_of_people)
{
	num_of_people = 0;
	fstream f(file_name);
	vector<string> words;
	string line;
	while (getline(f, line))
	{
		words.push_back(line);
	}

	string * xy = new string[words.size()];
	for (int j = 0; j < words.size(); j++) {
		xy[j] = words[j];
	}

	string **all = new string*[words.size()];

	People* everyone = new People[words.size()];
	for (int i = 0; i < words.size(); i++) {
		char *se = new char[1024];
		strcpy(se, xy[i].c_str());
		char *p = strtok(se, " ");
		int j = 0;
		string* one = new string[7];
		while (p) {
			one[j] = p;
			j++;
			//cout << p << endl;
			p = strtok(NULL, " ");
		}
		everyone[i] = create_people(one);
		num_of_people++;
	}
	return everyone;
}

//num类，读入学生信息文件，建立每个班学生数量的数组
class num {
public:
	int stu_num[3][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } };
	int class_num[3] = { 0,0,0 };
	int people_num;
	num(string filena)
	{
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
					stu_num[i][j] += 1;
					k++;
					ID = all[k].get_ID();
					id = new char[strlen(ID.c_str()) + 1];
					strcpy(id, ID.c_str());
				}
				class_num[i] += 1;
				j++;
			}
			i++;
		}
	}
};