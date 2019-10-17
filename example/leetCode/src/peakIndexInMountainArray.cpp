#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
using namespace std;

int compareTwo(int start, int end) {
	if (start > end) {
		return start;
	}
	return end;
}

int peakIndexInMountainArray(vector<int> moutain) {
	int temp = moutain[0];
	int s = 0;
	int devide = moutain.size()/2;
	int pow = moutain.size();
	int count = 1;
	while (pow/2!=1) {
		count += 1;
		pow = pow / 2;
	}
	while (pow--) {
		if (moutain[(pow + 1) / 2] > moutain[(pow + 1) / 2 - 1] && moutain[(pow + 1) / 2] < moutain[(pow + 1) / 2 + 1]) {
			return (pow + 1) / 2;
		}
		if (moutain[(pow + 1) / 2] > moutain[(pow + 1) / 2 - 1]) {
		temp = moutain[(pow + 1) / 2];
		}		
	}
	if (moutain[0] < moutain[devide]) {
		temp = moutain[devide];
	}
	if (temp < moutain[moutain.size()]) {
		temp = moutain[moutain.size()];
	}
	for (int i = 0; i < moutain.size(); i++) {
		if (temp < moutain[i]) {
			temp = moutain[i];
			s = i;
		}
	}
	return s;
}


int main_temp2() {
	vector<int> moutain;
	int res = peakIndexInMountainArray(moutain);
	system("pause");
	return 0;
}