#pragma once
//����
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
	for (int i = 0; i < cols; i++) { /*���ڵ����Ƿ���������*/
		if (a[row][i] == value)  return false;
	}
	for (int i = 0; i < rows; i++) {/*���ڵ����Ƿ���������*/
		if (a[i][col] == value)  return false;
	}
	for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {/*���ڵĴ��߸��Ƿ���������*/
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
			if (check(row, col, i)) {//�ж���ǰλ��,��ֵΪi�Ƿ��������
				a[row][col] = i;
				if (col == 8) {/*�����һ��ֵ*/
					dfs(row + 1, col - 8);
				}
				else {
					dfs(row , col+1);
				}

				if (!signal) {/*�����ж�*/
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
	for (int i = 0; i < rows; i++) {/*��ӡ*/
		for (int j = 0; j < cols - 1; j++)
			cout << a[i][j] << ' ';
		cout << a[i][8];
		cout << endl;
	}

}


/*����ģ��
int check(����)
{
	if(��������)
		return 1;
	return 0;
}

void dfs(int step)
{
	�жϱ߽�
	{
		��Ӧ����
	}
	����ÿһ�ֿ���
	{
		����check����
		���
		������һ��dfs(step+1)
		�ָ���ʼ״̬�����ݵ�ʱ��Ҫ�õ���
	}
}
*/