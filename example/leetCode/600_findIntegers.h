    int findIntegers(int n){
        vector<int> dp(31);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        int pre = 0, res = 0;
        for (int j = 29; j >= 0 ; j--) {
            int val = 1 << j;
            if((n&val) != 0){
                n -= val;
                res += dp[j + 1];
                if(pre == 1) break;
                pre = 1;
            } else {
                pre = 0;
            }
            if(j==0) res++;
        }
        return  res;
    }
