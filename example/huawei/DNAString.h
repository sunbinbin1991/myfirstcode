#pragma once
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int countGCNum(const char *input, int num) {
	int cnt = 0;
	for (size_t i = 0; i < num; i++)
	{
		char tmp = *(input + i);

		if (tmp == 'G' || tmp == 'C') {
			cnt++;
		}
	}
	return cnt;
}
//str.substr()
string getMaxSubString(string& input,int stringlen,int num) {
	string res;
	int MaxNum = -1;
	for (size_t i = 0; i < stringlen - num+1; i++)
	{ 
		string tmp(input.begin()+i, input.begin() +i+num);
		int cnt = countGCNum(tmp.c_str(), num);
		if (cnt > MaxNum) {
			res = tmp;
			MaxNum = cnt;
			printf("%s %d\n", tmp.c_str(), countGCNum(tmp.c_str(), num));
		}
	}
	return res;
}

int test_DNAString() {
	string input = "AAATCACGGAGAAACCAGGTCAGCTGTCTTTACCTCGC";
	int num = 19;
	//while (cin>>input>>num)
	{
		int len = strlen(input.c_str());
		string res = getMaxSubString(input, len, num);
		cout << res << endl;
	}
	return 0;
}
