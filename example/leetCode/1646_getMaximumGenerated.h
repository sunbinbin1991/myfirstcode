    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        int i = 2;
        while(i <= n) {
            if(i % 2 == 0){
                dp[i] = dp[i/2];
            } else {
                dp[i] = dp[i/2] + dp[i/2 + 1];
            }
            i++;
        }
        int maxNum = INT_MIN;
        maxNum = *max_element(dp.begin(), dp.end());
        // for (int i = 0; i <= n; ++i){
        //     maxNum = max(dp[i], maxNum);
        // }
        return maxNum;
    }
