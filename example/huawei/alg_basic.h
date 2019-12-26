#pragma once
#include"iostream"
#include"string.h"
#include <string>
#include <set>
using namespace std;
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
int bubblesort() {
	int len;
	cin >> len;
	int num;
	std::set<int> pts;
	while (cin >> num) {
		pts.emplace(num);
	}
	int arry_size = pts.size();
	int* arry = new int[arry_size];
	int i = 0;
	for (auto it = pts.begin(); it != pts.end(); it++) {
		arry[i++] = *it;
	}
	for (int i = 0; i < arry_size; i++)
	{
		for (int j = i; j < arry_size; j++)
		{
			if (arry[i] > arry[j]) {
				int temp = arry[j];
				arry[j] = arry[i];
				arry[i] = temp;
			}
		}
	}

	for (int i = 0; i < arry_size; i++)
	{
		printf("%d", arry[i]);
	}
	delete[] arry;
	return 0;
}