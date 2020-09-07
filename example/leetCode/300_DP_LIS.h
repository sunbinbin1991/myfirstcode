#pragma once
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
    int len = nums.size();
    vector<int> DP(len + 1);
    DP[0] = 1;
    int res = INT_MIN;
    for (size_t i = 1; i < len; i++) {
        //DP[i] = 1;
        for (size_t j = 0; j <= i; j++) {
            if (nums[i] > nums[j]) {
                DP[i] = max(DP[j] + 1, DP[i]);
            }
            //printf("%d = %d\n", i, DP[i]);
        }
        res = max(DP[i], res);
    }
    
    return res;
}

int lengthOfLIS2(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int len = nums.size();
    vector<int> DP(len + 1);
    DP[0] = 1;
    int res = 1;
    for (size_t i = 1; i < len; i++) {
        DP[i] = 1;
        for (size_t j = 0; j <= i; j++) {
            if (nums[i] > nums[j]) {
                DP[i] = max(DP[j] + 1, DP[i]);
            }
        }
        res = max(DP[i], res);
    }

    return res;
}

void test_lengthOfLIS() {
    vector<int> nums = { 1,3,4,5,2,3,5,7,9,2 };
    lengthOfLIS(nums);
}