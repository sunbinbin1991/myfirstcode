#pragma once
//����
#include<iostream>
#include<vector>
using namespace std;

int N, M; //�ֱ�����к���
vector<vector<int>> soduMatrix;//��������
void cal_sodu() {

}
void test_sodu() {
	soduMatrix = vector<vector<int>>(9, vector<int>(9, 0));
	for (auto &i : soduMatrix)
		for (auto &j : i)
			cin >> j;

}