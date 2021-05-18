#pragma once
bool canJump(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int len = nums.size();
    if (len == 1) return nums[0] >= 0;
    vector<int> DP(len);
    DP[0] = nums[0];
    bool canJump = DP[0] > 0;
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j <= i; ++j) {
            DP[i] = max(DP[j - 1] - 1, nums[j]);
        }
        canJump = canJump && DP[i] > 0;
    }
    return canJump;
}

void test_canJump()
{
    vector<int> res = {2,3,1,1,4 };


}