#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int threeSumClosest(vector<int>& input,int target)
{
	if (input.empty()) return 0;
	sort(input.begin(), input.end());
	int *start = input.data();
	int *end = input.data() + input.size() - 1;
	int min_result = INT_MAX;
	int res = 0;
	while (end - start >= 2) {
		int *left = start + 1;
		int *right = end;
		bool isbreak = false;
		while (right - left >= 1) {
			int tmpres = *start + *left + *right;
			std::cout << *start << " " << *left << " " << *right << endl;
			if (tmpres == target) {
				min_result = tmpres;
				isbreak = true;
				break;
			} else if (tmpres > target) {
				right--;
			} else {
				left++;
			}
			int distanceOfTarget = abs(tmpres - target);
			cout << "distanceOfTarget " << distanceOfTarget << "\n";
			cout << "min_result " << min_result << "\n";
			cout << "tmpres " << tmpres << "\n";
			if (min_result > distanceOfTarget) {
				res = tmpres;
			}
			min_result = min_result > distanceOfTarget ? distanceOfTarget : min_result;
			while (*left == *right && right - left > 1) {
				left++;
			}
		}
		start++;
	}
	cout << "res" << min_result << "\n";
	return min_result;
}

void test_threeSumClosest()
{
	//vector<int> input = { 3, -5, -3,-9, 1, 2, 4, 9 ,0 };
	vector<int> input = { -1,2,1,-4 };
	threeSumClosest(input,1 );
}