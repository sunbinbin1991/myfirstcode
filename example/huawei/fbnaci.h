#pragma once
#include<iostream>
#include<string>
using namespace std;
int fbnaci(int num) {
	if (num <= 2) {
		return 1;
	}
	return fbnaci(num-2) + fbnaci(num - 1);
}
int fbnaci_better(int num) {
	int first = 1;
	int second = 1;
	int sum = 0;
	for (size_t i = 2; i < num; i++)
	{
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}

int test_fbnaci() {
	int mouth;
	cin >> mouth;
	int num = fbnaci_better(mouth);
	cout << "num = " << num;
	return 0;
}