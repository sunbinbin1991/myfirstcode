#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;
void getFirstCharOnlyOnceInString(std::string & str) {
	std::map<char, int> charMap;
	for (size_t i = 0; i < str.length(); i++)
	{
		char tmpchar = str.at(i);
		if (charMap.find(tmpchar) != charMap.end()) {
			charMap[str.at(i)] += 1;
			cout << str.at(i) << endl;
			cout << charMap[str.at(i)] << endl;

		}
		else {
			charMap[str.at(i)] = 1;
		}
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		char tmpchar = str.at(i);
		if (charMap.find(tmpchar) != charMap.end()) {
			if (charMap[str.at(i)]==1)
			{
				printf("%d\n", str.at(i));
				cout << str.at(i) << endl;
				break;
			}
		}
	}
}
int test_getFirstCharOnlyOnceInString() {
	string inpustr;
	while (cin >> inpustr) {
		getFirstCharOnlyOnceInString(inpustr);
	}
	return 0;
}