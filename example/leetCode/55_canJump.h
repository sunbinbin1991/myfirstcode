#pragma once
bool canJump(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int len = nums.size();
    if (len == 1) return nums[0] >= 0;
    vector<int> DP(len);
    DP[0] = nums[0];
    bool canJump = DP[0] > 0;
    for (int i = 1; i < len - 1; ++i) {
        DP[i] = max(DP[i - 1] - 1, nums[i]);
        canJump = canJump && DP[i] > 0;
    }
    return canJump;
}

void test_canJump()
{
    vector<int> res = {2,3,1,1,4 };


}