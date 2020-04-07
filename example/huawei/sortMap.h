#pragma once
#include<set>
#include<string>
#include<iostream>
using namespace std;

//typedef struct {
//	int value;
//	string name;
//}gradeMap;

struct pair_cmp
{
	bool operator()(const std::pair<int, string>& lhs, const std::pair<int, string>& rhs)const
	{
		return lhs.first<rhs.first;
	}
};

struct pair_cmp2
{
	bool operator()(const std::pair<int, string>& lhs, const std::pair<int, string>& rhs)const
	{
		return lhs.first>rhs.first;
	}
};
using topK_set = multiset<std::pair<int, string>, pair_cmp>;
using topK_setless = multiset<std::pair<int, string>, pair_cmp2>;

int test_sortMap() {
	int num = 0;
	int mode = 0;
	cin >> num;
	cin >> mode;
	topK_set tkset;
	topK_setless tksetless;
	while (num--) {
		pair_cmp pair;
		string name;
		int value;
		cin >> name;
		cin >> value;
		if (mode == 0) {
			tkset.insert(std::make_pair(value, name));
		}
		else {
			tksetless.insert(std::make_pair(value, name));
		}
	}

	for (auto itr:tkset)
	{
		printf("%s %d\n", itr.second.c_str(), itr.first);
	}
	for (auto itr : tksetless)
	{
		printf("%s %d\n", itr.second.c_str(), itr.first);
	}

	return 0;
}
