#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int test_fama()
{
	int N;
	while (cin >> N)
	{
		vector<int> weights(N, 0), nums(N, 0);
		set<int> total;
		total.insert(0);
		for (auto &i : weights)
			cin >> i;
		for (auto &i : nums)
			cin >> i;
		for (int j = 1; j <= nums[0]; j++)//先push进第一种砝码的所有可能重量
			total.insert(j*weights[0]);
		printf("totol size = %d\n", total.size());
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j <= nums[i]; j++)
			{
				auto itr = total.begin();
				set<int> tmpset = total;
				for (auto tmp : tmpset) {
					total.insert(weights[i] + tmp);
					printf(" insert = %d\n", weights[i] + tmp);
				}
				/*if (total.find(weights[i] + *itr) != total.end()) {
					total.insert(weights[i] + *itr);
				}*/
				/*for (auto it : total) {
					total.insert(weights[i] + it);
					printf(" insert = %d\n", weights[i] + it);
				}*/

				//auto itr = total.begin();
				//while (itr != total.end()) {
				//	//printf(" weight = %d\n", weights[i] * j + *itr);
				//	//total.insert(weights[i] * j + (int)(*itr));
				//	printf(" itr = %d\n", *itr);
				//	itr++;

				//}
			}
		}

		cout << total.size() << endl;
	}
	return 0;
}