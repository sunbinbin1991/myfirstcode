#pragma once
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
class Solution_roman2num
{
public:
	string intToRoman(int num)
	{
		string result;
		vector<int> store = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> strs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int storeSize = int(store.size());
		//Ì°ÐÄ·¨
		for (int i = 0; i < storeSize; i++) {
			while (num >= store[i]) {
				result.append(strs[i]);
				num -= store[i];
			}
		}
		return result;
	}
};

int romanToInt(string s)
{
	std::map<char, int> single_str = { {'M',1000 }, {'D',500} ,{'C',100}, {'L',50}, {'X',10},{'V',5} ,{'I',1 } };
	std::map<string,int> double_str = { { "CM",900 },{ "CD",400 },{ "XC",90 },{ "XL",40 },{ "IX" ,9 },{ "IV",4 } };
	int res = 0;
	while (!s.empty()) {
		if(s.size() >= 2) {
			string sub(s.begin(), s.begin() + 2);
			if (double_str.find(sub) != double_str.end()) {
				res += double_str[sub];
				s = s.substr(2, s.size() - 2);
				continue;
			}
		}
		char sub = s[0];
		if (single_str.find(sub) != single_str.end()) {
			res += single_str[sub];
		}
		s = s.substr(1, s.size() -1);
	}
	cout << " res " << res << endl;
	return res;
}
void test_roman2num() {
	string input = "MCMXCIV";
	int res = romanToInt(input);
}