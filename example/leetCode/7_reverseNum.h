#pragma once
#include<vector>
using namespace std;
int reverse(int x) {
	vector<int> input;
	if (x >= (0x7fffffff) || x <= (-1 * pow(2, 31))) return 0;
	int tmp = x;
	if (x<0) {
		tmp = -1 * x;
	}
	while (tmp) {
		input.push_back(tmp % 10);
		tmp = tmp / 10;
	}
	long res = 0;
	int zero_num = 0;
	for (int i = 0; i< input.size(); i++) {
		if (input[i] == 0) {
			zero_num++;
			continue;
		}
		res += input[i] * pow(10, input.size() - 1 - (i));
	}
	if (res>(0x7fffffff) || res<(-1 * pow(2, 31))) return 0;
	if (x<0) return -1 * res;
	return res;
}