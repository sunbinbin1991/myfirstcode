
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <bitset>

#include "base.h"
#include "print.h"
#include "StackWithMin.h"
#include "BinaryTree.h"
using namespace std;

void test_string_pattern() {
	base alg;
	int pos = alg.stringPattern("sadfdsfds", "dsfd", 0);
	printf("pos = %d\n", pos);
};

void test_printToMaxOfNDigits() {
	base alg;
	int n = -1;
	alg.PrintToMaxOfNDigits(n);
}

void test_delListNode() {
	
	ListNode* head = NULL;
	createList(head);
	base alg;
	ListNode* delNode;
}

void test_isNumString() {
	string m_str = "-100E-12";
	base alg;
	bool isNum = alg.isNumString(m_str.c_str());
	printf("isNum = %d ", isNum);

}

void test_recordeeOldEven() {
	int len =10;
	int *data = new int[len];
	for (size_t i = 0; i < len; i++)
	{	
		data[i] = i;
	}
	base alg;
	alg.RecorderOldEven(data, len);
	for (size_t i = 0; i < len; i++)
	{
		printf("res = %d\n", data[i]);
	}
}

void test_printMatrixClockwisely() {
	int matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };	
	int **data = (int**)matrix;
	int totalnums = sizeof(matrix) / sizeof(int);  //元素总个数
	int cols = sizeof(matrix[0]) / sizeof(int);  //行
	int rows = totalnums / cols;
	int len = 6;
	int **mat = new int*[4];
	for (size_t i = 0; i < len; i++)
	{
		mat[i] = new int[len];
		for (size_t j = 0; j < len; j++)
		{
			*(*(mat + i) + j) = len*i + j;
		}
	}
	printMatrix(mat, len, len);
	
	base alg;
	alg.PrintMatrixClockwisely(mat, len, len);

}

void test_minStack() {
	StackWithMin<int> stack;
	stack.push(3);
	printf("stack min =%d\n",stack.min());
	stack.push(2);
	printf("stack min =%d\n", stack.min());
	stack.push(3);
	printf("stack min =%d\n", stack.min());
	stack.push(1);
	printf("stack min =%d\n", stack.min());
	stack.pop();
	stack.pop();
	stack.pop();
	printf("stack min =%d\n", stack.min());
}

void test_isStackOrder() {
	int data1[5] = { 1,2,3,4,5 };
	int data2[5] = { 4,5,3,1,2 };
	base alg;
	bool res = alg.isPopOrder(data1, data2, 5);

	printf("res = %d\n", res);
	
}

void test_printBinaryTreeFromTopToBottom() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	printf("====Test1 Begins: ====\n");
	printf("Expected Result is:\n");
	printf("8 \n");
	printf("6 10 \n");
	printf("5 7 9 11 \n\n");

	base alg;
	alg.printBinaryTreeFromTomToBottom(pNode8);


}

void test_printBinaryTreeFromLeftToRight() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	printf("====Test1 Begins: ====\n");
	printf("Expected Result is:\n");
	printf("8 \n");
	printf("6 10 \n");
	printf("5 7 9 11 \n\n");

	base alg;
	alg.printBinaryTreeFromLeftToRight(pNode8);
}

void test_printBinaryTreeZway() {
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode13 = CreateBinaryTreeNode(13);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode15 = CreateBinaryTreeNode(15);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	ConnectTreeNodes(pNode4, pNode8, pNode9);
	ConnectTreeNodes(pNode5, pNode10, pNode11);
	ConnectTreeNodes(pNode6, pNode12, pNode13);
	ConnectTreeNodes(pNode7, pNode14,nullptr);

	base alg;
	alg.printBinaryTreeFromLeftToRight(pNode1);

	alg.prinBinaryTreeZway(pNode1);
}

void test_findPath() {
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	printf("====Test1 Begins: ====\n");
	printf("Expected Result is:\n");
	printf("8 \n");
	printf("6 10 \n");
	printf("5 7 9 11 \n\n");

	base alg;
	alg.findPath(pNode8, 27);

}


int main(){
	printf("*******************\n");
	printf("*-hello leet code-*\n");
	printf("*******************\n");
	//test_string_pattern();
	//test_printToMaxOfNDigits();
	//test_delListNode();
	//test_isNumString();
	//test_recordeeOldEven();
	//test_printMatrixClockwisely();
	//test_minStack();
	//test_isStackOrder();
	//test_printBinaryTreeFromTopToBottom();
	//test_printBinaryTreeFromLeftToRight();
	//test_printBinaryTreeZway();

	test_findPath();

	system("pause");
	return -1;
}