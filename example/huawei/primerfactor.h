#pragma once
#include "iostream"
using namespace std;

void getprimefactor(int num) {
	if (num <= 0) return;
	int i = 2;
	while (num >= 2) {
		if (num % i == 0) {
			cout << i << endl;
			while (num%i == 0) {
				num /= i;
			}
		}
		i++;
	}
}

void test_primerfactor() {
	int num;
	cin >> num;
	getprimefactor(num);
}