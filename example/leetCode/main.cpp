
#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <bitset>
#include "global_head.h"
#include <7_reverseNum.h>
#include <3_lengthOfLongestSubstring.h>
#include <4_findMedianSortedArrays.h>
#include <5_longestPalindrome.h>
using namespace std;

void test_case_hard() {
	test_findMedianSortedArrays();

}

void test_case_simple() {
	//test_lengthOfLongestSubstring();
}

void test_case_mid() {
	//test_lengthOfLongestSubstring();
	test_longestPalindro();
}

int main() {
	printf("*******************\n");
	printf("*-hello leet code-*\n");
	printf("*******************\n");
	
	// test_case_simple();
	 test_case_mid();
	//test_case_hard();

	printf("\n");
	system("pause");
	return -1;
}