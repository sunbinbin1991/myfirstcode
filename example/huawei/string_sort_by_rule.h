#pragma once
#include<iostream>
#include<vector>
using namespace std;

void test_case() {
	string str;
	while (cin >> str) {
		vector<char> res;
		for (int j = 0; j < 26; j++)
		{
			for (int i = 0; i < str.length; i++)
			{
				if ((str.at(i) - 'a') == j||(str.at(i) - 'A') == j){
					res.push_back(str.at(i));
				}
			}
		}//sort

		int M = 0;
		for (int i = 0; i<str.size(); i++)
		{
			if ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z'))
			{
				if (M<res.size())
				{
					cout << res[M];
					M++;
				}
			}
			else
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
}