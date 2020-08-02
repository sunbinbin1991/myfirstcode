#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    set<int> resSet;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                resSet.emplace(nums1[i]);
            }
        }
    }

    for (auto itr : resSet) {
        res.push_back(itr);
    }
    return res;
}

void test_intersection() {
    vector<int> nums1 = { 1,2,3,4,3,9 };
    vector<int> nums2 = { 1,2,9,12 };
    vector<int> res = intersection(nums1, nums2);
    for (size_t i = 0; i < res.size(); i++) {
        printf("%d\n", res[i]);
    }
}