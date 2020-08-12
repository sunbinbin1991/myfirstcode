#pragma once
#include<vector>
#include<iostream>

int maxSubArray(vector<int>& nums)
{
    int len = nums.size();
    vector<int> DP(len+1);
    DP[0] = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        DP[i] = max(nums[i], DP[i - 1] + nums[i]);
    }
    int res = INT_MIN;
    for (size_t i = 0; i < len; i++) {
        res = max(DP[i], res);
        //printf("[%d]\n", DP[i]);
    }
    return res;
}

void test_maxSubArray() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    maxSubArray(nums);
}