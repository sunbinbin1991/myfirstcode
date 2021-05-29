#pragma once
#include<vector>
#include<iostream>
using namespace std;
void dfs(vector<vector<int>> &ans, vector<int> &tmp, vector<int>& nums, int cur, int n)
{
    if (cur == n) {
        ans.push_back(tmp);
        return;
    }
    tmp.push_back(nums[cur]);
    dfs(ans, tmp, nums, cur + 1, n);
    tmp.pop_back();
    dfs(ans, tmp, nums, cur + 1, n);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    if (nums.empty()) return{};
    vector<vector<int>> ans;
    // ans.push_back({});

    // for (int i = 0; i <= nums.size(); ++i) {
    vector<int> tmp;
    dfs(ans, tmp, nums, 0, nums.size());
    // }
    return ans;
}