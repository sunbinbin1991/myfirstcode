#pragma once
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    std::map<int, int> arr2Map;
    for (auto itr: arr2) {
        arr2Map[itr] = 1;
    }
    vector<int> res(arr1.size() - arr2.size());
    int resIndex = 0;
    for (auto itr : arr1) {
        if (arr2Map.find(itr) != arr2Map.end()) {
            arr2Map[itr] ++;
        } else {
            res[resIndex] = itr;
            resIndex++;
        }
    }
    vector<int> temp;
    for (size_t i = 0; i < arr2.size(); i++) {
        for (size_t j = 0; j < arr2Map[i]; j++) {
            temp.push_back(arr2[j]);
        }
    }
    sort(res.begin() + arr2.size(), res.end());
    for (size_t i = 0; i < res.size(); i++) {
        temp.push_back(res[i]);
    }
    return temp;
}