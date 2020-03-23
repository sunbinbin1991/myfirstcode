#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
void get_maxContinuousIncreaseOrder(const std::vector<int>& nums) {
	int count = 1;
	std::vector<int> target(nums.size());
	target[0] = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		printf("nums = %d\n", nums[i]);
	}
	int max = -1;
	for (size_t i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] < nums[i + 1]) {
			count++;
		}
		else {
			max = std::max(count, max);
			count = 1;
		}
		target[i] = std::max(count, max);;
	}
	max = std::max(count, max);
	printf("max = %d\n", max);

}

int test_maxContinuousIncreaseOrder() {
	std::vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
	}
	get_maxContinuousIncreaseOrder(nums);
	return 0;
}