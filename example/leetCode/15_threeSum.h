#pragma once
#include <vector>
#include <iostream>
using namespace std;
//1: ��Ҫ�����ǿ��ж�
//2: ˫ָ��

int cp_less(const void *a,const void *b) {
	int s = *(int*)a;
	int t = *(int*)b;
	return *(int *)a - *(int *)b;
}
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.empty()) {
		return res;
	}
	qsort(nums.data(), nums.size(), sizeof(int),cp_less);
	for (size_t i = 0; i < nums.size(); i++) {
		cout << nums[i] << endl;
	}
	return res;
}

void test_threeSum() {
	vector<int> input = { 3, -5, -3,- 9, 1, 2, 4, 9 ,0};
	threeSum(input);
}