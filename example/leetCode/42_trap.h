#pragma once
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int trap(vector<int>& height)
{
    if (height.empty()) return 0;
    stack<int> stk;
    int le = height.size();
    int ans = 0;
    for (size_t i = 0; i < le; i++) {
        while (!stk.empty() && height[stk.top()] < height[i]) {
            int left =stk.top();
            stk.pop();
            if (stk.empty()) {
                break;
            }
            int width = i - left;
            int hei = height[i] - height[left];
            cout << "W " << width << endl;
            cout << "h " << hei << endl;
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