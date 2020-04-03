#pragma once
//https://www.nowcoder.com/practice/bfd8234bb5e84be0b493656e390bdebf?tpId=37&tqId=21284&tPage=3&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
int getNumsDevides(int num, int n) {
	if (num <= 0 || n <= 0) return -1;
	if (num == 1 || n == 1) return 1;
	if (num <= n) {
		getNumsDevides(num, num);
	}
	else {
		getNumsDevides(num,  n-1)+ getNumsDevides(num-n, n);
	}
}

int test_getNumsDevides() {
	int mApple,nPlasic;
	while (cin>> mApple >> nPlasic){
		int res = getNumsDevides(mApple, nPlasic);
		cout << res << endl;
	}
}