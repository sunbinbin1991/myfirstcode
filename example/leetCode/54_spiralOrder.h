#pragma once
#include<vector>
#include<iostream>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    if (matrix.empty()) return{};
    int row = matrix.size();
    int col = matrix[0].size();

    int c = 0;
    int r = 0;
    int loopTimes = row * col;
    vector<int> res;
    while (loopTimes) {
        // turn Right
        for (int k = c; k < col && loopTimes > 0; ++k) {
            res.push_back(matrix[r][k]);
            // cout << "R " <<res.back() << endl;
            loopTimes--;
        }
        r += 1;

        // turn down
        for (int m = r; m < row && loopTimes > 0; ++m) {
            res.push_back(matrix[m][col - 1]);
            // cout << "D " << res.back() << endl;
            loopTimes--;
        }
        col -= 1;

        // turn left
        for (int k = col - 1; k >= c && loopTimes > 0; --k) {
            res.push_back(matrix[row - 1][k]);
            // cout << "L " << res.back() << endl;
            loopTimes--;
        }

        row -= 1;
        // turn up
        for (int k = row - 1; k >= r && loopTimes > 0; --k) {
            res.push_back(matrix[k][c]);
            // cout << "U " << res.back() << endl;
            loopTimes--;
        }
        c += 1;
    }
    return res;
}

void test_spiralOrder() {
    vector<vector<int>> matrix = { {1,2,3},{ 4,5,6 },{ 7,8,9 } };
    spiralOrder(matrix);
}