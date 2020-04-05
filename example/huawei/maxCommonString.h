#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
void get_maxCommonString(string & str1,string & str2) {
	if (str1.empty() || str2.empty()) return;
	int len1 = strlen(str1.c_str());
	int len2 = strlen(str2.c_str());
	if (len1 > len2) {
		std::swap(str1, str2);
		std::swap(len1, len2);
	}
	int max_len = -1;
	string res;

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			char temp1 = str1.at(i);
			char temp2 = str2.at(j);
			int count = 1;
			printf("%c %c \n", temp1, temp2);
			if (temp1 == temp2) {
				for (int m = i+1; m < len1; m++)
				{
					printf("\t\t%c %c \n", *(str1.data() + m), *(str2.data() + j + m));
					if (*(str1.data() + m) == *(str2.data() + j + m-i)) {
						count++;
					}
					else {
						break;
					}
				}
			}
			if (count > max_len) {
				max_len = count;
				res = string(str1.begin() + i, str1.begin() + i + count);
			}
		}
	}
	cout << res << endl;

}
int test_maxCommonString() {
	string str1, str2;
	while (cin>>str1>>str2) {
		get_maxCommonString(str1, str2);
	}
	return 0;
}