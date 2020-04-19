#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

bool pair_less(const pair<char, int>& former, const pair<char, int>& latter){
	return former.second < latter.second ||
		former.second == latter.second&&
		former.first < latter.second;
}

int cmpfunc2(const void * a, const void * b)
{
	pair<char, int>* former = (pair<char, int>*)a;
	pair<char, int>* latter = (pair<char, int>*)b;
	return former->second > latter->second ||
		former->second == latter->second&&
		former->first > latter->second;
}

int test_charsum() {
	string input;
	while (getline(cin, input)) {
		char letters[255] = { 0 };
		int len = input.size();

		std::vector< std::pair<char, int>> chset_vector;
		for (int i = 0; i<len; i++) {
			char tmp = input[i];
			letters[tmp]++;
			//chset.first = tmp;
			//chset.second = letters[tmp];
			//chset_vector.push_back(chset);
		}

		for (int i = 0; i<255; i++) {
			std::pair<char, int> chset;
			chset.first = (char)i;
			chset.second = letters[i];
			//chset.insert(std::make_pair(value, name));
			if (letters[i]) {
				chset_vector.push_back(chset);
			}
			
		}
		qsort(chset_vector.data(), chset_vector.size(), sizeof(pair<char, int>), cmpfunc2);
		for (auto itr: chset_vector)
		{
			printf("%c %d\n", itr.first, itr.second);
		}
	}
	return 0;
}