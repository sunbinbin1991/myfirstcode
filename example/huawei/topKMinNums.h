#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include <functional>   // std::greater
using namespace std;

void test_topKminNums() {
	int inputNums;
	int topK;
	cin >> inputNums;
	cin >> topK;
	std::vector<int> nums;
	while (inputNums--)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	
	}
	std::sort(nums.begin(), nums.end(), std::less<int>());
	for (size_t i = 0; i <topK; i++)
	{
		cout << nums[i]<<" ";
	}
	cout << endl;
}