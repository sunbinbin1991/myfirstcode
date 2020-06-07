#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
string longestPalindrome_leetcode(string s)
{
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n));
	string ans;
	for (int l = 0; l < n; ++l) {
		for (int i = 0; i + l < n; ++i) {
			int j = i + l;
			if (l == 0) {
				dp[i][j] = 1;
			} else if (l == 1) {
				dp[i][j] = (s[i] == s[j]);
			} else {
				dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
			}
			if (dp[i][j] && l + 1 > ans.size()) {
				ans = s.substr(i, l + 1);
			}
		}
	}
	return ans;
}


void longestPalindro(string & input) 
{
	int i, j;
	int len = input.size();
	vector<vector<int>> DP(len,vector<int>(len,0));
	
	string strrev = input;
	std::reverse(strrev.begin(), strrev.end());

	for (int i = 0; i < len; i++) {
		DP[i][0] = 1;
		DP[0][i] = 1;
	}
	int max_len = 1;
	int maxEnd  = 1;
	std::pair<int, int> pairIndex;
	cout << " 0 " << input << endl;
	cout << " 1 " << strrev << endl;
	for (int i = 1; i < len; i++) {
		for (int j = 1; j < len; j++) {
			if (input[i] == strrev[j]) {
				DP[i][j] = DP[i-1][j-1] + 1;
			}

			if (DP[i][j] > max_len) {
				int beforeRev = len - 1 - j;
				if (beforeRev + DP[i][j] - 1 == i) { //判断下标是否对应
					max_len = DP[i][j];
					maxEnd = i;
					pairIndex.first = i - max_len + 1;
					pairIndex.second = max_len + 1;
				}
			}
		}
	}
	printf("\n%s\n", input.substr(pairIndex.first, pairIndex.second).c_str());
	for (int i = 1; i < len; i++) {
		for (int j = 1; j < len; j++) {
			//cout << "DP = " << DP[i][j] << endl;
		}
	}
}

void test_longestPalindro() 
{
	string input;
	while (cin >> input) {
		printf("input %s", input.c_str());
		longestPalindro(input);
	}
}