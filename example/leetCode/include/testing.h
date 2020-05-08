#pragma once
#include<../1_twoSum.h>

void test_two_sum() {
	std::vector<int> input = { 1,2,3,4,5 };
	std::vector<int> out = twoSum(input, 9);
	for (size_t i = 0; i < out.size(); i++)
	{
		cout << out[i] << endl;
	}
}
