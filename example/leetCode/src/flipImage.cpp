#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
#include <bitset>
using namespace std;

void swapcode(vector<int>& v, int i, int j) {
	if (i<j) {
		int tmp = 1 - v[i];
		v[i] = 1 - v[j];
		v[j] = tmp;
	}
	else {
		v[i] = 1 - v[i];
	}
}
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j<(A[i].size() + 1) / 2; j++) {
			swapcode(A[i], j, A[i].size() - j - 1);
		}
	}
	return A;
}


int main_5() {
	vector<vector<int>> A;
	A.resize(3);
	for (int i = 0; i < 3; i++) {
		A[i].resize(4);
	}
	for (int i = 0; i< 3; i++) {
		for (int j = 0;j < 4; j++) {
			A[i][j] = i+j;
		}
	}
	vector<vector<int>> res = flipAndInvertImage(A);
	
	for (int i = 0; i<4 ; i++) {
		for (int j = 0; j < 3; j++) {
			cout << res[i][j] << endl;
		}
	}
	system("pause");
	return -1;
}