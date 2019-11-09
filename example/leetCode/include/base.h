#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include <functional>
#include"typedef.h"
#include "BinaryTree.h"

using std::string;
using namespace std;

typedef multiset<int, less<int> > inSet;
typedef multiset<int, less<int> >::iterator inSetIterator;
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
	Offer-20���ַ����Ƿ���һ������
	*/

	bool isNumString(const char* str);

	/*
	Offer-21����ԭʼ���ݽ���ż������
	*/

	void RecorderOldEven(int * pdata,int length);

	/*
	Offer-29��˳ʱ���ӡ����
	*/

	void PrintMatrixClockwisely(int **data, int col, int row);

	/*
	Offer-31�����������Ƿ�������һ��������˳��
	*/

	bool isPopOrder(int *sPush, int * sPop, int nlength);


	/*
	Offer-32���Զ����µĴ�ӡ������
	*/

	void printBinaryTreeFromTomToBottom(BinaryTreeNode* pTreeRoot);

	/*
	Offer-32-2��
	*/

	void printBinaryTreeFromLeftToRight(BinaryTreeNode* pTreeRoot);

	/*
	Offer-32-3������Z��������ӡ����
	*/

	void base::prinBinaryTreeZway(BinaryTreeNode* pTreeRoot);

	/*
	Offer-33���ж������Ƿ�Ϊ�������
	*/

	bool base::VerifySeqOfBST(int arry[],int len);

	/*	
	Offer-34���ҵ���������·���������ֵ
	*/

	void base::findPath(BinaryTreeNode *pRoot, int expectSum);

	/*
	Offer-35��������������
	*/
	void cloneComplexListNode(ComplexListNode* pHead);

	/*
	Offer-38�������ַ������е�����
	*/
	void permutation(char* pStr);

	/*
	Offer-39���ҵ������г���һ�������
	*/
	int halfInArray(int *array, int length);

	/*
	Offer-40����ȡtopk���ֵ
	*/
	void getTopKGreater(const vector<int>data, inSet& inset, int topK);

	/*
	Offer-42:��������������ֵ���
	*/
	int getConsequentMax(int* array, int length);

	/*
	Offer-43����ø���Nǰ����1�Ĵ���
	*/
	int getNumsofOneBeforeN(int n);

private:

};