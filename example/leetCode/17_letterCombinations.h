#pragma once
#include<vector>
#include<iostream>
#include<set>
using namespace std;
static std::map<int, string> letmapper = { {2,"abc"},{3,"def"},{ 4,"ghi" },
										   { 5,"jkl" },{ 6,"mno" }, { 7,"pqrs" },
										   {8,"tuv"},{9,"wxyz"}};

void dfsletter(int depth, string digits, vector<string> &parts, set<string> &results) {
	int len = digits.size();
	if (!parts.empty()) {
		bool isSatified = false;
		if (parts[0].size() == len) {
			results.insert(parts[0]);
			isSatified = true;
		}
		if (isSatified) {
			return;
		}
	}

	int num = digits[depth]-'0';
	string letters = letmapper[num];
	for (int i = 0; i < letters.size(); i++) {
		for (int j = 0; j < parts.size(); j++) {
			parts[j][0] += letters[i];
		}
	}
	dfsletter(depth + 1, digits, parts, results);
}

vector<string> letterCombinations(string digits) {
	vector<string> nums = { "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> result;
	if (digits.empty()) {
		return result;
	}
	result.push_back("");
	for (int i = 0; i<digits.size(); i++) {
		vector<string> tempresult;//用来存放新的字母组合。
		int num = digits[i] - '0' - 1; //数字对应表中的字母索引。
		for (int j = 0; j<nums[num].size(); j++) {//循环数字对应的各个字母。
			vector<string> temp(result);//获得之前得到的字母组合  可为空。
			for (int k = 0; k<temp.size(); k++) {
				temp[k] += nums[num][j];//每个之前的字母组合后面都加上当前循环得到的字母。
				tempresult.push_back(temp[k]);//保存新的字母组合。
			}
		}
		result = tempresult;//将新的字母组，达到结束时输出或者参与下一轮组合。
	}
	return result;
}

void test_letterCombinations()
{
	string digits = "23";
	letterCombinations(digits);
}