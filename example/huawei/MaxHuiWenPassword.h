#pragma once
#include<iostream>
#include<string>
using namespace std;
bool judgehuiwen(const string& input){
	int str_len = strlen(input.c_str());
	if (input.empty()) return false;
	for (int i = 0; i <= str_len/2; i++)
	{
		if (input[i] != input[str_len -1- i]) {
			return false;
		}
	}
	return true;
}

int MatchingTarget(const string& input) {
	bool flag = false;
	int num = 0;
	if (input.empty()) {
		return 0;
	}
	int str_len = strlen(input.c_str());
	for (int i = 0; i < str_len; i++)
	{
		for (int j = i; j < str_len; j++)
		{
			if (input[j] == input[i]) {
				string tmp(input.begin()+i, input.begin() + j+1);
				//printf("tmp@@@%s\n", tmp.c_str());
				if (judgehuiwen(tmp)) {
					//printf("@@@%s\n", tmp.c_str());
					int tmpstr_len = strlen(tmp.c_str());
					num = std::max(num, tmpstr_len);
				}
			}
		}
	}
	return num;
}
//qhbrivaighqmgafhthxicdiixpefhwwefdebwczswqqdjxulhuhceqrxechddtlbbltddhcexrqechuhluxjdqqwszcwenakceymkxfqpqxctbsousrwwhooxjtcqnvb
int test_maxValidPassword() {
	string input;
	while (cin >> input)
	{
		int num;
		num = MatchingTarget(input);
		printf("%d\n", num);
	}
	return 0;
}