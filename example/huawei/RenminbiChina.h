#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const string UNIT[7] = { "·Ö","½Ç","Ê°","°Ù","Çª","Íò","ÒÚ" };
const string ChinaNum[10] = { "Áã","Ò¼","·¡","…£","ËÁ","Îé","Â½","Æâ","°Æ","¾Á" };

string num2ChinaYuan(std::vector<int>& num) {
	string res = "";
	bool former_is_zero = false;
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == 0 && !former_is_zero) {
			res += ChinaNum[num[i]];
			former_is_zero = true;
		}
		else {
			if (num[i] == 0) {
				continue;
			}
			else {
				if (i == num.size() - 1) {
					res += ChinaNum[num[i]];
				}
				else {
					res += ChinaNum[num[i]] + UNIT[num.size() - i];
				}
				former_is_zero = false;
			}

		}
	}
	return res;
}

string numEight2ChinaYuan(std::vector<int>& nums) {
	string res = "";
	int len = nums.size();
	int wanNum = len / 4;
	if (wanNum == 2) {
		int pre_wan = len - 4;
		std::vector<int> tempNums(nums.begin(), nums.begin() + pre_wan);
		string part = num2ChinaYuan(tempNums);
		res += part;
		res += UNIT[5];
		std::vector<int> tempNums2(nums.begin() + pre_wan, nums.begin() + pre_wan + 4);
		string part2 = num2ChinaYuan(tempNums2);
		res += part2;
	}
	else if (wanNum == 1) {
		int pre_wan = len - 4;
		std::vector<int> tempNums(nums.begin(), nums.begin() + pre_wan);
		string part = num2ChinaYuan(tempNums);
		res += part;
		if (pre_wan != 0) {
			res += UNIT[5];
		}
		std::vector<int> tempNums2(nums.begin() + pre_wan, nums.end());
		string part2 = num2ChinaYuan(tempNums2);
		res += part2;
	}
	else {
		std::vector<int> tempNums(nums.begin(), nums.end());
		string part = num2ChinaYuan(tempNums);
		res += part;
	}
	return res;
}

int test_printRenminbi() {


	double num;
	while (cin >> num) {
		std::vector<int> nums;
		int tem = int(num);
		while (tem) {
			int rem = tem % 10;
			nums.push_back(rem);
			tem = tem / 10;
		}
		std::vector<int> nums2;
		std::reverse(nums.begin(), nums.end());
		for (size_t i = 0; i < nums.size(); i++)
		{
			printf("%d\n", nums[i]);
		}
		string res = "ÈËÃñ±Ò";
		int yiNum = nums.size() / 9;
		int len = nums.size();
		if (yiNum == 1) {
			int pre_yi = nums.size() - 8;
			std::vector<int> tempNums(nums.begin(), nums.begin() + pre_yi);
			string part = numEight2ChinaYuan(tempNums);
			res += part;
			if (pre_yi != 0) {
				res += UNIT[6];
			}
			std::vector<int> tempNums2(nums.begin()+ pre_yi, nums.end());
			string part2 = numEight2ChinaYuan(tempNums2);
			res += part2;
		}
		else {
			string part2 = numEight2ChinaYuan(nums);
			res += part2;
		}
		res += "Ôª";
		int jiao = ((long long)(num * 10)) % 10;
		int fen = ((long long)((num+0.001) * 100)) % 10;
		if (jiao == 0 && fen == 0) {
			res += "Õû";
		}
		else {
			string 	str = ChinaNum[jiao] + UNIT[1];
			string 	str2 = ChinaNum[fen] + UNIT[0];
			res += str;
			res += str2;
		}
		printf("res = %s", res.c_str());
	}

	return 0;
}