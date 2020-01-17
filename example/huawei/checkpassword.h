#pragma once
#include <iostream>
#include <string>

using namespace std;

bool isLetterProper(const string & str) {
	bool hasNum = false;
	bool hasBigLatter = false;
	bool hasSmallLatter = false; 
	bool hasOther = false;

	for (int i = 0; i < strlen(str.c_str()); i++) {
		char chr = str.at(i);
		if (chr >= '0'&& chr <= '9') {
			hasNum = true;
		}
		else if (chr >= 'a' && chr <= 'z') {
			hasSmallLatter = true;
		}
		else if (chr >= 'A' && chr <= 'Z') {
			hasBigLatter = true;
		}
		else{
			hasOther = true;
		}
	}
	int count = 0;
	if (hasNum) {
		count++;
	}
	if (hasSmallLatter) {
		count++;
	}
	if (hasBigLatter) {
		count++;
	}
	if (hasOther) {
		count++;
	}
	return count >= 3;
}

bool hasMaxSubstrLen(const string& str) {
	for (int i = 0; i<str.size(); i++)
	{
		int LenOfChild = 1;
		for (int j = i + 1; j<str.size(); j++)
		{
			int m = i;
			int n = j;
			while (m<str.size() && n<str.size() && str[m] == str[n])  //连续子串
			{
				m++;
				n++;
				LenOfChild++;
			}
			if (LenOfChild>3)  //条件三
				return false;
			else
				LenOfChild = 1;
		}
	}
	return true;
}

bool ispasswordproper(const string& password) {
	
	return isLetterProper(password)&&
		   strlen(password.c_str())>8&&
		   hasMaxSubstrLen(password);

}

void test_isproperpassword() {
	string str;
	while (cin >> str) {
		bool flag = ispasswordproper(str);
		if (flag) {
			printf("OK\n");
		}
		else {
			printf("NG\n");
		}
	};	
}