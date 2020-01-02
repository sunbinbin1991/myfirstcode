#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "string.h"

using namespace std;
std::string addZero2String(const std::string& str) {
	int len1 = strlen(str.c_str());
	int num_2_add_zero = 8 - len1 % 8;
	std::string res= str;
	while (num_2_add_zero--) {
		res += "0";
	}
	return res;
}

std::vector<std::string> splitOneString(const string& inputString) {
	std::vector<std::string> res;
	std::string str1 = inputString;
	int len1 = strlen(str1.c_str());
	while (len1 / 8 != 0) {
		len1 -= 8;
		std::string tempString(str1.begin(), str1.begin() + 8);
		std::string  tempString2(str1.begin() + 8, str1.end());
		str1 = tempString2;
		res.push_back(tempString);
	}
	//int num_2_add_zero = 8 - len1 % 8;
	if (len1 % 8 != 0) {
		std::string new_string(str1.end() - len1 % 8, str1.end());
		string addzerostring = addZero2String(new_string);
		res.push_back(addzerostring);
	}	
	return res;
}


std::vector<std::string> splitString(const string& str1, const string& str2) {
	std::vector<std::string> res;
	std::vector<std::string> res2;
	res = splitOneString(str1);
	res2 = splitOneString(str2);
	res.insert(res.end(), res2.begin(), res2.end());

	return res;
}

void test_splitstring() {
	string str;
	string str2;
	cin >> str;
	cin >> str2;
	std::vector<std::string > res = splitString(str, str2);
	for (auto & re : res) {
		printf("%s\n", re.c_str());
	}
	
}