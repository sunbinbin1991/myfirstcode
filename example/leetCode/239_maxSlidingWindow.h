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

void clearPriorityQue(priority_queue<pair<int, int>> &q,int index) {
    int len = q.size();
    priority_queue<pair<int, int>> qOut;
    for (size_t i = 0; i < len; i++) {
        if (q.top().second != index) {
            qOut.emplace(q.top());
        }
        q.pop();
    }
    q = qOut;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> res;
    if (nums.empty()) return res;
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k && i < nums.size(); i++) {
        pair<int, int> temp(nums[i],i);
        q.push(temp);
    }
    vector<int> ans = { q.top().first };
    for (int i = k; i < nums.size(); i++) {
        q.emplace(nums[i], i);
        while (q.top().second <= i - k) {
            q.pop();
        }
        ans.push_back(q.top().first);
    }
    return ans;
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