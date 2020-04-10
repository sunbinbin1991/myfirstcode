#pragma once
//https://www.nowcoder.com/practice/dbace3a5b3c4480e86ee3277f3fe1e85?tpId=37&tqId=21299&tPage=4&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
#include <iostream>
#include <string>
using namespace std;
int test_GetSequeOddNum() {
	int num = 0;
	while (cin >> num) {
		int cube_num = num*num*num;
		int first = (cube_num - ((num - 1)*num))/ num;
		if (first & 1==0) {
			continue;
		}
		for (int i = 0; i < num; i++)
		{
			if(num-1 == i)
			{
				cout << first + i * 2;
			} else {
				cout << first + i * 2 << "+";
			}			
		}
		cout << endl;
	}
	return 0;
}