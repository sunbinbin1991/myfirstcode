#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int get_distance(const string &str1, const string &str2) {
	int M = str1.size();
	int N = str2.size();
	if (M <= 0) return N;
	if (N <= 0) return M;

	std::vector<std::vector<int>> DP(M, std::vector<int>(N, 0));
	if (str1.at(0) == str2.at(0)) DP[0][0] = 0;
	if (str1.at(0) != str2.at(0)) DP[0][0] = 1;
	for (int i = 1; i < N; i++)
	{
		 DP[0][i] = DP[0][0] + i;
	}

	for (int i = 1; i < M; i++)
	{
		DP[i][0] = DP[0][0] + i;
	}

	for (int i = 1; i <= M-1; i++)
	{
		for (int j = 1; j <= N-1; j++) {
			int d1 = DP[i][j - 1]+1;
			int d2 = DP[i - 1][j]+1;
			int d3 = DP[i - 1][j - 1];
			//if (str1.at(i) == str2.at(j)) DP[i][j] = DP[i - 1][j - 1];
			if (str1.at(i) != str2.at(j)) d3++;
				DP[i][j] = std::min(std::min(d1, d2), d3);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			printf("%d ",DP[i][j]);
		}
		printf("\n");
	}
	printf("1/%d\n", DP[M-1][N-1] + 1);
	return 0;
}

//void get_dis(const string &s1, const string &s2) {
//
//	int n = s1.size(), m = s2.size();
//	vector<vector<int>> dp(n, vector<int>(m));/*dp[x][y]为将字符串s1的前x个字符（前1个字符为a[0]，前2个字符为a[0]和a[1]）
//													  转换为字符串s2的前y个字符所需的最少操作次数*/
//	for (int i = 0; i < n; i++)
//		dp[i][0] = i;
//	for (int j = 0; j < m; j++)
//		dp[0][j] = j;
//	for (int i = 1; i < n; i++)
//		for (int j = 1; j < m; j++)
//		{
//			int d1 = dp[i - 1][j] + 1, d2 = dp[i][j - 1] + 1, d3 = dp[i - 1][j - 1];
//			if (s1[i] != s2[j]) d3++;
//			dp[i][j] = min(min(d1, d2), d3);
//		}
//	cout << 1 << '/' << dp[n-1][m-1] + 1 << endl;
//}

int test_dp_distanceOfStrings() {
	string inputa,inputb;
	//while (cin>>inputa>>inputb)
	{
		inputb = "ciklumgbckzhspbknvkwjihvcwaldxaqjgjvmgmbddbfbglkmbbhswdozsdfqzfolgfpfscynqocwokzhfzgdlwnytdzqpndeztkqilkuiwlwuvrjbeqpwbiewepuz";
		inputa = "ie";
		get_distance(inputa, inputb);
	}

	return 0;
}
