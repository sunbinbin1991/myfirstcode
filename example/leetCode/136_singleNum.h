#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int singleNumber(vector<int>& nums)
{
    int single = 0;
    for (int num : nums) {
        single ^= num;
    }
    return single;
}