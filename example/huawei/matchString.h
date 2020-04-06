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

void test_matchstring() {
	string input;
	while (getline(cin,input))
	{
		matchingString(input);
		printf("%s\n", input.c_str());
	}
}