#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const string helper1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string helper2 = "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza1234567890";
void Encrypt(string str) {
	string res;
	for (int i = 0; i < str.size(); i++) {
		res += helper2[helper1.find(str[i])];
	}
	cout << res << endl;
}
void unEncrypt(string str) {
	string res;
	for (int i = 0; i < str.size(); i++) {
		res += helper1[helper2.find(str[i])];
	}
	cout << res << endl;
}
int test_endecry() {
	string str1, str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		Encrypt(str1);
		unEncrypt(str2);
	}
	return 0;
}