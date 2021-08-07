#pragma once
#include<vector>
int findMin(vector<int>& nums)
{
    if (nums.empty()) return 0;
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    int mid = (left + right) / 2;
    while (left < right) {
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if(nums[mid] < nums[right]){
            right = mid;
        } else if (nums[mid] == nums[right]) {
            right--;
        }
        mid = (left + right) / 2;
    }
    return nums[left];
}

void test_findMin() {
    vector<int> nums1{ 1, 3, 4, 7, 8};
    vector<int> nums2{ 3, 3, 3, 3, 3};
    vector<int> nums3{ 4, 5, 6, -1, 2, 3 };
    auto num = findMin(nums3);
    cout << num << endl;
}