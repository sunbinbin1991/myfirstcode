#pragma once
#include<string>
#include<memory.h>
static constexpr int MOD = 1'000'000'007;

int checkRecord(int n)
{
    int dp[2][3];  // A ����������β���� L ������
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int dpNew[2][3];  // A ����������β���� L ������
        memset(dpNew, 0, sizeof(dpNew));
        // �� P ��β������
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                dpNew[j][0] = (dpNew[j][0] + dp[j][k]) % MOD;
            }
        }
        // �� A ��β������
        for (int k = 0; k <= 2; k++) {
            dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % MOD;
        }
        // �� L ��β������
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k <= 2; k++) {
                dpNew[j][k] = (dpNew[j][k] + dp[j][k - 1]) % MOD;
            }
        }
        memcpy(dp, dpNew, sizeof(dp));
    }
    int sum = 0;
    for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 2; k++) {
            sum = (sum + dp[j][k]) % MOD;
        }
    }
    return sum;
}
