#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void CombineBySort(int* pArray1, int iArray1Num, int* pArray2, int iArray2Num, int* pOutputArray, int* iOutputNum) {

};

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a > *(int*)b);
}

int test_combinebysort() {
	int num1, num2;
	std::vector<int> input;
	while (cin >> num1) {
		while (num1--)
		{
			int tmp;
			cin >> tmp;
			input.push_back(tmp);
		}
		cin >> num2;
		while (num2--)
		{
			int tmp;
			cin >> tmp;
			input.push_back(tmp);
		}
		std::qsort(input.data(), input.size(), sizeof(int), cmpfunc);
		if (!input.empty()) {
			printf("%d", input[0]);
		}
		
		for (size_t i = 1; i < input.size(); i++)
		{
			if(input[i]!= input[i-1])
				printf("%d", input[i]);
		}
	}
	return 0;

}