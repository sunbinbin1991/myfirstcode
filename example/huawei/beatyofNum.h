#pragma once
#include<iostream>
#include<vector>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
void bubbleSort(vector<int>& input) {
	std::sort(input.begin(), input.end());
}

int nameOfBeauty(const string& str) {
	vector<int> cnt(26);
	string tmp = str;
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
	//printf("input %s\n", tmp.c_str());
	for (size_t i = 0; i < tmp.size(); i++)
	{
		char tmpchar = tmp.at(i);
		cnt[tmpchar - 'a']++;
	}
	bubbleSort(cnt);
	int num = 26;
	int sum = 0;
	for (int i = cnt.size()-1; i >=0 ; i--)
	{
		//printf("%d\n", cnt[i]);
		if (cnt[i] > 0) {
			sum += (num--)*cnt[i];
		}
	}
	printf("%d\n", sum);
	return sum;
}

int test_name_of_beauty() {
	int num;
	cin >> num;
	while (num--) {
		string input;
		cin >> input;
		nameOfBeauty(input);
	}
	return 0;
}
