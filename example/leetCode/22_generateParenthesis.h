#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

bool isValid(string s)
{
	if (s.empty()) return true;
	int len = s.size();
	stack<char> ch_small;
	for (int i = 0; i < len; i++) {
		char tmp = s[i];
		if ((tmp == ')') && ch_small.empty()) {
			return false;
		}
		if (tmp == ')'&&ch_small.top() == '(' ){
			ch_small.pop();
		} else {
			ch_small.push(tmp);
		}
	}
	return ch_small.empty();
}
//括号生成的步骤
void generaterkuohao(int depth, int len, string path, vector<string> res ) {
	if (path.size() == len) {
		res.push_back(path);
		return;
	}
	path += "(";
	path += ")";

	


}

void test_generateParenthesis() {
	int n = 3;

}