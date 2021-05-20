#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;
int singleNumber(vector<int>& nums)
{
    int single = 0;
    for (int num : nums) {
        single ^= num;
    }
    return single;
}

int singleNumber2(vector<int>& nums)
{
    unordered_map<int, int> freq;
    for (int num : nums) {
        ++freq[num];
    }
    int ans = 0;
    for (auto num: freq) {
        if (num.second == 1) {
            ans = num.first;
            break;
        }
    }
    cout << ans;
    return ans;
}

int test_singleNumber2()
{
    vector<int> nums = { 3,1,2,4,1,2,3 };
    int s = singleNumber2(nums);
    return s;
}