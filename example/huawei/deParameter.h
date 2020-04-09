#pragma once
//https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&tqId=21297&tPage=4&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void deparam(const string & input) {
	int len = strlen(input.c_str());
	stringstream  sb;
	string tem = "";
	std::vector<string> vstrings;
	bool hasfront = false;
	for (int i = 0; i < len; i++)
	{
		char tmpchar = input.at(i);
		if (tmpchar != ' ') {
			tem+=tmpchar;
		}
		if (!hasfront&&tmpchar == ' ') {
			vstrings.push_back(tem);
			tem = "";
		}
		if (tmpchar == '"') {
			hasfront = true;
		}

		if (tmpchar == '"') {
			vstrings.push_back(tem);
			tem = "";
			hasfront = true;
		}
	}
	printf("%d\n", vstrings.size());
	for (auto it : vstrings) {
		printf("%s\n", it.c_str());
	}

}

int test_deparam() {
	string input;
	while (getline(cin,input)) {
		printf("%s\n", input.c_str());
		deparam(input);
	}

	return 0;
}