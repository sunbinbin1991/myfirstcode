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
	KMP字符串匹配；
	*/
	int stringPattern(string S, string T, int pos);
	/*
	https://leetcode-cn.com/problems/subsets/
	*/
	
	vector<vector<int>> subsets(vector<int>& nums);

	/*
	Offer-17: 打印1-N位数
	*/

	void PrintToMaxOfNDigits(int n);

	/*
	Offer-18: del listNode
	*/
	
	void DeleteNode(ListNode** pListNode, ListNode* pToBeDel);

	/*
	Offer-20：字符串是否是一个数字
	*/

	bool isNumString(const char* str);

	/*
	Offer-21：将原始数据进行偶奇区分
	*/

	void RecorderOldEven(int * pdata,int length);

	/*
	Offer-29：顺时针打印矩阵
	*/

	void PrintMatrixClockwisely(int **data, int col, int row);

	/*
	Offer-31：给定序列是否能满足一定的生成顺序
	*/

	bool isPopOrder(int *sPush, int * sPop, int nlength);


	/*
	Offer-32：自顶向下的打印二叉树
	*/

	void printBinaryTreeFromTomToBottom(BinaryTreeNode* pTreeRoot);

	/*
	Offer-32-2：
	*/

	void printBinaryTreeFromLeftToRight(BinaryTreeNode* pTreeRoot);

	/*
	Offer-32-3：按照Z字形来打印数字
	*/

	void base::prinBinaryTreeZway(BinaryTreeNode* pTreeRoot);

	/*
	Offer-33：判定数组是否为后序遍历
	*/

	bool base::VerifySeqOfBST(int arry[],int len);

	/*	
	Offer-34：找到二叉树中路径满足给定值
	*/

	void base::findPath(BinaryTreeNode *pRoot, int expectSum);

	/*
	Offer-35：拷贝复杂链表
	*/
	void cloneComplexListNode(ComplexListNode* pHead);

	/*
	Offer-38：给定字符串所有的排列
	*/
	void permutation(char* pStr);

	/*
	Offer-39：找到数字中出现一半的数字
	*/
	int halfInArray(int *array, int length);

	/*
	Offer-40：获取topk大的值
	*/
	void getTopKGreater(const vector<int>data, inSet& inset, int topK);

	/*
	Offer-42:数组中连续数字值最大
	*/
	int getConsequentMax(int* array, int length);

	/*
	Offer-43：获得给定N前出现1的次数
	*/
	int getNumsofOneBeforeN(int n);

private:

};