#pragma once
#include<vector>
#include<map>
#include<set>
using namespace std;
bool test_uniqueOccurrences() {
    vector<int> input = { 1,2,3,2,1,3 };
    map<int, int> array2nums;
    for (size_t i = 0; i < input.size(); i++) {
        if (array2nums.find(input[i]) != array2nums.end()) {
            array2nums[input[i]] += 1;
        } else {
            array2nums[input[i]] = 1;
        }
    }
    set<int> res;
    for (auto map1 : array2nums) {
        if (res.find(array2nums[map1.first])!=res.end()) {
            return false;
        } else {
            res.emplace(array2nums[map1.first]);
        }
    }
    return true;
}