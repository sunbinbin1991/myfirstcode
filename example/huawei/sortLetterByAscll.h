#pragma once
//https://www.nowcoder.com/practice/2de4127fda5e46858aa85d254af43941?tpId=37&tqId=21257&tPage=2&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 指针的初始化是无意义地址,vector是零
void sort_letter(const string& input) {
	vector<int> letter(52);
	vector<int> num(10);
	for (int i = 0; i < strlen(input.c_str()); i++) {
		char let = input[i];
		if (let >= '0'&&let <= '9') {
			num[let - '0'] += 1;
		}
		if (let >= 'a'&&let <= 'z') {
			letter[26+let - 'a'] += 1;
		}
		if (let >= 'A'&&let <= 'Z') {
			letter[let - 'A'] += 1;
		}
	}
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < num[i]; j++)
		{
			std::cout <<i;
		}
	}

	for (size_t i = 0; i < letter.size(); i++)
	{
		if (i < 26) {
			for (size_t j = 0; j < letter[i]; j++)
			{
				char temp = 'A' + i;
				std::cout << temp;
			}
		}
		else {
			for (size_t j = 0; j < letter[i]; j++)
			{
				char temp = 'a' + i-26;
				std::cout << temp;
			}
		}
	}
}

int test_sort(string data) {
	sort(data.begin(), data.end());
	cout << "\n";
	cout << data << endl;
	return 0;
}

void test_sort_letter_by_Ascll() {
	string input= "h8NuC1jSbhqy9a5T9eJ3Oo3jau8s9BtNGAo5r11FIaz0XpGnZk5Igg7f073RWh1n2LU5D798H30oP1L6dn19wfiNeTa4RmbJ19uLFJ1Swpi5VCVk4VvHYF8F8VLB222f81SWLM968jJcteAUNUAy5w28DL237C5Xl4LktW5Li3O3t65uK6eA94E5bPVC3Rix2O1qkqP0eq3mFG63x4h8Bc5fkDkqt0NXwi03M1ngqa5tsUqCuj2ZQ07nQbfHDtu4E46B3p7uE0P69s6b626tR4Be0d6UO5ohBSV1012ZTs89i57RDI7E1a8Tp7Lj88kP1R9ec58aN9E8E2jN15g2vyOR56sBFHP53wSAS6EDFLtbd7Z158148ai8UIECKvlkFiSwYwW43AijfeRh63";
	//cin >> input;
	sort_letter(input);
	test_sort(input);
}