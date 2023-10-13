#pragma once

#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;



string* dangerCommunity(int nu)
{
	string* dc = new string[nu];
	Risk risk = Risk(XFD);
	risk.sortRisk();
	int k = 0;
	for (k; k < nu; k++)
	{
		dc[k] = risk.danger[k] + 'a' - 1;
	}
	return dc;
}




string community[10] = {"c", "d", "j" };