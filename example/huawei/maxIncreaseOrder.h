#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
void get_maxIncreaseOrder(const std::vector<int>& nums) {
	int max_num = 1;
	std::vector<int> target(nums.size());
	target[0] = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		printf("nums = %d\n", nums[i]);
	}
	for (size_t i = 1; i < nums.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			target[i] = std::max(max_num, target[j]);
			/*if (nums[i] > nums[j-1]) {
				target[i] = std::max(max_num, target[j]);
			}
			else {
				target[i] = target[i - 1];
			}*/
		}
		max_num = target[i];
		//target[i] = std::max(max_num,target[i-1]);
	}

	for (size_t i = 0; i < target.size(); i++)
	{
		printf("tt = %d\n", target[i]);
	}

}

int test_maxIncreaseOrder() {
	std::vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
	}
	get_maxIncreaseOrder(nums);
	return 0;
}