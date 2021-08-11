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
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.empty() || nums.size() < 3) return 0;
        vector<int> dp(nums.size());
        int ans = 0;
        int d = nums[1] - nums[0];
        int t = 0;
        for (int i = 2; i < nums.size(); ++i) {
            if(nums[i] - nums[i-1] == d){
                t++;   
            } else {
                d = nums[i] - nums[i-1];
                t = 0;
            }
            ans += t;
        }
        return ans;
    }

void test_numberOfArithmeticSlices() {
    vector<int> nums = { 1,2,3,4 };
    auto res = numberOfArithmeticSlices(nums);
    cout << res << endl;
}
