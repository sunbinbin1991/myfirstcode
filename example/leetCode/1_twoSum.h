#pragma once
//https://leetcode-cn.com/problems/two-sum/
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	for (int i = 0; i< nums.size() - 1; i++) {
		for (int j = i + 1; j< nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				res.push_back(i);
				res.push_back(j);
			}
		}
	}
	return res;
}