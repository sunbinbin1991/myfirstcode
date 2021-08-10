#pragma once
#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
int numberOfArithmeticSlices(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 3) return 0;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < len - 2; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            for (int k = i + 2; k < len; k++) {
                if (2 * nums[j] == nums[i] + nums[k]) {
                    ans ++;
                    continue;
                }
            }
        }
    }
    return ans;
}

void test_numberOfArithmeticSlices() {
    vector<int> nums = { 1,2,3,4 };
    auto res = numberOfArithmeticSlices(nums);
    cout << res << endl;
}