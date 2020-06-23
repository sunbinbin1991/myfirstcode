#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

bool isKuohaoValid(string s)
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


//括号生成的步骤,dfs 顺序
void generate_all(string& current, int n, vector<string>& result)
{
	if (n == current.size()) {
		if (isValid(current))
			result.push_back(current);
		return;
	}
	current += '(';
	generate_all(current, n, result);
	current.pop_back();
	current += ')';
	generate_all(current, n, result);
	current.pop_back();
}

void test_generateParenthesis() {
	int n = 3;

}