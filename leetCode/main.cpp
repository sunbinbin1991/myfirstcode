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

int main(){
	printf("*******************\n");
	printf("*-hello leet code-*\n");
	printf("*******************\n");
	//test_string_pattern();
	//test_printToMaxOfNDigits();
	//test_delListNode();

	test_isNumString();

	system("pause");
	return -1;
}