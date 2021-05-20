#pragma once
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<iostream>
using namespace std;
int search2(vector<int>& nums, int target)
{
    if (nums.empty()) return -1;
    for (int i = 0; i< nums.size(); i++) {
        if (nums[i] == target) return i;
    }
    return -1;
}

int search(vector<int>& nums, int target)
{
    if (nums.empty()) return -1;
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        int mid = (left + right) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target && nums[left] < target ) {
            left = mid + 1;
            right = right - 1;
        } else if (nums[mid] < target && nums[right] > target ){
            left += 1;
            right = mid - 1;
        }
    }
    return -1;
}

void test_search() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    int res = search(nums, 0);
    std::cout << "res " << res << endl;
}