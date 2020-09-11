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
    int len = triangle.size();
    vector<vector<int>> DP(len + 1, vector<int>(len + 1));

    DP[0][0] = triangle[0][0];
    for (int i = 1; i < len; i++) {
        //DP[i][0] = triangle[i - 1][0] + DP[i - 1][0];
    }

    for (int i = 1; i < len; i++) {
        for (size_t j = 0; j < i-1; j++) {
            if (triangle[i-1][j + 1] < triangle[i-1][j]) {
                DP[i][j] = DP[i-1][j] + triangle[i - 1][j + 1];
            } else {
                DP[i][j] = DP[i - 1][j] + triangle[i - 1][j];
            }
        }
    }

    for (int i = 1; i < len; i++) {
        for (size_t j = 0; j < i; j++) {
            printf(" %d", DP[i][j]);
        }
        printf(" \n");
    }

    return 0;
}

void test_minimumTotal(){
    vector<vector<int>> triangle = { {2},{3,4},{6,5,6},{4,1,8,3} };

    int res = minimumTotal(triangle);
    printf("res = %d", res);
}