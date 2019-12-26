#pragma once
#include "iostream"
#include <string>
using namespace std;
int test_len_of_string() {
	string all_strings;
	int lenght = 0;
	while (cin>>all_strings)
	{
		lenght = strlen(all_strings.c_str());
		printf("%d \n", lenght);
	}
	return lenght;
}