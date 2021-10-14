class Solution583 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; j++) {
                char c2 = text2.at(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int minDistance(string word1, string word2) {
        if(word2.empty() && word1.empty()) return 0;
        if(word2.empty()) return word1.size();
        if(word1.empty()) return word2.size();
        int s = longestCommonSubsequence(word1, word2);
        return word1.size() - s + word2.size() - s;
    }
};
