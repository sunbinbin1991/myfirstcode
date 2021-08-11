#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int numDecodings(string s)
{
    int len = s.size();
    if (s[0] == '0') {
        return 0;
    }
    vector<int> dp(len + 1);
    dp[0] = 1;
    for (int i = 1; i <= len; i++) {
        if (s[i - 1] - '0' != 0) {
            dp[i] += dp[i - 1];
        }
        if (i > 1) {
            auto two = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    }
    return dp[len];
}