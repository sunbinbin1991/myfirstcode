#pragma once
#include<iostream>
using namespace std;
void GetResult(int Num, char* pResult) {
	int sum = (Num + 1)*Num >> 1;
	int count = 0;
	for (size_t i = 1; i <= Num; i++)
	{
		for (size_t j = i; j <= Num; j++)
		{
			int first_Num = (j*(j + 1)) /2 -i+1;
			cout << first_Num << "\t";
			pResult[count++] = first_Num;
		}
		cout << "\n";
	}
}

void test_snake_matrix() {
	int num;
	while (cin >> num) {
		int sum = (num + 1)*num >> 1;
		printf("sum = %d\n", sum);
		char* pResult = new char[sum];
		memset(pResult,'0',sizeof(char)*sum);
		GetResult(num, pResult);
		for (size_t i = 0; i < sum; i++)
		{
			printf("%d\t", pResult[i]);
		}
	}
}