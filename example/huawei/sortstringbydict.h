#pragma once
#include "iostream"
#include "string"
#include "string.h"
#include <set>
using namespace std;
void sort_string_by_dict() {
	int num;
	cin >> num;
	multiset<string> stringset;
	while (num--) {
		string inputstring;
		cin >> inputstring;
		stringset.insert(inputstring);
	}

	for (auto itr = stringset.begin(); itr != stringset.end(); itr++)
	{
		std::cout << *itr << endl;
	}
}