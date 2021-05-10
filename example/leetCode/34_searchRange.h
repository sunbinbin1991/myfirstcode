#pragma once
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

void binarySearch() {

}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res{-1,-1};
    if (nums.empty() || nums.front() > target || nums.back() < target) return res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target && res[0] != -1) {
            res[0] = i;
        }
        if (nums[i] == target && res[0] != -1) {
            res[1] = i;
        }
    }
    return res;
}

void test_searchRange() {
    vector<int> nums = { 5,7,7,8,8,10 };
    int target = 10;
    auto res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        printf("%d \n", res[i]);
    }
}