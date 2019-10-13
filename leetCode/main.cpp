#include"base.h"
#include<stdio.h>
#include<vector>
#include<iostream>
#include <map>
#include <bitset>
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

int main(){
	printf("*******************\n");
	printf("*-hello leet code-*\n");
	printf("*******************\n");
	//test_string_pattern();
	//test_printToMaxOfNDigits();
	//test_delListNode();
	//test_isNumString();

	test_recordeeOldEven();


	system("pause");
	return -1;
}