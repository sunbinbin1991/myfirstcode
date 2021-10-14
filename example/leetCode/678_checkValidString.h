bool checkValidString(string s) {
    int len = s.size();
    vector<vector<bool>> dp(len + 1, vector<bool>(len + 1)); // 从 i
    dp[0][0] = true;
    for (int i = 1; i <= len; ++i) {
        char c = s[i - 1];
        for (int j = 0; j <= i; ++j) {
            if(c == '(') {
                if(j >= 1) {
                    dp[i][j] = dp[i-1][j-1];
                }
            } else if(c == ')'){
                if(j + 1 <= i) {
                    dp[i][j] = dp[i-1][j + 1];
                }
            } else {
                dp[i][j] = dp[i-1][j];
                if(j>=1)  dp[i][j] = dp[i][j] | dp[i-1][j-1];
                if(j + 1 <= i)  dp[i][j] = dp[i][j] | dp[i-1][j+1];
            }
        }
    }
    return dp[len][0];
}
