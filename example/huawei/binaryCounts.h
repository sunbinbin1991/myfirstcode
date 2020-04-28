#pragma once
#include<iostream>
using namespace std;
int binaryCounts(int num) {
	if (num <= 0) return 0;
	int res = 0;
	while (num >= 1) {//this way maybe not proper
		if (num & 1) {
			res++;
		}
		num = num >> 1;
	}
	return res;
}

int test_binaryCounts() {
	int num;
	while (cin >> num)
	{
		int res = binaryCounts(num);
		cout << res << endl;
	}
	return 0;
}