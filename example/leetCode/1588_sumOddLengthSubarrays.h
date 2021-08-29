#pragma once
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int sumOddLengthSubarrays2(vector<int>& arr)
{

    vector<int> presum = { 0 };
    for (int e : arr) presum.push_back(presum.back() + e);

    int res = 0;
    for (int i = 0; i < arr.size(); i++)
        for (int sz = 1; i + sz - 1 < arr.size(); sz += 2)
            res += presum[i + sz] - presum[i];

    return res;
}

int sumOddLengthSubarrays(vector<int>& arr)
{
    if (arr.empty()) return 0;
    int ans = 0;
    for (int j = 1; j <= arr.size(); j++) {
        if (j % 2 == 0) {
        } else {
            for (int i = 0; i <= arr.size() - j; i++) {
                for (int k = 0; k < j; k++) {
                    ans += arr[k + i];
                }

            }

        }
    }
    return ans;
}