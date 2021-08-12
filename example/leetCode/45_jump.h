#pragma once
#include<vector>
#include<algorithm>
using namespace std;
int jump_better(vector<int>& nums)
{
    int max_far = 0;// 目前能跳到的最远位置
    int step = 0;   // 跳跃次数
    int end = 0;    // 上次跳跃可达范围右边界（下次的最右起跳点）
    for (int i = 0; i < nums.size() - 1; i++) {
        max_far = std::max(max_far, i + nums[i]);
        // 到达上次跳跃能到达的右边界了
        if (i == end) {
            end = max_far;  // 目前能跳到的最远位置变成了下次起跳位置的有边界
            step++;         // 进入下一次跳跃
        }
    }
    return step;
}

int jump2(vector<int>& nums)
{
    if (nums.empty() || nums.size() == 1) return 0;
    int len = nums.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    for (int i = 1; i <= len; ++i) {
        int minJump = INT_MAX - 1;
        for (int j = 0; j < i; ++j) {
            if (dp[j] > minJump) {
                continue;
            }
            if (nums[j] + j >= i) {
                minJump = min(dp[j], minJump);
            }
        }
        dp[i] = minJump + 1;
    }
    return dp[len - 1];
}
