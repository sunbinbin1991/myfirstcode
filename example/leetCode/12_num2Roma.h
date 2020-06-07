#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Solution_num2roman
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
void test_num2roman() {


}