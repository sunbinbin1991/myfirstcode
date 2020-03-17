#pragma once
#include<iostream>
#include<string>
using namespace std;
int test_split_str_by_nums() {
	string input;
	while (cin >> input) {
		int nums;
		cin >> nums;
		//printf("input = %s\n", input.c_str());
		//printf("input = %d\n", input.size());
		//int size = input.size();
		//int temp = nums - 1;
		//while (temp >= 0 && input[temp] < 0)
		//	temp--;
		cout << input.substr(0, nums) << endl;
		//cout << input.substr(0, temp).size() << endl;
	}

	return 0;
}