#pragma once

int findKthLargest(vector<int>& nums, int k)
{
    if (nums.empty() || k <= 0) return 0;
    priority_queue<int,vector<int>,greater<int>> pQue;
    for (int i = 0; i < nums.size(); i++) {
        if (pQue.empty() || pQue.size() < k) {
            pQue.push(nums[i]);
        } else {
            if (pQue.top() < nums[i]) {
                pQue.push(nums[i]);
            }
        }
    }
    int ans = 0;
    int del = pQue.size() - k + 1;
    while (!pQue.empty() && del--) {
        ans = pQue.top();
        cout << pQue.top() << endl;
        pQue.pop();
    }
    cout << "ans = "<< ans << endl;
    return ans;
}

void test_findKthLargest() {
    vector<int> nums = { 3,1,2,4,78,9,65 };
    findKthLargest(nums, 5);
}