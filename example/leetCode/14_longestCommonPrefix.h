#pragma once
#include <iostream>
#include <vector>
string longestCommonPrefix(vector<string>& strs)
{
	int minStringLen = INT_MAX;
	string res = "";
	for (int i = 0; i < strs.size(); i++) {
		if (strs[i].empty()) return res;
		if (strs[i].length() < minStringLen) {
			minStringLen = strs[i].length();
		}
	}
	cout << minStringLen << endl;
	for (int i = 1; i <= minStringLen; i++) {
		bool has_prefix = true;
		string common_str = strs[0].substr(0, i);
		cout << common_str << endl;
		for (size_t j = 0; j < strs.size(); j++) {
			bool flag = strs[j].find_first_of(common_str,0) != string::npos;
			cout<< strs[j] << " = " << flag << endl;
			has_prefix = has_prefix && flag;
			if (!has_prefix) {
				break;
			}
		}
		if (!has_prefix) {
			return res;
			break;
		}
		cout<<" common_str " << common_str << endl;
		res = common_str;
	}
	return res;
}

void tet_longestCommonPrefix() {
	vector<string> strs = { "c","acc","ccc" };
	string str = longestCommonPrefix(strs);
	cout << str << endl;
}