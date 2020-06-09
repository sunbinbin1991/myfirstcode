
#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<bitset>
#include"global_head.h"
#include<7_reverseNum.h>
#include<3_lengthOfLongestSubstring.h>
#include<4_findMedianSortedArrays.h>
#include<5_longestPalindrome.h>
#include<11_maxArea.h>
#include<46_permute.h>
#include<6_zconvert.h>
#include<8_atoi.h>
#include<13_roma2num.h>
#include<14_longestCommonPrefix.h>
#include<15_threeSum.h>
using namespace std;

void test_case_hard() {
	//test_findMedianSortedArrays();
}

void test_case_simple() {
	//test_lengthOfLongestSubstring();
	//tet_longestCommonPrefix();
}

void test_case_mid() {
	//test_lengthOfLongestSubstring();
	//test_longestPalindro();
	//test_maxArea();
	//test_permute();
	//test_zconvert();
	//test_atoi();
	//test_roman2num();
	test_threeSum();
}

int main() {
	printf("*******************\n");
	printf("*-hello leet code-*\n");
	printf("*******************\n");
	
	 //test_case_simple();
	 test_case_mid();
	//test_case_hard();

	printf("\n");
	system("pause");
	return -1;
}
