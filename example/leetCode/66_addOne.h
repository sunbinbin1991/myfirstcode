#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> plusOne(vector<int>& digits)
{
    if (digits.empty())  return {};

    vector<int> res;
    int len = digits.size();
    std::reverse(digits.begin(),digits.end());
    int extraNum = 0;
    for (int i = 0; i < len; i++) {
        int num = 0;
        i == 0 ? num = digits[i] + 1 : num = digits[i] + extraNum;
        if (num >= 10) {
            digits[i] = num % 10;
        } else {
            i == 0 ? digits[i] += 1: digits[i] += extraNum;
        }
        
        extraNum = num / 10;
    }
    if (extraNum) {
        digits.push_back(1);
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

void test_plusOne()
{
    vector<int> digits = { 9,9,9,8 };
    vector<int> res = plusOne(digits);

    for (auto itr : res) {
        printf("%d ", itr);
    }
}