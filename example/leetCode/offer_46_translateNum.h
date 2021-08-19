#pragma once
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
#define MIN_LETTERNUM  10
#define MAX_LETTERNUM  26
int translateNum2(int num)
{
    string str = "0" + std::to_string(num);
    vector<int> dp(str.size(), 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < str.size(); ++i) {
        dp[i] = dp[i - 1];
        int val = std::stoi(str.substr(i - 1, 2));
        if (10 <= val && val <= 25) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[str.size() - 1];
}


int translateNum(int num)
{
    string s = std::to_string(num);
    vector<bool> vis(s.size());
    int ans = 0;
    string paht = "";
    for (size_t i = 0; i < s.size(); i++) {
        cout << vis[i] << endl;
    }
    dfsTransNum(ans, s, vis, paht);
    return 0;
}

void test_translateNum() {
    int num = 12258;
    translateNum(num);
}