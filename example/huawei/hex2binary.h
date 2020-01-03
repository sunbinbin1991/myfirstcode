#pragma once
#include"iostream"
#include"string"

using namespace std;

std::string int2binarystring(int num) {
	string inputstr = "";	
	for (int i = 4; i>0; i--)
	{
		inputstr += std::to_string((num >> i) & 1);
	}
	return inputstr;
}

void letter2binary(const char& input,std::string& dst) {
	if (input>='A'&&input<='E') {
		int num = 10;
		num += (input - 'A');
		dst = int2binarystring(num);
	}
	if (input >= '0'&&input <= '9') {
		int num = (input - '0');
		dst = int2binarystring(num);
	}
}

void letter2num(const char& input, int& num) {
	if (input >= 'A'&&input <= 'E') {
		num = 10;
		num += (input - 'A');
	}
	if (input >= '0'&&input <= '9') {
		num = (input - '0');
	}
}

void hex2binary(const std::string& inputstring){
	if (strlen(inputstring.c_str()) <= 2) {
		return;
	}
	string prefix(inputstring.begin(), inputstring.begin() + 2);
	if (prefix.compare("0x")) {
		printf("prefix.compare()= %d", prefix.compare("0x"));
		return;
	}

	int len = strlen(inputstring.c_str());
	std::string outstring = "";
	for (size_t i = 2; i < len; i++)
	{
		string tempstr="";
		letter2binary(inputstring.at(i), tempstr);
		printf("tempstr = %s\n", tempstr.c_str());
		outstring += tempstr;
	}
	printf("out = %s\n", outstring.c_str());
}

void hex2decimal(const std::string& inputstring) {
	if (strlen(inputstring.c_str()) <= 2) {
		return;
	}
	string prefix(inputstring.begin(), inputstring.begin() + 2);
	if (prefix.compare("0x")) {
		printf("prefix.compare()= %d", prefix.compare("0x"));
		return;
	}

	int len = strlen(inputstring.c_str());
	std::string outstring = "";
	int sum = 0;
	for (size_t i = 2; i < len; i++)
	{
		int num;
		letter2num(inputstring.at(i), num);
		sum += (std::pow(16, len - i-1)*num);
	}
	outstring += std::to_string(sum);
	printf("out = %s\n", outstring.c_str());
}

int hex2decimal_best() {
	string str;

	while (getline(cin, str)) {
		if (str.length() <= 0) break;

		long num = 0; int index = 16;
		for (int i = 2; i < str.length(); ++i) {
			if (str[i] >= '0' && str[i] <= '9')
				num = num * 16 + (str[i] - '0');
			else
				num = num * 16 + (str[i] - 'A' + 10);
		}
		cout << num << endl;
	}

	return 0;
}

void test_hex2binary() {
	string inputstr;
	cin >> inputstr;
	//hex2binary(inputstr);
	hex2decimal(inputstr);
}