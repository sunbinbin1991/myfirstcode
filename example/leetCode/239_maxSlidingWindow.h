#pragma once
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int maxTrainNum(vector<int> dequeTrain, int start, int k,int & index)
{
    int maxNum = INT_MIN;
    for (size_t i = 0; i < k; i++) {
        maxNum = max(maxNum, dequeTrain[start - i]);
        index = start - i;
    }
    return maxNum;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> res;
    if (nums.empty()) return res;
    if (nums.size() <= k) {
        int maxTrain = INT_MIN;
        for (size_t i = 0; i < nums.size(); i++) {
            maxTrain = max(maxTrain, nums[i]);
        }
        res.push_back(maxTrain);
        return res;
    }
    int maxLastTrain = INT_MIN;
    int maxIndex = -1;
    for (size_t i = k - 1; i < nums.size(); i++) {
        if (i >= k && maxIndex != i - k) {
            if (nums[i] > maxLastTrain) {
                maxLastTrain = nums[i];
                res.push_back(maxLastTrain);
                continue;
            } else {
                res.push_back(maxLastTrain);
                continue;
            }
        }
        maxLastTrain = maxTrainNum(nums, i, k, maxIndex);
        res.push_back(maxLastTrain);
    }
    return res;
}

void test_maxSlidingWindow()
{
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (size_t i = 0; i < res.size(); i++) {
        printf("%d\n", res[i]);
    }
}