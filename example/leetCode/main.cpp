
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
#include<16_threeSumClosest.h>
#include<17_letterCombinations.h>
#include<18_fourSum.h>
#include<19_removeNthFromEnd.h>
#include<20_isValid.h>
#include<22_generateParenthesis.h>
#include<24_swapPairs.h>
#include<25_reverseKListNode.h>
#include<26_removeDuplicates.h>
#include<28_strStr.h>
#include<recur_1611_devingBoard.h>
#include<350_intersection.h>
#include<349_intersect.h>
#include<121_maxProfit.h>
#include<66_addOne.h>
#include<53_maxSubArray.h>
#include<300_DP_LIS.h>
using namespace std;

void test_case_hard() {
	//test_findMedianSortedArrays();
	//test_reverseKListNode();
	//test_rmDuplicates();
}

void test_case_simple() {
	//test_lengthOfLongestSubstring();
	//tet_longestCommonPrefix();
    //test_strStr();
    //test_divingBoard();
    //test_intersection();
    //test_intersection2();
    //test_maxStockProfit();
    //test_plusOne();
    //test_maxSubArray();
}

void test_case_mid() {
	//test_lengthOfLongestSubstring();
	//test_longestPalindro();
	//test_maxArea();
	//test_permute();
	//test_zconvert();
	//test_atoi();
	//test_roman2num();
	//test_threeSum();
	//test_threeSumClosest();
	//test_letterCombinations();
	//test_foursum();
	//temp::test_rmNthFromEnd();
	//test_valid();
	//test_swappairs();
    test_lengthOfLIS();
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
