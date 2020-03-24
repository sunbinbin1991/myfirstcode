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

void get_maxIncreaseOrder(const std::vector<int>& nums) {
	std::vector<int> target(nums.size());
	target[0] = 1;
	for (size_t i = 0; i < nums.size(); i++)
	{
		printf("nums = %d\n", nums[i]);
		target[i] = 1;
	}
	int max_num = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		int max_num = 1;
		for (int j = 0; j <= i; j++) {
			if (nums[j] < nums[i]) {
				target[i] = std::max(target[j]+1, target[i]);
			}
			max_num = std::max(max_num, target[i]);
			printf("i= %d, j= %d £¬target = %d£¬num = %d\n",i,j, target[i],max_num);
		}
		//target[i] = max_num;

		//printf("target = %d\n", target[i]);
	}
	for (int i = 1; i < nums.size(); i++)
	{
		printf("target %d = %d\n", i,target[i]);
	}

}

int test_maxContinuousIncreaseOrder() {
	std::vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
	}
	//get_maxContinuousIncreaseOrder(nums);
	get_maxIncreaseOrder(nums);
	return 0;
}