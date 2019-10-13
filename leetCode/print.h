#pragma once
#include<iostream>
using namespace std;
void printMatrix(int **data, int col, int row) {
	printf("Input matrix:\n");
	for (int i = 0; i < col; i++)
	{
		printf("\t");
		for (int j = 0; j < row; j++)
		{
			printf("%d\t", data[i][j]);
		}
		printf("\n");
	}
}