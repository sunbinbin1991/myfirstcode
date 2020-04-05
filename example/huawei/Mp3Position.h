#pragma once
#pragma once
#include<iostream>
#include<stack>
#include<deque>
#include<string>
#include<vector>
using namespace std;
void getMp3Pos(int num, const string& mov) {
	std::deque<int> result;
	std::vector<int> nums;
	for (int i = 0; i < num; i++)
	{
		if (result.size() < 4) {
			result.push_back(i);
		}
		nums.push_back(i);
	}
	int pos = 0;
	for (int i = 0; i < strlen(mov.c_str()); i++)
	{
		if (mov.at(i) == 'U') {
		//up
			if (pos == 0) {
				pos = num-1;
				result.clear();
				for (int j = 0; (j < num)&&(j<4); j++)
				{
					result.push_front(nums[num - j-1]);
				}
			}
			else if(pos==result.front()){
				pos--;
				result.push_front(pos);
				result.pop_back();
			}
			else {
				pos--;
			}

		}
		if (mov.at(i) == 'D') {
			//up
			if (pos == num-1) {
				pos = 0;
				result.clear();
				for (int j = 0; (j < num) && (j<4); j++)
				{
					result.push_back(nums[j]);
				}

			}
			else if (pos == result.back()) {
				pos++;
				result.pop_front();
				result.push_back(pos);
			}
			else {
				pos++;
			}
		}
	}
	int slen = result.size();
	//printf("size = %d\n ", slen);
	for (int i = 0; i < slen; i++)
	{
		printf("%d\n", result.front()+1);
		result.pop_front();
	}
	cout<<pos+1 << endl;
}

int test_getMP3Pos() {
	int num = 0;
	string mov;
	while (cin >> num) {
		cin >> mov;
		getMp3Pos(num, mov);
	}
	return 0;
}

