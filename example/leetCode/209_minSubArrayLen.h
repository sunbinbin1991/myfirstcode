//
// Created by s30001871 on 2021/8/24.
//

#ifndef MYFIRSTCODE_209_MINSUBARRAYLEN_H
#define MYFIRSTCODE_209_MINSUBARRAYLEN_H
#include <vector>

int calculateVector(vector<int>& nums, int start, int end){
    int ans = 0;
    for (int i = start; i <= end; ++i) {
        ans += nums[i];
    }
    return ans;
}

int minSubArrayLenQianzhui(int s, vector<int> & nums){
    int n = nums.size();
    if(n== 0 ) return 0;
    int ans = INT_MAX;
    vector<int> sum(n+1,0);
    for (int i = 0; i <= n ; ++i) {
        sum[i] = sum[i-1] + nums[i-1];
    }

    for (int j = 0; j <= n ; ++j) {
        int target = s+ sum[j-1];
        auto bound = lower_bound(sum.begin(), sum.end(), target);
        if(bound!= sum.end()){
            ans = min(ans, static_cast<int>(bound - sum.begin()) - (j-1));
        }
    }
    return ans == INT_MAX? 0 : ans;
}

int minSubArrayLen(int target, vector<int>& nums) {
    if(nums.empty()) return 0;
    int minLen = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            if(((j - i) > minLen)){
                continue;
            }
            int res = calculateVector(nums, i, j);
            cout << res <<",i:" << i <<",j:" << j <<endl;
            if(res == target) {
                minLen = min(minLen, j - i);
                cout << "ml " << minLen << endl;
            }
        }
    }
    return minLen == INT_MAX? -1: minLen +1;
}

void test_minSubArrayLen(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << minSubArrayLen(target, nums) << endl;
}
#endif //MYFIRSTCODE_209_MINSUBARRAYLEN_H
