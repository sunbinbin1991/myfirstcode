#pragma once
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int target, bool lower) {
    int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target || (lower && nums[mid] >= target)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange2(vector<int>& nums, int target)
{

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
    int target = 8;
    auto res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        printf("searchRange %d \n", res[i]);
    }

    res = searchRange2(nums, target);
    for (int i = 0; i < res.size(); i++) {
        printf("searchRange2 %d \n", res[i]);
    }
}