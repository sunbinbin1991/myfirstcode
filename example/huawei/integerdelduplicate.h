#pragma once
#include "iostream"
#include <string>
#include "string.h"

using namespace std;

//url:https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

void integerdelduplicate() {

}

void test_integerdelduplicate() {
	string numstr;
	cin >> numstr;
	int array[10] = { 0 };
	int len = strlen(numstr.c_str());
	for (int i = len-1; i >=0 ; i--)
	{
		if (array[numstr.at(i) - '0'] <= 0) {
			array[numstr.at(i) - '0'] += 1;
			cout << numstr.at(i);
		}
		else {
		
		}
		
	}
}