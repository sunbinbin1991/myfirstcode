#pragma once
#include<vector>
#include<iostream>
using namespace std;
void test_findNumberIn2DArray()
{
    vector<vector<int>> matrix = 
        { { 1,4,7,11,15 },
          { 2,5,8 ,12,19},
          { 3,6,9, 16,22},
          {18,21,23,26,30}
    };
    spiralOrder(matrix);
}