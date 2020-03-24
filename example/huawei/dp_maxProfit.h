#pragma once
//url: https://www.hackerearth.com/zh/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;

int input[100];
int loop_time = 0;
int loop_time_year = 0;
int loop_time_cache = 0;

const int N = 5;
std::vector<std::vector<int>> cache(N, vector<int>(N, -1));

int profit(int beg, int end) {
	if (beg > end) {
		return 0;
	}
	int year = N - (end - beg);
	
	printf("loop_time = %d\n", loop_time++);

	return std::max(profit(beg+1, end)+year * input[beg]
		, profit(beg, end-1)+year * input[end]);
}

int profit_year(int year,int beg, int end) {
	if (beg > end) {
		return 0;
	}
	printf("profit_year loop_time = %d\n", loop_time_year++);

	return std::max(profit_year(year + 1,beg + 1, end) + year * input[beg]
		, profit_year(year + 1,beg, end - 1) + year * input[end]);
}

int get_maxprofit_cache(int beg, int end) {
	if (beg > end) {
		return 0;
	}
	if (cache[beg][end] != -1) {
		return cache[beg][end];
	}
	int year = N - (end - beg);

	printf("loop_time_cache = %d\n", loop_time_cache++);

	return cache[beg][end] = std::max(get_maxprofit_cache(beg + 1, end) + year * input[beg]
		, get_maxprofit_cache(beg, end - 1) + year * input[end]);

}


void get_maxprofit(const std::vector<int>& nums) {
	
	int maxProfit = profit_year(1, 0, nums.size() - 1);
	printf("profit_year = %d\n", maxProfit);
	
	maxProfit = profit(0, nums.size()-1);
	printf("max profix = %d\n", maxProfit);

	maxProfit = get_maxprofit_cache(0, nums.size() - 1);
	printf("get_maxprofit_cache = %d\n", maxProfit);
}

int test_maxprofit() {
	std::vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		input[nums.size() - 1] = num;
	}
	get_maxprofit(nums);

	return 0;
}