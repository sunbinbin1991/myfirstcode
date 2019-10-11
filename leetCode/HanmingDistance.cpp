#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
#include <bitset>
using namespace std;

vector<unsigned char> intToBytes(int paramInt)
{
	vector<unsigned char> arrayOfByte(4);
	for (int i = 0; i < 4; i++)
		arrayOfByte[3 - i] = (paramInt >> (i * 8));
	return arrayOfByte;
}

int HangmingDis(int x, int y) {
	bitset<32> s = x;
	bitset<32> t = y;
	int count = 0;
	for (int i = 0; i < 32; i++) {
		cout << s[i] << endl;
		if (s[i]!=t[i]) {
			count += 1;
		}
	}
	return count;
}
int main_temp5() {
	vector <string> words;
	int res = HangmingDis(10,4);
	std::cout << res << endl;
	return -1;

}