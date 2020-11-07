#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// https://leetcode-cn.com/problems/count-of-range-sum/solution/
int cmp(const void * a, const  void *b)
{
    cout << (int *)a << endl;
    cout << (int *)b << endl;
    cout << *(int *)a << endl;
    cout << *(int *)b << endl;
    return *(int*) a - *(int *)b;
}

int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right)
{
    if (left == right) {
        return 0;
    } else {
        int mid = (left + right) / 2;
        int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
        int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
        int ret = n1 + n2;

        // 首先统计下标对的数量
        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        while (i <= mid) {
            while (l <= right && sum[l] - sum[i] < lower) l++;
            while (r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }

        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = sum[p2++];
            } else if (p2 > right) {
                sorted[p++] = sum[p1++];
            } else {
                if (sum[p1] < sum[p2]) {
                    sorted[p++] = sum[p1++];
                } else {
                    sorted[p++] = sum[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            sum[left + i] = sorted[i];
        }
        return ret;
    }
}

int countRangeSum_opt(vector<int>& nums, int lower, int upper)
{
    long s = 0;
    vector<long> sum{ 0 };
    for (auto& v : nums) {
        s += v;
        sum.push_back(s);
    }
    return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
}


// 超时解法
int countRangeSum(vector<int>& nums, int lower, int upper)
{
    if (nums.empty()) return 0;
    //qsort(nums.data(), nums.size(), sizeof(int), cmp);
    int res = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (size_t j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum >= lower && sum <= upper) {
                res++;
            }
        }
    }
    return res;
}

void test_countRangeSum()
{
    vector<int> nums = { 2,3,45,7,9,15 };
    int res = countRangeSum(nums, 3, 20);
    cout << res;
}