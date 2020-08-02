#pragma once
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int maxStockProfit(vector<int>& prices)
{
    if (prices.empty() || prices.size() == 1) return 0;
    auto start = prices.begin();
    auto second = prices.begin() + 1;
    int maxPro = 0;

    while (start < prices.end() - 1) {
        maxPro = max(*second - *start, maxPro); //º¯ÊýÔÚalgorithmÀï
        if (*second <= *start || second >= prices.end() - 1) {
            start += 1;
            second = start + 1;
            continue;
        }
        second = second + 1;
    }
    printf("%d\n", maxPro);
}
void test_maxStockProfit()
{
    vector<int> nums1 = { 15, 2, 3, 4, 3, 9 };
    vector<int> nums2 = { 7,5,3,1 };
    int res = maxStockProfit(nums1);
    res = maxStockProfit(nums2);
}