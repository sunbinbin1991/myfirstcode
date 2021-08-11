#pragma once
#include<vector>
#include<algorithm>
using namespace std;
int jump2(vector<int>& nums)
{
    if (nums.empty() || nums.size() == 1) return 0;
    int len = nums.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    for (int i = 1; i <= len; ++i) {
        int minJump = INT_MAX - 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] + j >= i) {
                minJump = min(dp[j], minJump);
            }
        }
        dp[i] = minJump + 1;
    }
    return dp[len - 1];
}
