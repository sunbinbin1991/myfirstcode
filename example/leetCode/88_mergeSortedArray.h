#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void mergeSortedArray(vector<int>& nums1, int m,
    vector<int>& nums2, int n)
{
    if (nums2.empty()) return;
    memcpy(nums1.data() + m, nums2.data(), sizeof(int) * n);

    sort(nums1.begin(), nums1.end());
    for (size_t i = 0; i < nums1.size(); i++) {
        printf("%d ", nums1[i]);
    }
}
void test_merge_array() 
{
    vector<int> nums1 = { 1,2,3,0,0, 0 };
    vector<int> nums2 = { 2,5,6};
    mergeSortedArray(nums1, 3, nums2, 3);
}