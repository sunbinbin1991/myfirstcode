#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void sort_string(const string &str) {
	string res;

}

unsigned char char2hex(unsigned char ch) {
	unsigned char uch;
	if (ch >= 'A'&&ch <= 'F') {
		uch = ch - 'A' + 0x0A;
	}
	else if (ch >= 'a'&&ch <= 'f') {
		uch = ch - 'a' + 0x0A;
	}
	else {
		uch = ch - '0';
	}
	return uch;
}

unsigned char hex2char(unsigned char ch) {
	unsigned char uch;
	if (ch >= 0x0A&& ch<=0x0F) {
		uch = ch - 0x0A + 'A';
	}
	else if (ch >=0x0&&ch <= 0x9) {
		uch = ch +'0';
	}
	else {
		return 0;
	}
}

void convert_str(const string &str1, const string &str2) {
	string conv_str = str1 + str2;
	string odd_str;
	string even_str;
	for (int i = 0; i < conv_str.size(); i++)
	{
		if (i & 1) {//odd ÆæÊý
			odd_str += conv_str.at(i);
		}
		else {
			even_str += conv_str.at(i);
		}
	}
	sort(odd_str.begin(), odd_str.end());
	sort(even_str.begin(), even_str.end());
	string sort_str;
	for (int i = 0; i < conv_str.size()/2; i++)
	{
		sort_str += even_str.at(i);
		sort_str += odd_str.at(i);
	}
	string res;
	for (int i = 0; i < sort_str.size(); i++)
	{
		char ch = sort_str.at(i);
		if (ch>'F'&&ch <= 'Z') {
			res += ch;
			continue;
		}
		if (ch>'f'&&ch <= 'z') {
			res += ch;
			continue;
		}
		unsigned char uch = char2hex(ch);
		unsigned char inverse_char1, inverse_char2;
		inverse_char1 = (uch & 0x04) >> 1 | (uch & 0x02) << 1;
		inverse_char2 = (uch & 0x08) >> 3 | (uch & 0x01) << 3;
		unsigned char conver_char = hex2char(inverse_char1| inverse_char2);
		res += conver_char;
	}

	//printf("convt = %s", sort_str.c_str());
	printf("res = %s", res.c_str());
}

int test_combineTwoStringByRule() {
	string str1, str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		str1 = "DKSq8qykpgKIZxiRKmQ9QkZt909PffE6Gyfc57dBx7p20D42bWJRzKqGGCzzQ4p7Z32Dsx2Cf8G2841lPuAZNb";
		str2 = "K0fHodOVFlbl220ov260TPOrmZ328d1E89OatcL88EXr622RdklXtXazO7wMoc6DEKU45eQ5VBUy2YFjgJX";
		convert_str(str1, str2);
	}
	return 0;
}