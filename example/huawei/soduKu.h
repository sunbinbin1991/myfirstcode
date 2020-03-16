#pragma once
//数独
#include<iostream>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
int rows = 9, cols = 9;
int a[9][9];
bool signal = false;
//https://www.nowcoder.com/practice/78a1a4ebe8a34c93aac006c44f6bf8a1?tpId=37&tqId=21267&tPage=3&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
//check whether this col or row has this value
bool check(int row, int col, int value) {
	for (int i = 0; i < cols; i++) { /*所在的行是否满足条件*/
		if (a[row][i] == value)  return false;
	}
	for (int i = 0; i < rows; i++) {/*所在的列是否满足条件*/
		if (a[i][col] == value)  return false;
	}
	for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {/*所在的粗线格是否满足条件*/
		for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
			if (a[i][j] == value)  return false;
		}
	}
	return true;
}

bool dfs(int col, int row) { 
	if (col >= 9 || row >= 9) {
		signal = true;
		return true;
	}
	if (a[row][col] == 0) {
		for (size_t i = 0; i < 9; i++)
		{
			if (check(row, col, i)) {//判定当前位置,该值为i是否符合条件
				a[row][col] = i;
				if (col == 8) {/*检查下一个值*/
					dfs(row + 1, col - 8);
				}
				else {
					dfs(row , col+1);
				}

				if (!signal) {/*回溯判断*/
					a[row][col] = 0;
				}
			}
		}
	}
	else {
		if (col == 8) {
			dfs(row + 1, col - 8);
		}
		else dfs(row , col +1);
	}
	return false;

}

void test_sodu() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			cin >> a[i][j];
		}

	dfs(0, 0);
	for (int i = 0; i < rows; i++) {/*打印*/
		for (int j = 0; j < cols - 1; j++)
			cout << a[i][j] << ' ';
		cout << a[i][8];
		cout << endl;
	}

}


/*回溯模板
int check(参数)
{
	if(满足条件)
		return 1;
	return 0;
}

void dfs(int step)
{
	判断边界
	{
		相应操作
	}
	尝试每一种可能
	{
		满足check条件
		标记
		继续下一步dfs(step+1)
		恢复初始状态（回溯的时候要用到）
	}
}
*/