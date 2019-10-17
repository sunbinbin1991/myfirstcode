#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
using namespace std;

bool judgeCircle(string  s) {
	int countU = 0;
	int countD = 0;
	int countR = 0;
	int countL = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'U') {
			countU++;
		}
		if (s.at(i) == 'D') {
			countD++;
		}
		if (s.at(i) == 'R') {
			countR++;
		}
		if (s.at(i) == 'L') {
			countL++;
		}
	}
	if (countD == countU&&countR == countL) {
		return true;
	}
	return false;
}


int main_6() {
	string s = "LL";
	bool res = judgeCircle(s);

	system("pause");
	return -1;
}