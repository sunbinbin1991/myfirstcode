#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string add_string(const char* str1, const char* str2,bool isNagtive=false) {
	int num1 = strlen(str1);
	int num2 = strlen(str2);
	int max_num = std::max(num1, num2);
	int min_num = std::min(num1, num2);
	int add_flag = 0;
	string res;
	if (num1 < num2) {
		std::swap(str1, str2);
	}
	for (size_t i = 0; i <max_num; i++)
	{
		int index1 = max_num - i - 1;
		int index2 = min_num - i - 1;
		int re;
		if (i >= min_num) {
			re = *(str1 + index1) - '0' + add_flag;
		}
		else {
			re = *(str1 + index1) - '0' + *(str2 + index2) - '0' + add_flag;
		}
		if (re >= 10) {
			add_flag = 1;
			re = re % 10;
		}
		else {
			add_flag = 0;
		}
		res += re + '0';
	}
	if (add_flag) {
		res += '1';
	}
	if (isNagtive) {
		res += '-';
	}
	reverse(res.begin(), res.end());
	return res;
}

string minus_string(const char* str1, const char* str2, bool isSwap = false) {
	int num1 = strlen(str1);
	int num2 = strlen(str2);
	int max_num = std::max(num1, num2);
	int min_num = std::min(num1, num2);
	int min_flag = 0;
	string p1 = str1;
	string p2 = str2;
	string res;
	if (p1.compare(p2)!=1) {
		std::swap(str1, str2);
	}
	
	for (size_t i = 0; i <max_num; i++)
	{
		int index1 = max_num - i - 1;
		int index2 = min_num - i - 1;
		int re;
		if (i >= min_num) {
			re = *(str1 + index1) - '0' + min_flag;
		}
		else {
			re = *(str1 + index1) - '0' - (*(str2 + index2) - '0') + min_flag;
		}
		if (re >= 0) {
			min_flag = 0;
		}
		else {
			min_flag = -1;
			re = 10 + re;
		}
		res += re + '0';
		cout << "== " << res << endl;
	}
	if (min_flag==-1) {
		res += '-';
	}
	reverse(res.begin(), res.end());
	return res;
}

string addStringNums(string str1, string str2) {
	string res;
	if (str1.empty()) {
		return str2;
	}

	if (str2.empty()) {
		return str1;
	}

	char prefix1 = str1.at(0);
	char prefix2= str2.at(0);
	if (prefix1 == '-'&& prefix2 == '-') {
		//add
		string input1(str1.begin() + 1, str1.end());
		string input2(str2.begin() + 1, str2.end());
		res = add_string(input1.c_str(), input2.c_str(),true);

	}

	else if (prefix1 != '-'&&prefix2 == '-') {
		//minus
		string input1(str1.begin(), str1.end());
		string input2(str2.begin() + 1, str2.end());
		res = minus_string(input1.c_str(), input2.c_str());
	}

	else if (prefix1 == '-'&&prefix2 != '-') {
		//minus
		string input1(str1.begin() + 1, str1.end());
		string input2(str2.begin(), str2.end());
		res = minus_string(input1.c_str(), input2.c_str());
	}
	else {
		string input1(str1.begin(), str1.end());
		string input2(str2.begin(), str2.end());
		res = add_string(input1.c_str(), input2.c_str());
	}

	
	cout << "res " << res;

	return res;
}

void test_addStringNums() {
	string input1, input2;
	while (cin>>input1>>input2)
	{
		string res = addStringNums(input1.c_str(), input2.c_str());
		
		//cout << "res " << res;
	}
}
