#pragma once
#include<vector>
#include<deque>
#include<algorithm>
#include<map>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution1498 {
public:
    static constexpr int P = int(1E9) + 7;
    static constexpr int MAX_N = int(1E5) + 5;

    int f[MAX_N];

    void pretreatment()
    {
        f[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            f[i] = (long long)f[i - 1] * 2 % P;
        }
    }

    int numSubseq(vector<int>& nums, int target)
    {
        pretreatment();

        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; ++i) {
            int maxValue = target - nums[i];
            int pos = upper_bound(nums.begin(), nums.end(), maxValue) - nums.begin() - 1;
            int contribute = (pos >= i) ? f[pos - i] : 0;
            ans = (ans + contribute) % P;
        }

        return ans;
    }
};

int numSubseq(vector<int>& nums, int target)
{
    if (nums.empty()) return 0;
    int left = 0;
    int right = 0;
    int valid = 0;
    long long num = 0;
    unordered_map<int, int> need;
    unordered_map<int, int> window;
    //priority_queue<pair<int, int>> test;
    sort(nums.begin(), nums.end());
    while (right < nums.size()) {
        int n = nums[right];
        right++;
        
        window[right - 1] = n;

        int minTemp = INT_MAX;
        int maxTemp = INT_MIN;
        for (size_t i = 0; i < window.size(); i++) {
            minTemp = min(window[i], minTemp);
            maxTemp = max(window[i], maxTemp);
        }
        if (minTemp + maxTemp <= target) {
            num += (right - left + 1);
          
        }

        while(left < right){
            int n = nums[left];
            left++;
            window.erase(left - 1);
            int minTemp = INT_MAX;
            int maxTemp = INT_MIN;
            for (size_t i = 0; i < window.size(); i++) {
                minTemp = min(window[i], minTemp);
                maxTemp = max(window[i], maxTemp);
            }

            if (minTemp + maxTemp <= target) {
                num += (right - left + 1);
            }
        }
    }
    return num;
}