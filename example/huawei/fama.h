#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	while (cin >> N)
	{
		vector<int> m(N, 0), x(N, 0), w = { 0 };
		for (auto &i : m)
			cin >> i;
		for (auto &i : x)
			cin >> i;
		for (int j = 1; j <= x[0]; j++)//先push进第一种砝码的所有可能重量
			w.push_back(j*m[0]);
		int temp = w.size();
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j <= x[i]; j++)
				for (int k = 0; k < temp; k++)
					if (find(w.begin(), w.end(), j*m[i] + w[k]) == w.end())//避免重量重复
						w.push_back(j*m[i] + w[k]);
			temp = w.size();
		}

		cout << temp << endl;
	}
	return 0;
}