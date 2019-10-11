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
	int n = 4;
	alg.PrintToMaxOfNDigits(n);
}




int main(){
	printf("*******************\n");
	printf("*-hello leet code-*\n");
	printf("*******************\n");
	//test_string_pattern();
	
	test_printToMaxOfNDigits();

	system("pause");
	return -1;
}