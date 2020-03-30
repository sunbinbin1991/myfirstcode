#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void test_getNumsOfSenvenRelated() {
	int nums;
	while (cin >> nums) {
		int res = 0;
		for (size_t num = 1; num <= nums; num++)
		{
			if ((num % 7 == 0) || (num % 10 == 7) || (num / 10 % 10 == 7) || (num / 100 % 10 == 7) || (num / 1000 % 10 == 7)) {
				res++;
			}
		}

		cout << res << endl;
	}
}