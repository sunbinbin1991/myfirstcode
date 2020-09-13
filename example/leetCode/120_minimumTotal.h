#pragma once
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cmath>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle)
{
    if (triangle.empty()) return 0;
    if (triangle.size() == 1) return triangle[0][0];
    int len = triangle.size();
    vector<vector<int>> DP(len + 1, vector<int>(len + 1));

    DP[0][0] = triangle[0][0];
    DP[1][0] = triangle[0][0] + triangle[1][0];
    DP[1][1] = triangle[0][0] + triangle[1][1];

    for (int i = 2; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                DP[i][0] = DP[i - 1][0] + triangle[i][0];
            } else if (j == i) {
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            } else {
                if (DP[i - 1][j - 1] < DP[i - 1][j]) {
                    DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
                } else {
                    DP[i][j] = DP[i - 1][j] + triangle[i][j];
                }
            }
        }
    }
    int minRes = DP[len-1][0];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" %d", DP[i][j]);
        }
        printf(" \n");
    }
    for (int i = 0; i < len; i++) {
        minRes = min(minRes, DP[len - 1][i]);
    }
    return minRes;
}

void test_minimumTotal(){
    vector<vector<int>> triangle = { {2},{3,4},{6,5,6},{4,1,8,3} };

    int res = minimumTotal(triangle);
    printf("res = %d", res);
}