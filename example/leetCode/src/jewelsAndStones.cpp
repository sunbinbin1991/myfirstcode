#include<stdio.h>
#include<iostream>
using namespace std;
int numJewelsInStones(string J, string S) {
	bool *byteflag = new bool[128];
	int count = 0;
	for (int i = 0; i < J.length(); i++) {
		byteflag[(int)(J[i])] = true;
	}
	for (int j = 0; j < S.length(); j++) {
		if (byteflag[(int)(S.at(j))] != true) {
			count++;
		}
	}

	delete[] byteflag;
	return S.length() - count;
}

int main_t() {
	string J = "bcddsfsd ";
	string S = "cbsdfabca";
	int res = numJewelsInStones( J, S);
	cout << res << endl;
	getchar();
	return -1;

}