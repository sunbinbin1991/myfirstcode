#pragma once
#include<iostream>
#include<vector>
using namespace std;
bool isNotPrimer(int num) {
	bool flag = false;
	for (size_t i = 2; i < num>>1; i++)
	{
		if (num % i == 0) {
			flag = true;
			return flag;
		}
	}
	return flag;
}

void getPrimerFactor(int num, std::vector<int>& primers) {
	for (size_t i = 2; i < num; i++)
	{
		if (!isNotPrimer(i)) {
			primers.push_back(i);
		}
	}
}
int getNearPrimer(int num) {
	if (num < 2) {
		return -1;
	}
	std::vector<int> primers;
	getPrimerFactor(num, primers);
	int min_val = INT_MIN;
	int a = 0;
	int b = 0;
	bool flag = false;
	for (size_t i = 0; i < primers.size(); i++)
	{
		for (size_t j = i; j <  primers.size(); j++)
		{
			cout << primers[i] <<"---"<< primers[j] << endl;
			if (primers[j] + primers[i] > num) {
				break;
			}
			if (primers[j] + primers[i] == num) {
				int val = abs(primers[j] - primers[i]);
				printf("val = %d\n", val);
				if (min_val < val) {
					a=  primers[i];
					b = primers[j];
					flag = true;
					//cout << primers[j] << endl;
				}
			}
		}
	}
	if (flag) {
		cout << a << endl;
		cout << b << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}
int test_getNearPrimer() {
	int num;
	while (cin>>num)
	{
		getNearPrimer(num);
	}
	return 0;
}