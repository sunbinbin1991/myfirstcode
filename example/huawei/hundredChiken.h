#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test_chiken() {
//
	int x = 0;
	int y = 0;
	int z = 0;
	for (int i = 75; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			int num = 100 - i - j;
			if (4 * i - 3 * j == 300 && num>=0) {
				
				printf("%d %d %d\n",  j, num, i);
			}
		}
	}
}