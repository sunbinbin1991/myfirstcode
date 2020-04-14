#pragma once
# include <string.h>
#include<iostream>
using namespace std;
bool isNum(char letter) {
	return letter <= '9'&& letter >= '0';
}
void test_maxContinueNumStr() {
	string input;
	while (cin>> input)
	{
		if (input.empty()) {
			printf("\n");
			continue;
		}
		input = "8749r6k4nugdm04p5b1yhegi8hiq3937";
		int len = input.size();
		bool is_continue_num = false;
		string maxlen_str = "";
		string temp_str = "";
		int maxlen = 0;
		int count = 0;
		std::vector<string> total;
		for (int i = 0; i < len; i++)
		{
			bool isNowNum = isNum(input[i]);
			if (isNowNum) {
				count++;
				temp_str += input[i];
			}else {
				count =  0;
				temp_str = "";
				is_continue_num = false;
			}
			if (is_continue_num&&isNowNum) {
				maxlen = std::max(maxlen, count);
				if (maxlen >= count) {
					total.push_back(temp_str);
				}
			}
			if (isNowNum) {
				is_continue_num = true;
			}
		}
		len = total.size();
		for (int i = 0; i < len; i++)
		{
			if (maxlen == total[i].size()) {
				maxlen_str += total[i];
			}
		}

		printf("%s,%d", maxlen_str.c_str(), maxlen);
	}
}