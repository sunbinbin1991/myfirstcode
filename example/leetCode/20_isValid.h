#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
bool isValid(string s)
{
	if (s.empty()) return true;
	int len = s.size();
	stack<char> ch_small;
	for (int i = 0; i < len; i++) {
		char tmp = s[i];
		if ((tmp == ')' || tmp == ']' || tmp == '}' )&& ch_small.empty()) {
			printf(" ch_small.empty()1 = %d\n", ch_small.empty());
			return false;
		}

		if (tmp == ')') {
			if (ch_small.top() == '(') {
				ch_small.pop();
			} else {
				return false;
			}
		} else if (tmp == ']') {
			if (ch_small.top() == '[') {
				ch_small.pop();
			} else {
				return false;
			}
		} else if (tmp == '}') {
			if (ch_small.top() == '{') {
				ch_small.pop();
			}else{
				return false;
			}
		} else {
			printf(" ch_small.empty()2 = %d\n", ch_small.empty());
			ch_small.push(tmp);
		}
	}
	printf("size = %d\n", ch_small.size());
	return ch_small.empty();
}
void test_valid() {
	string input = "[)]";
	printf("isvalid = %d\n", isValid(input));
}