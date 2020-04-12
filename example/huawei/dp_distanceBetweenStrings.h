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

	std::vector<std::vector<int>> DP(M+1, std::vector<int>(N+1, 0));
	//if (str1.at(0) == str2.at(0)) DP[0][0] = 0;
	//if (str1.at(0) != str2.at(0)) DP[0][0] = 1;
	for (int i = 0; i <= N; i++)
	{
		//int d1 = DP[0][i-1];
		//if (str1.at(0) != str2.at(i)) d1++;
		DP[0][i] = i;
	}

	for (int i = 0; i <= M; i++)
	{
		//DP[i][0] = i;
		//int d1 = DP[i - 1][0];
		//if (str1.at(i) != str2.at(0)) d1++;
		DP[i][0] = i;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++) {
			int d1 = DP[i][j - 1]+1;
			int d2 = DP[i - 1][j]+1;
			int d3 = DP[i - 1][j - 1];
			if (str1.at(i-1) != str2.at(j-1)) d3++;
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
	printf("1/%d\n", DP[M][N] + 1);
	return 0;
}

//void get_dis(const string &s1, const string &s2) {
//
//	int n = s1.size(), m = s2.size();
//	vector<vector<int>> dp(n, vector<int>(m));/*dp[x][y]Ϊ���ַ���s1��ǰx���ַ���ǰ1���ַ�Ϊa[0]��ǰ2���ַ�Ϊa[0]��a[1]��
//													  ת��Ϊ�ַ���s2��ǰy���ַ���������ٲ�������*/
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
