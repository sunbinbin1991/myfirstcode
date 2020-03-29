#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//int N = 1000000000;
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
void printEvenOfTriangle(int input) {
	std::vector<std::vector<int>> matrix(input, vector<int>(2*input, 0));
	F(i, 0, input-1) matrix[i][0] = 1;
	F(i, 0, input - 1) matrix[i][2*i] = 1;
	F(i, 0, input - 1) {
		F(j, 0, 2*(input - 1)) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	F(i, 1, input-1) {
		F(j, 1, 2 * i-1) {
			if (j == 1 && i==1) 
				matrix[i][j] = matrix[i - 1][j-1];
			else if(j == 1) // top and left
				matrix[i][j] =  matrix[i - 1][j] + matrix[i-1][j -1];
			else if(j== (2 * i - 1))//top and right
				matrix[i][j] = matrix[i - 1][j-1] + matrix[i - 1][j-2];
			else
			 matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i-1][j -2];
			
			printf("%d ",  matrix[i][j]);
		}
		printf("\n");
	}
}

int test_print_triangle() {
	int input;
	while (cin >> input) {
		printEvenOfTriangle(input);
	}
	return 0;
}
