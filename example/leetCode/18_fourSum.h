#pragma once
#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	if (nums.empty()) return {};
	sort(nums.begin(), nums.end());
	if (nums.size() < 4) {
		return {};
	}
	int one, two, three, four;
	int len = nums.size();
	for (size_t i = 0; i < len; i++) {
		cout << nums[i] << endl;
	}
	vector<vector<int>> res;
	for (int i = 0; i <= len - 4; i++) {
		for (int j = i+1; j <= len - 3; j++) {
			for (int m = j+1; m <= len - 2; m++) {
				for (int n = m+1; n <= len -1; n++) {
					if (nums[i] + nums[j] + nums[m] + nums[n] > target) {
						break;
					}
					cout << nums[i]<< nums[j] << nums[m] << nums[n] << endl;
					if (nums[i] + nums[j] + nums[m] + nums[n] == target) {
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[m]);
						tmp.push_back(nums[n]);
						bool alreadyHad = false;
						for (int k = 0; k < res.size(); k++) {
							if (nums[i] == res[k][0] && nums[j] == res[k][1]
								&& nums[m] == res[k][2] && nums[n]==res[k][3]) {
								alreadyHad = true;
								break;
							}
						}
						if (!alreadyHad) {
							res.push_back(tmp);
						}
						while (n <= len - 1 && nums[i] == nums[n]) {
							i++;
							j++;
							m++;
							n++;
						}

					}
				}
			}
		}
	}
	for (size_t i = 0; i < res.size(); i++) {
		for (size_t j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << endl;
		}
		cout << endl;
	}
	return res;
}

void test_foursum(){
	//vector<int> input = { 3, -5, -3,-9, 1, 2, 4, 9 ,0 };
	vector<int> input = { 1, 0, -1, 0, -2, 2 };
	fourSum(input, 0);
}