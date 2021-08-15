#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct numFrq
{
    int num;
    int frq;
    bool operator<(const numFrq& a) const
    {
         return frq > a.frq; //Ð¡¶¥¶Ñ
    }
};

bool compFrq(numFrq n1, numFrq n2) {
    return n1.frq > n2.frq;
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    if (nums.empty()) return{};

    vector<numFrq> numsFrq;
    priority_queue<numFrq> numFrqQue;
    map<int, int> numsFrqMap;
    for (size_t i = 0; i < nums.size(); i++) {
        if (numsFrqMap.find(nums[i]) != numsFrqMap.end()) {
            numsFrqMap[nums[i]]++;
        } else {
            numsFrqMap[nums[i]] = 1;
        }
    }
    for (auto itr: numsFrqMap) {
        if (numFrqQue.empty() || numFrqQue.size() <= k) {
            numFrqQue.push(numFrq{ itr.first, itr.second });
        } else {
            auto top = numFrqQue.top();
            if (top.frq < itr.second) {
                numFrqQue.pop();
                numFrqQue.push(numFrq{ itr.first, itr.second });
            }
        }

        //numsFrq.push_back(numFrq{ itr.first, itr.second });
    }

    //sort(numsFrq.begin(), numsFrq.end(), compFrq);
    vector<int> ans;
    while (!numFrqQue.empty()) {
        auto top = numFrqQue.top();
        ans.push_back(top.num);
        numFrqQue.pop();
    }
    //for (size_t i = 0; i < numsFrq.size() && i < k; i++) {
    //    cout << numsFrq[i].num << " : " << numsFrq[i].frq << endl;
    //    ans.push_back(numsFrq[i].num);
    //}
    return ans;
}