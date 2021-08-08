#pragma once
#include<vector>
#include<iostream>
using namespace std;
vector<int> exchange(vector<int>& nums)
{
    if (nums.empty()) return{};
    int left = 0;
    int n = nums.size();
    int leftcout = 0;
    while (left < n) {
        if (nums[left] & 1 != 0) { // ÆæÊý
            swap(nums[leftcout++], nums[left]);
        }
        left++;
    }
    cout << (5 & 1) << std::endl;
    cout <<( 4 & 1) << endl;
    cout << (3 & 1) << endl;
    cout << (2 & 1) << endl;
    cout << (1 & 1 ) << endl; 
    return nums;
}

void test_exchange() {
    vector<int> nums = { 1,2,3,4 };
    auto ans = exchange(nums);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}