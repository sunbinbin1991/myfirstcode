// 动态规划，dp[i] 从0到i这些值中完全平方数的最小数量  错误解释
// 动态规划，dp[i] 最少需要多少个完全平方数来组成整数i
int numSquares(int n) {
    vector<int> dp(n + 1);
    int minVal = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            minVal = min(minVal, dp[i - j * j]);
//            minVal = dp[i];
        }
        dp[i] = minVal + 1;
    }
    return dp[n];
}
