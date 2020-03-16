#pragma once
//数独
#include<iostream>
#include<vector>
using namespace std;

int N, M; //分别代表行和列
vector<vector<int>> soduMatrix;//数独矩阵
void cal_sodu() {

}
void test_sodu() {
	soduMatrix = vector<vector<int>>(9, vector<int>(9, 0));
	for (auto &i : soduMatrix)
		for (auto &j : i)
			cin >> j;

}