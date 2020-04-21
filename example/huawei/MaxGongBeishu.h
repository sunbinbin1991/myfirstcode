#pragma once
#include<iostream>
using namespace std;

int gcd(int a, int b) {//最大公约数
	while (a%b) {
		int tmp = a;
		a = b;
		b = tmp % b;
		//printf("%d\n", b);
	}
	
	return b;
}
int test_gongbeishu() {
	int a, b;

	while (cin >> a >> b) {
		int max_gongyue = gcd(a, b);
		printf("%d\n", a*b / max_gongyue);
	}
	return 0;
}