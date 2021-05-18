#pragma once
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }

int trap2(vector<int>& height) {
    if (height.empty()) return 0;
    stack<int> stk;
    int le = height.size();
    int ans = 0;
    for (size_t i = 0; i < le; i++) {
        while (!stk.empty() && height[stk.top()] < height[i]) {
            int top = stk.top();
            stk.pop();
            if (stk.empty()) {
                break;
            }
            int left = stk.top();
            int width = i - left - 1;
            int hei = min(height[left], height[i] - height[top]);
            ans += width * hei;
        }
        stk.push(i);
    }
    return ans;
}

void test_trap() {
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int res = trap(height);
    cout << "res " << res;
}