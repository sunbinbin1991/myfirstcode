#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
void test_votesum() {
	int canditate_num;
	std::map<string, int> total;
	while (cin>>canditate_num) {
		while (canditate_num--) {
			std::pair<string, int> canditate_name;
			cin >> canditate_name.first;
			canditate_name.second = 0;
			total.insert(canditate_name);
		}
		int voter_num;
		cin >> voter_num;
		int invalid = 0;
		while (voter_num--) {
			string parter;
			cin >> parter;
			if (total.find(parter) != total.end()) {
				total[parter]++;
			}
			else {
				invalid++;
			}
		}
		for (auto itr:total)
		{
			printf("%s : %d\n", itr.first.c_str(), itr.second);
		}
		printf("Invalid: %d\n", invalid);
	}
}