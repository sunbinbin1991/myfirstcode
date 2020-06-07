#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define LENOFONEZU 6
enum ZDirection{
	down = 0,
	upright = 1,
};

void zconvert(string& input, int rows)
{
	int lens = input.size();
	int znums = lens / LENOFONEZU;
	int zremain = lens % LENOFONEZU;
	int numsOfMidLetter = znums * (rows - 1) + zremain;
	cout << " len = " << lens << endl;
	cout << " znums = " << znums << endl;
	cout << " zremain = " << zremain << endl;
	cout << " numsOfMidLetter = " << numsOfMidLetter << endl;

	vector<vector<char>> matrix(rows, vector<char>(numsOfMidLetter, 0));
	int direction = ZDirection::down;
	int i = 0; 
	int j = 0;
	for (int l = 0; l < lens; l++) {
		char tmpchar = input[l];
		//cout << i <<","<< j << ","<<tmpchar<<endl;;
		if (direction == ZDirection::down && i == rows) {
			matrix[rows - 2][j + 1] = tmpchar;
			direction = ZDirection::upright;
			i-=3;
			j+=2;
			continue;
		} else if (direction == ZDirection::upright && i == -1){
			matrix[1][j - 1] = tmpchar;
			direction = ZDirection::down;
			i += 3;
			j--;
			continue;
		} else { 	
			matrix[i][j] = tmpchar;
		}
		if (direction == ZDirection::upright) {
			i--;
			j++;
		} else {
			i++;
			direction = ZDirection::down;
		}
	}
	string res = "";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < numsOfMidLetter; j++) {
			if (matrix[i][j]) {
				res += matrix[i][j];
			}
		}
	}
	cout << res<<endl;
}

void test_zconvert() 
{
	string input;
	int rows;
	while (cin >> input >> rows) {
		input = "LEETCODEISHIRING";
		rows = 3;
		zconvert(input, rows);
	}
}