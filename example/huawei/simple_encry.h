#pragma once
#include <iostream>
#include <string>
using namespace std;

void decry(const string& input,string& out) {
	out = "";
	strlen(input.c_str());
	for (int i = 0; i < input.size(); i++)
	{
		char ch = input.at(i);
		char outchar;
		if (ch == 'Z') {
			outchar = 'a';
		}
		if (ch >= '0'&&ch<='9') {
			outchar = ch;
		}
		if (ch >= 'A'&&ch < 'Z') {
			outchar = ch + 33;
		}
		if (ch >= 'a'&&ch <= 'r') {
			int num = ch - 'a';
			outchar = num / 3 +2 +'0';
		}
		if (ch == 's') {
			outchar = '7';
		}
		if (ch > 's'&&ch <= 'v') {
			outchar = '8';
		}
		if (ch > 'w'&&ch <= 'z') {
			outchar = '9';
		}
		out += outchar;
	}
	printf("out = %s\n", out.c_str());
}

int lowtonum(char s)
{
	int nu[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	return (nu[s - 'a']);
}
void better() {
	string s;
	while (cin >> s)
	{
		string re;
		int n = s.size();
		for (int i = 0; i<n; ++i)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				int t = s[i] - 'A' + 1;
				re += 'a' + (t % 26);
			}
			else if (s[i] >= 'a'&&s[i] <= 'z')
			{
				int t = lowtonum(s[i]);
				re += t + '0';
			}
			else if (isdigit(s[i]))
			{
				re += s[i];
			}
		}
		cout << re << endl;
	}
}


void test_decry() {
	string input = "YUANzhiv1987";
	string out;
	//cin >> input;
	decry(input, out);
}