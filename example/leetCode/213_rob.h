#pragma once
#include<vector>
#include<deque>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
//int robRange(vector<int>& nums, int start, int maxNum)
//{
//    int len = nums.size();
//    int ans = 0;
//    vector<int> dp(len + 1);
//    int startCircle = (start + len) % len;
//    //int startCircle = (end + len) % len;
//    dp[0] = 0;
//    dp[1] = nums[startCircle];
//    for (size_t i = 2; i < len; i++) {
//        int x2 = (startCircle + i - 2) % len;
//        int x1 = (startCircle + i - 1) % len;
//        int x0 = (startCircle + i) % len;
//        cout << "x2 :" << x2 << ",x1:" << x1 << endl;
//        cout << "dp[x1] :" << dp[x1] + nums[i] << ",dp[x2]:" << dp[x2] << endl;
//        if (dp[x1] + nums[x1] > dp[x2]) {
//            dp[i] = dp[x1] + nums[x1];
//        } else {
//            dp[i] = dp[x2];
//        }
//        cout << "dp[i-1] :" << dp[i] << endl;
//    }
//    ans = dp[len - 1];
//    cout << "ans : " << ans << endl;
//    return ans;
//}
//
//int rob2(vector<int>& nums)
//{
//    if (nums.empty()) return 0;
//    if (nums.size() == 1) return nums[0];
//
//    int len = nums.size();
//    int ans = INT_MIN;
//    for (size_t i = 0; i < len; i++) {
//        ans = max(ans, robRange(nums, i, len));
//    }
//    return ans;
//}


int robRange(vector<int>& nums, int start, int end)
{
    int first = nums[start], second = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}

int rob2(vector<int>& nums)
{
    int length = nums.size();
    if (length == 1) {
        return nums[0];
    } else if (length == 2) {
        return max(nums[0], nums[1]);
    }
    return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
}

void test_rob2()
{
    vector<int> nums = { 1,2,3,1 };
    int res = rob2(nums);
    cout << res << endl;
}