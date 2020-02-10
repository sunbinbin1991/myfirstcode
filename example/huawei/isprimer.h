#pragma once
#include <iostream>
#include <cmath>
using namespace std;

bool isprimer(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			cout << n << " isn't a prime" << endl;
			return true;
		}
	}
	return false;
}
