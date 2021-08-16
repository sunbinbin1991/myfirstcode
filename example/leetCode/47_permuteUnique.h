#pragma once
#include<vector>
#include<algorithm>
using namespace std;

void dfs_permuteUnique(vector<vector<int>> &res, vector<int>& nums,
    vector<int>& vis, int level,vector<int> & perm) {
    if (level == nums.size()) {
        res.emplace_back(perm);
        return;
    }

    for (size_t i = 0; i < nums.size(); i++) {
        if (vis[i] || (i > 0 && nums[i - 1] == nums[i] && !vis[i - 1])) {
            continue;
        }
        vis[i] = 1;
        perm.push_back(nums[i]);
        dfs_permuteUnique(res, nums, vis, level + 1, perm);
        perm.pop_back();
        vis[i] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    //vector<int> nums = {1,1,2,4};
    vector<int> vis;
    sort(nums.begin(), nums.end());
    vis.resize(nums.size());
    vector<vector<int>> res;
    vector<int> per;
    dfs_permuteUnique(res, nums, vis, 0, per);
    return res;
} 

void test_permuteUnique() {
    vector<int> nums = {1,1,2,4};
    permuteUnique(nums);
}