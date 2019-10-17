#include"base.h"
#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
#include <bitset>

#include"print.h"
#include"StackWithMin.h"

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

	printf("res = %d", res);


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

	test_isStackOrder();

	system("pause");
	return -1;
}