#pragma once

#include <iostream>
#include <string>
using namespace std;

int SequenceSearch(string a[], string value, int n)
{
	int i;
	for (i = 0; i<n; i++)
		if (a[i] == value)
			return i;
	return -1;
}