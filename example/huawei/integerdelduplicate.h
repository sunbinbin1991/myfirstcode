#pragma once
#include "iostream"
#include <string>
#include "string.h"

using namespace std;

//url:https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

void integerdelduplicate() {

}

void test_integerdelduplicate() {
	string numstr;
	cin >> numstr;
	int array[10] = { 0 };
	int len = strlen(numstr.c_str());
	for (int i = len-1; i >=0 ; i--)
	{
		if (array[numstr.at(i) - '0'] <= 0) {
			array[numstr.at(i) - '0'] += 1;
			cout << numstr.at(i);
		}
	}
}

void test_getallacellnums() {
	string str;
	cin >> str;
	int len = strlen(str.c_str());
	int num = 0;
	for (int i = 0; i<len; i++) {
		if ((str.at(i) >= 0) && (str.at(i)<128)) {
			num += 1;
		}
	}
	cout << num << endl;
}

void inversestr(const string& src, string& dst) {
	dst = "";
	int len = strlen(src.c_str());
	for (int i = len - 1; i >= 0; i--)
	{
		dst += src.at(i);
	}
}

void test_getInversesentence() {
	std::vector<string> strings;
	string numstr;
	while (cin >> numstr) {
		strings.push_back(numstr);
	}
	int string_nums = strings.size();
	printf("string_nums = %d\n", string_nums);
	for (int i = string_nums - 1; i >= 0; i--)
	{
		cout << strings[i] << " ";
	}
}


void test_string_compare() {
	
	std::string str1 = "abc";
	std::string str2 = "aba";
	std::string str3 = "abd";

	printf("str1 str2 %d\n", str1.compare(str2));
	printf("str1 str2 %d\n", str1.compare(str1));
	printf("str3 str1 %d\n", str1.compare(str3));
}