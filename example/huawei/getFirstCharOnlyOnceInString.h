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

int test_getFirstCharOnlyOnceInString2()
{
	using namespace std;
	string str;
	while (getline(cin, str))
	{
		unsigned int i;
		for (i = 0; i<str.size(); i++)
		{
			//rfind: 寻找等于给定字符序列的最后子串,
			//if position is same then return
			if (str.find(str[i]) == str.rfind(str[i]))
			{
				cout << str[i] << endl;
				break;
			}
		}
		if (i == str.size())
			cout << '.';
	}
	return 0;
}

int test_getFirstCharOnlyOnceInString() {
	string inpustr;
	while (cin >> inpustr) {
		getFirstCharOnlyOnceInString(inpustr);
	}
	return 0;
}