#pragma once
#include<iostream>
using namespace std;
int test_atoi()
{
	string str;
	while (cin >> str) {
		int res = atoi(str.c_str());
		cout << "res = " << res;
	}
	return 0;
	
}