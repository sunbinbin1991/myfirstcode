#pragma once
#include<stack>

using namespace std;
typedef multiset<int, less<int>> inputset;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() && nums2.empty()) return 0;

	int sum_len = nums1.size() + nums2.size();
	stack<int> first;
	stack<int> second;

	inputset allnums;
	for (size_t i = 0; i < nums1.size(); i++)
	{
		allnums.insert(nums1[i]);
	}
	for (size_t i = 0; i < nums2.size(); i++)
	{
		allnums.insert(nums2[i]);
	}

	if (sum_len % 2 == 0) {
		int mid = sum_len / 2;
		int count = 0;
		int a,b;
		for (auto itr : allnums) {
			if (count == mid) {
				b = itr;
				cout << "b = " << itr << endl;
				return (a + b) / 2.;
			}
			else if (count++ == (mid-1-1)) {
				a = itr;
				cout << "a = " << itr << endl;
			}
			else {
				continue;
			}
		}
	}
	else {
		int mid = sum_len / 2;
		int count = 0;
		for (auto itr : allnums) {
			if (count++ == mid) {
				return itr;
			}
		}
	}

	return 0;
}

void test_findMedianSortedArrays(){
	int str;
	while (cin >> str) {
		vector<int> nums1 = { 1,2 };
		vector<int> nums2 = { 3,5 };
		double res = findMedianSortedArrays(nums1, nums2);
		cout << "res = "<< res << endl;
	}
}