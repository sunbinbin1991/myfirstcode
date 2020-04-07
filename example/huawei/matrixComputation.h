#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>
using namespace std;
void calculateInStack(std::vector<std::vector<int>> &input,std::map<char, int>& char2IndexMap, stack<char>& chStack,int &sum) {
	std::vector<char> tmpVecor;

	while (!chStack.empty()&&chStack.top() != '(') {
		tmpVecor.push_back(chStack.top());
		chStack.pop();
	}
	
	//printf("%c\t", tmpVecor[tmpVecor.size() - 1]);
	int part = 1;
	for (int i = tmpVecor.size()-1; i >=0 ; i--)
	{
		if (char2IndexMap.find(tmpVecor[i]) != char2IndexMap.end()) {
			int index = char2IndexMap[tmpVecor[i]];
			if (i == tmpVecor.size() - 1) {
				part *= input[char2IndexMap[tmpVecor[i]]][0] * input[char2IndexMap[tmpVecor[i]]][1];
			}
			else {
				part *=  input[char2IndexMap[tmpVecor[i]]][1];
			}
			printf("%c\t", tmpVecor[i]);
			cout << input[char2IndexMap[tmpVecor[i]]][0]<<"*"<< input[char2IndexMap[tmpVecor[i]]][1] << endl;
		
		}
	}
	if (!tmpVecor.empty()) {
		cout << "input[char2IndexMap[tmpVecor[0]]][1] = " << input[char2IndexMap[tmpVecor[tmpVecor.size() - 1]]][1] << endl;
		cout << "input[char2IndexMap[tmpVecor[0]]][1] = " << input[char2IndexMap[tmpVecor[0]]][1] << endl;
		input[char2IndexMap[tmpVecor[tmpVecor.size() - 1]]][1] = input[char2IndexMap[tmpVecor[0]]][1];
		cout << "part = " << part << endl;
	}

	sum += part;
	if (!chStack.empty()&&chStack.top() == '(') {
		chStack.pop();
	}
	
	if (!chStack.empty()) {
		chStack.push(tmpVecor[tmpVecor.size() - 1]);
	}
}

int test_matrixComputation() {
	int num = 0;
	while (cin >> num) {
		if (num <= 0) return -1;

		std::vector<std::vector<int>> input(num, std::vector<int>(2, 0));
		int index = 0;
		while (num--) {
			cin >> input[index][0];
			cin >> input[index][1];
			index++;
		}

		string calOrder;
		cin >> calOrder;
		stack<char> calValue;
		std::map<char, int> char2Index;
		 index = 0;
		int sum = 0;
		for (int i = 0; i < calOrder.size(); i++)
		{
			char let = calOrder.at(i);
			if (let != '('&&let != ')') {
				char2Index[let] = index++;
			}
		
			if (let == ')') {
				//cal
				calculateInStack(input, char2Index, calValue,sum);
			}
			else {
				calValue.push(let);
			}
		}
		while (!calValue.empty()) {
			calculateInStack(input, char2Index, calValue, sum);
		}
		cout << "sum= " << sum << endl;
	}

	return 0;
}