#pragma once
# include <stdio.h>
# include <string.h>
#include<iostream>
#include<stack>

using namespace std;
int ip2num(const std::string& input) {
	return 0;
}

int num2ip(const string& input) {
	return 0;
}

stack<int> num2binary(int num) {
	stack<int> bin;
	stack<int> bin2;
	while (num!=0) {
		bin.push(num % 2);
		num =num/ 2;
	}
	int len = bin.size();
	return bin;
}

int bin2num(stack<int> bin) {
	int sum = 0;
	int len = bin.size();
	for (int i = 1; i <= len; i++) {
		if (bin.top() & 1) {
			sum += pow(2, len-i);
		}
		bin.pop();
	}
	return sum;
}

void test_ipnumchange() {
	
	int input_num[4];
	scanf("%d", &input_num[0]);
	stack<int> bin = num2binary(input_num[0]);
	bin2num(bin);
}

int test_ipnumchange_better()
{
	unsigned int a, b, c, d;
	char ch;
	while (cin >> a >> ch >> b >> ch >> c >> ch >> d)
	{
		cout << ((a << 24) | (b << 16) | (c << 8) | d) << endl;
		cin >> a;
		cout << ((a & 0xff000000) >> 24) << "." << ((a & 0x00ff0000) >> 16) << "." << ((a & 0x0000ff00) >> 8) << "." << (a & 0x000000ff) << endl;
	}
	return 0;

}
