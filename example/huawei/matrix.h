#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int test_matrix() {
	int x = 0;
	int y = 0;
	int z = 0;
	while (cin >> x >> y >> z) {
		std::vector<std::vector<int>> matrix1(x, std::vector<int>(y, 0));
		std::vector<std::vector<int>> matrix2(y, std::vector<int>(z, 0));
		std::vector<std::vector<int>> target(x, std::vector<int>(z, 0));
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				 cin >> matrix1[i][j];
			}
		}
		printf("\n ");
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < z; j++)
			{
				cin >> matrix2[i][j];
				printf("%d", matrix2[i][j]);
			}
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < z; j++)
			{
				int sum = 0;
				for (int k = 0; k < y; k++)
				{
					sum += matrix1[i][k] * matrix2[k][j];
				}
				target[i][j] = sum;
				printf("%d ", sum);
			}
			cout << endl;
		}
	}
	return 0;

}
