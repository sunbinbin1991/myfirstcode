#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
//jufnsojxgsnswvrsfmwpagmjqidiwqhqfomcnfsqmrckcabmbykdpwwqwctoqctdfbmawplvjtsyqrckidbgnfgwohnraopnavlk
//emrnerjquhqdthawyroaqxjxnjwiymnpdunrzmqkgbtaqrivkozwuowvvijrbbhcyzsyaqmhthrexnuighhcuawrwulcqilhaxaakdcfkekmegjbf
void CombineBySort(int* pArray1, int iArray1Num, int* pArray2, int iArray2Num, int* pOutputArray, int* iOutputNum) {

};

int cmpfunc(const void * a, const void * b)
{
	return (*(int*)a > *(int*)b);
}

int test_findstring() {
	string shortstr, longstr;
	while (cin >> shortstr >> longstr) {
		int len_short = strlen(shortstr.c_str());
		int flag = true;
		int totol_flag[255];
		memset(totol_flag, 0, sizeof(int) * 255);
		for (int i = 0; i < longstr.size(); i++)
		{
			totol_flag[longstr[i]]++;
		}
		for (int i = 0; i < shortstr.size(); i++)
		{
			int num = shortstr[i];
			if (totol_flag[num]==0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
		
	}
	return 0;
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