#pragma once
#include"iostream"
#include "string"
using namespace std;

float fun(float guess, float x)
{
	if (abs(guess*guess*guess - x)<0.0000001) return guess;
	else
		return fun((x / guess / guess + 2 * guess) / 3, x);
}
void getCubeRoot(double num) {
	std::printf("%.1f",cbrt(num));
}

void test_getCubeRoot() {
	double num;
	cin >> num;
	getCubeRoot(num);
}