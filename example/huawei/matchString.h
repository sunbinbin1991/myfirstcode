#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<string> commandStrs = { "reset","reset board","board add","board delet","reboot backplane","backplane abort" };
std::vector<string> executeStrs = { "reset what","reset fault","where to add","no board at all","impossible","install first","unkown command" };
void matchingString(string &input) {
	if (input.find(' ') != string::npos) {
		printf("has space\n");
	}
	else {
		printf("no space\n");
		if (input.find_first_of('r')) {
		
		}

	}
	printf("%d \n", input.find(' '));

}

#include <sstream>
bool match(string str, string s) {
	return str.find(s) == 0;
}
int test_matchingstr() {
	string str;
	string cmd[6] = { "reset",       "reset board", "board add",     "board delet",      "reboot backplane", "backplane abort" };
	string res[7] = { "reset what",  "board fault", "where to add",  "no board at all",  "impossible",       "install first",    "unkown command" };
	while (getline(cin, str)) {
		string s1, s2, temp;
		stringstream ss(str);
		ss >> s1 >> s2;
		int resi = 6;
		if (s2.empty())
			resi = match(cmd[0], s1) ? 0 : 6;
		else {
			bool flag = false;
			for (int i = 1; i < 6; i++) {
				stringstream allcmd(cmd[i]);
				allcmd >> temp >> temp;
				if (match(cmd[i], s1) && match(temp, s2)) {
					if (!flag) {
						flag = true;
						resi = i;
					}
					else {
						resi = 6;
						break;
					}
				}
			}
		}
		cout << res[resi] << endl;
	}
	return 0;
}//大家的都好长，我来个短一点的吧。。

void test_matchstring() {
	string input;
	while (getline(cin,input))
	{
		matchingString(input);
		printf("%s\n", input.c_str());
	}
}