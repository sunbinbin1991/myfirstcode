#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
int get_distance_num( int M,int N) {
	if (M <= 0||N<=0) return 0;

	std::vector<std::vector<int>> DP(M + 1, std::vector<int>(N + 1, 0));
	for (int i = 0; i <= N; i++)
	{
		DP[0][i] = 1;
	}

	for (int i = 0; i <= M; i++)
	{
		DP[i][0] = 1;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++) {
			int d1 = DP[i][j - 1];
			int d2 = DP[i - 1][j];
			DP[i][j] = d1+d2;
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			printf("%d ", DP[i][j]);
		}
		printf("\n");
	}
	printf(" %d\n", DP[M][N]);
	return 0;
}

int test_dp_distanceOfStrings2() {
	string inputa, inputb;
	int M,N;
	while (cin>> M>>N)
	{
		get_distance_num(M,N);
	}

	return 0;
}