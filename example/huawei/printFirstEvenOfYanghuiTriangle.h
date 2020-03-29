#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <dp_minCostPathWithBlock.h>
using namespace std;
//typedef long long int ll;
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
void printEvenOfTriangle(int input) {
	std::vector<std::vector<ll>> matrix(input, vector<ll>(2*input, 0));
	F(i, 0, input-1) matrix[i][0] = 1;
	F(i, 0, input - 1) matrix[i][2*i] = 1;
	//F(i, 0, input - 1) {
	//	F(j, 0, 2*(input - 1)) {
	//		printf("%d ", matrix[i][j]);
	//	}
	//	printf("\n");
	//}

	//printf("\n");

	F(i, 1, input-1) {
		F(j, 1, 2 * i-1) {
			if (j == 1 && i==1) 
				matrix[i][j] = (matrix[i - 1][j-1]+MOD) % MOD;
			else if(j == 1) // top and left
				matrix[i][j] = ( matrix[i - 1][j] + matrix[i-1][j -1] + MOD) % MOD;
			else if(j== (2 * i - 1))//top and right
				matrix[i][j] = (matrix[i - 1][j-1] + matrix[i - 1][j-2]+ MOD) % MOD;
			else
			 matrix[i][j] = (matrix[i - 1][j - 1] + matrix[i - 1][j] + matrix[i-1][j -2]+MOD) % MOD;;
			
			//printf("%d ",  matrix[i][j]);
		}
		//printf("\n");
	}
	F(j, 1, input-1) {
		if (!(matrix[input - 1][j] & 1)) {
			//printf("%d \n", matrix[input-1][j]);
			printf("%d\n", j+1);
			continue;
		}
	}
}

int test_print_triangle() {
	int input;
	while (cin >> input) {
		printEvenOfTriangle(input);
	}
	return 0;
}
