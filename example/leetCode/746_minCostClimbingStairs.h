int minCostClimbingStairs_wrongans(vector<int>& cost) {
    if(cost.empty()) return 0;
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = min(cost[0], cost[1]);
    for (int i = 2; i < cost.size(); ++i) {
        dp[i] = min(dp[i-2] + cost[i], dp[i-1]);
    }
    for (int j = 0; j < cost.size(); ++j) {
        cout << dp[j];
    }
    cout << endl;
    return dp[cost.size()-1];
}

//其中 dp[i] 表示达到下标 i 的最小花费
int minCostClimbingStairs(vector<int>& cost) {
    if(cost.empty()) return 0;
    vector<int> dp(cost.size() + 1);
    // dp[0] = 0;
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
        dp[i] =  min(dp[i-2] , dp[i-1]) + cost[i];
        // min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
    }
    for (int j = 0; j < cost.size(); ++j) {
        // cout << j << ": "<< dp[j] << " " << endl;
    }
    // cout << endl;
    return min(dp[cost.size()-1],dp[cost.size()-2]);
}
