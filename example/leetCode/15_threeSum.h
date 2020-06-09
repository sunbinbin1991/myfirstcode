#pragma once
#include <vector>
#include <iostream>
using namespace std;
//1: 需要先做非空判定
//2: 双指针

int cp_less(const void *a,const void *b) {
	int s = *(int*)a;
	int t = *(int*)b;
	return *(int *)a - *(int *)b;
}

vector<vector<int>> threeSum_let(vector<int>& input)
{
	vector<vector<int>> res;
	if (input.empty()) return res;
	sort(input.begin(), input.end());
	int *start = input.data();
	int *end = input.data() + input.size() - 1;
	int target = 0;
	while (end - start >= 2) {
		int *left = start + 1;
		int *right = end;
		while (right - left >= 1) {
			if (*start + *left + *right == target) {
				vector<int> tmp;
				tmp.push_back(*start);
				tmp.push_back(*left);
				tmp.push_back(*right);
				bool alreadyHad = false;
				for (int i = 0; i < res.size(); i++) {
					if (tmp[0] == res[i][0] && tmp[1] == res[i][1] && tmp[2] == res[i][2]) {
						alreadyHad = true;
						break;
					}
				}
				if (!alreadyHad) {
					res.push_back(tmp);
				}
				right--;
			} else if (*start + *left + *right > target) {
				right--;
			} else {
				left++;
			}
			while (*left == *right&& right - left>1) {
				left++;
			}
		}
		start++;
	}
	return res;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	if (nums.empty()) {
		return res;
	}
	//qsort(nums.data(), nums.size(), sizeof(int),cp_less);
	sort(nums.begin(), nums.end());
	int *begin = nums.data();
	int *end = nums.data() + nums.size()-1;

	cout << *begin << "\t" << *(int*)end << endl;
	int *mid = begin + 1;

	while (begin < end) {

		while (mid < end) {
			vector<int> tmp;
			if (*(int*)begin + *(int*)mid + *(int*)end == 0) {
				tmp.push_back(*begin);
				tmp.push_back(*mid);
				tmp.push_back(*end);
				res.push_back(tmp);
			}
			mid++;
		}
		//if (!tmp.empty()) {
		//	
		//}
		if (*(int*)begin + *(int*)mid + *(int*)end > 0) {
			end --;
		} else {
			begin++;
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

void test_threeSum() {
	vector<int> input = { 3, -5, -3,- 9, 1, 2, 4, 9 ,0};
	threeSum(input);
}