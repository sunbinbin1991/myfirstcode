#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
using std::string;
using namespace std;

class base {
public:
	//string related
	/*
	KMP�ַ���ƥ�䣻
	*/
	int stringPattern(string S, string T, int pos);
	/*
	https://leetcode-cn.com/problems/subsets/
	*/
	
	vector<vector<int>> subsets(vector<int>& nums);

	/*
	Offer-17: ��ӡ1-Nλ��
	*/

	void PrintToMaxOfNDigits(int n);


private:

};