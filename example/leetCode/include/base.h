#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include"typedef.h"
#include "BinaryTree.h"

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

	/*
	Offer-18: del listNode
	*/
	
	void DeleteNode(ListNode** pListNode, ListNode* pToBeDel);

	/*
	Offer-20
	*/

	bool isNumString(const char* str);

	/*
	Offer-21
	*/

	void RecorderOldEven(int * pdata,int length);

	/*
	Offer-29
	*/

	void PrintMatrixClockwisely(int **data, int col, int row);

	/*
	Offer-31
	*/

	bool isPopOrder(int *sPush, int * sPop, int nlength);


	/*
	Offer-32
	*/

	void printBinaryTreeFromTomToBottom(BinaryTreeNode* pTreeRoot);

	/*
	Offer-33
	*/

	void printBinaryTreeFromLeftToRight(BinaryTreeNode* pTreeRoot);


private:

};