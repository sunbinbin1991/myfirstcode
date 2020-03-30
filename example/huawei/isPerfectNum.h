#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
bool getprimefactor2(int num) {
	//if (num <= 0) return;
	//int i = 2;
	//while (num >= 2) {
	//	if (num % i == 0) {
	//		cout << i << endl;
	//		primers.push_back(i);
	//		while (num%i == 0) {
	//			num /= i;
	//		}
	//	}
	//	i++;
	//}
	std::vector<int> primers;
	for (size_t i = 1; i <num; i++)
	{
		if (num%i == 0) {
			primers.push_back(i);
		}
	}
	return num==std::accumulate(primers.begin(), primers.end(), 0);
}

void isPerfactNum(int num) {
	int res = 0;
	for (size_t i = 2; i <= num; i++)
	{
		if (getprimefactor2(i)) {
			res++;
			std::cout <<"loop = "<< i << endl;
		};
	}
	std::cout << res << endl;
}

int test_isPerfactNum() {
	int num;
	while (cin>>num) {
		isPerfactNum(num);
	}
	return 0;
}