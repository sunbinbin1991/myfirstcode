#pragma once
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int sumOddLengthSubarrays(vector<int>& arr)
{
    if (arr.empty()) return 0;
    int ans = 0;
    for (int j = 1; j <= arr.size(); j++) {
        if (j % 2 == 0) {
        } else {
            for (int i = 0; i <= arr.size() - j; i++) {
                for (int k = 0; k < j && (k + i <= arr.size() - 1); k++) {
                    ans += arr[k + i];
                    // cout << arr[k + i] << endl;
                }

            }

        }
    }
    return ans;
}