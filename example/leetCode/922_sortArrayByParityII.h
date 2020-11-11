#pragma once
#include<vector>
#include<algorithm>

void test_sortArrayByParityII() {
    vector<int> nums = { 4,2,5,7};
    vector<int> odd;
    vector<int> even;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] & 1) {
            odd.push_back(nums[i]);
        } else {
            even.push_back(nums[i]);
        }
    }

    for (size_t i = 0; i < nums.size(); i++) {
        if (i & 1) {
            nums[i] = odd[i/2];
        } else {
            nums[i] = even[i/2];
        }
        printf("%d ", nums[i]);
    }
}