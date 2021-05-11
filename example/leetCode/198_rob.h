#pragma once
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0],nums[1]);
    int len = nums.size();
    vector<int> DP(len + 1);
    DP[0] = nums[0];
    DP[1] = max(DP[0], nums[1]);

    for (int i = 2; i < len; i++) {
        DP[i] = max(DP[i - 2] + nums[i], DP[i-1]);
    }
    for (int i = 0; i < len; i++) {
        printf("DP = %d\n", DP[i]);
    }
    return DP[len - 1];
}

void test_rob() {
    vector<int> nums = { 2,7,9,3,1 };
    int res = rob(nums);
    cout << "res = " << res;
}