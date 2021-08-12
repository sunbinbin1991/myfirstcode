#pragma once
#include<string>
#include<vector>
#include<algorithm> 
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int n = temperatures.size();
    vector<int> ans;
    int len = temperatures.size();
    for (int i = 0; i < len; ++i) {
        int count = 0;
        for (int j = i; j < len; j++) {
            if (temperatures[j] > temperatures[i]) {
                count++;
                ans.push_back(count);
                break;
            }
            if (j = len - 1) {
                ans.push_back(0);
            }
        }
    }
    return ans;
}