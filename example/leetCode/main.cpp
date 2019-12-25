
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
#include<algorithm>
void test_cloneComplexNode() {
	
}


void test_pematation() {
		char * simple= "helloworld";
		base alg;
		alg.permutation(simple);
}

void test_halfInArray() {
	int  arry[10] = { 1,2,3,34,4,5,3,3,3,3 };
	int * ab = new int[5];
	int ft = 10;
	float f;
	base alg;
	int res = alg.halfInArray(arry, 10);
	printf("res = %d, sizeof(int) = %d,, sizeof(float) =  %d, sizeof(ab) = %d\n", res, sizeof(int), sizeof(float), sizeof(ab));

}

void test_getTopKBig() {
	std::vector<int> nums = {9,2,3,4,4,5,7,8,10};
	inSet inset;
	//for (size_t i = 0; i < nums.size(); i++)
	//{
	//	inset.insert(nums[i]);
	//}


	base alg;
	alg.getTopKGreater(nums, inset, 5);
	inSet::const_iterator iter = inset.begin();
	for (; iter != inset.end(); iter++) {
		printf("%d \n", *iter);
	}
}

void test_getcurrentMax() {
	std::vector<int> nums = {1, -2,3,10,-4,7,2,-5 };
	base alg;
	int big = alg.getConsequentMax(nums.data(), nums.size());
	printf("%d \n", big);

}

void test_digitAtIndex() {
	char* num = "1234567891011121314151617181920";
	base alg;
	alg.digAtIndex(10);

}

void test_unsignchar() {
	unsigned char myChar = 'A';
	unsigned char *A;
	int B;
	A = &myChar;
	B = static_cast<int>(*A);
	printf("id = %d\n", static_cast<int>(*A));
	std::cout << B << std::endl;
}

void test_printMinNum() {
	int arry[4] = { 12,34,25,56 };
	base alg;
	alg.printMinNumber(arry, 4);
};

struct box {
	int x1;
	int x2;
	int center;
	box()
		:
		center( (x1 + x2) >> 1) {}
};

void test_struct() {
	box bb;
	bb.x1 = 2;
	bb.x2 = 5;

	printf("bb.center %d \n", bb.center);
}

enum stringTT{
	x1,
	x2,
	x3,
	x4=10,
}x;

void test_enum(){
	printf("x = %d", x);
}

void test_unsigned() {
	unsigned char *p1;
	unsigned long *p2;
	p1 = (unsigned char *)0x801000;
	p2 = (unsigned long *)0x810000;
	printf("p1 = %d\n", p1 += 5);
	printf("p2 = %d\n", p2 += 5);
}

void example(char acWelcome[]) {
	printf("%d", sizeof(acWelcome));
	return;
}
void test_char_array() {
	char acWelcome[] = "Welcome to Huawei Test";
	example(acWelcome);
	return;
}

void test_pointer() {
	char str[] = "glad to test something";
	char *p = str;
	p++;
	int *p1 = reinterpret_cast<int *>(p);
	p1++;
	p = reinterpret_cast<char *>(p1);
	printf("result is %s\n", p);
}


void test_char_array2() {
	char str[] = "Hello";
	printf("%d\n", sizeof(str));
	printf("%d\n", strlen(str));
	char*p = str;
	printf("%d\n", sizeof(p));
	example(str);
	return;
}

//class A {
//public:
//	~A() { printf("A"); }
//};

//class B {
//public:
//	~B() { printf("B"); }
//};

class C {
public:
	~C() { printf("C"); }
};

class D {
public:
	~D() { printf("D"); }
};


C c;
void test_destroy()
{
	//A*pa = new A();
	//B b;
	static D d;
	//delete pa;
}

class CTest
{
public:
public:
	CTest() :m_chData('\0'), m_nData(0)
	{
	}
	virtual void mem_fun() {}
private:
	char m_chData;
	int m_nData;
	//static char s_chData;
};

class A
{
public:
	void FuncA()
	{
		printf("FuncA called\n");
	}
	virtual void FuncB()
	{
		printf("FuncB called\n");
	}
};
class B : public A
{
public:
	void FuncA()
	{
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB()
	{
		printf("FuncBB called\n");
	}
};

void test_virual() {
	B  b;
	A  *pa;
	pa = &b;
	A *pa2 = new A;
	pa->FuncA(); 
	pa->FuncB(); 
	pa2->FuncA(); 
	pa2->FuncB();
	delete pa2;
}

int FindSubString(char* pch)
{
	int   count = 0;
	char  * p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count++;
		}
		else {
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] + 1)
		{
			p1++;
			count2--;
		}
		else {
			break;
		}
	}
	if (count2 == 0)
		return(count);
	return(0);
}
void ModifyString(char* pText)
{
	char  * p1 = pText;
	char  * p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while (*p2 != '\0')
			{
				p2++;
			}
			p1 += count + count + 1;
		}
		else {
			*p2++ = *p1++;
		}
	}
}

void test_modify() {
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf(text);
}

char *myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello World!";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}

int test_string()
{
	printf("%s\n", myString());
	return 0;
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
	//test_findPath();
	//test_pematation();
	//test_halfInArray();
	//test_getTopKBig();
	//test_getcurrentMax();	
	//test_digitAtIndex();
	//test_unsignchar();
	//test_printMinNum();
	//test_struct();
	//test_enum();
	//test_unsigned();	
	//test_char_array();	
	//test_char_array2();	
	//test_pointer();
	//test_destroy();
	//test_virual();
	//test_modify();
	test_string();

	printf("sizeof ct= %d\n", sizeof(CTest));
	printf("\n");
	system("pause");
	return -1;
}