#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    set<int> resSet;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    auto start1 = nums1.begin();
    auto start2 = nums2.begin();

    while (start1 != nums1.end() && start2 != nums2.end()) {
        printf("%d %d \n", *start1, *start2);
        if (*start1 > *start2) {
            start2++;
        } else if (*start1 < *start2) {
            start1++;
        } else {
            res.push_back(*start1);
            start2++;
            start1++;
        }
    }

    for (auto itr : resSet) {
       // res.push_back(itr);
    }
    return res;
}

void test_intersection2()
{
    vector<int> nums1 = { 15, 2, 3, 4, 3, 9};
    vector<int> nums2 = { 1, 2, 9,12 };
    vector<int> res = intersection2(nums1, nums2);
    for (size_t i = 0; i < res.size(); i++) {
        printf("%d\n", res[i]);
    }
}