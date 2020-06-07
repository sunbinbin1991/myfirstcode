#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define LENOFONEZU 6
enum ZDirection{
	down = 0,
	upright = 1,
};

class Solution_zconvert {
public:
	string convert(string s, int numRows)
	{

		if (numRows == 1) return s;
		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) ret += row;
		return ret;
	}
};

void zconvert(string& input, int rows)
{
	if (input.empty()) {
		return ;
	}
	if (rows == 1) {
		return;
	}
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