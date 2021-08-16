
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
#include<120_minimumTotal.h>
#include<344_reverseStr.h>
#include<104_maxDepth.h>
#include<239_maxSlidingWindow.h>
#include<1207_uniqueOccurrences.h>
#include<129_sumNumberTree.h>
#include<327_countRangeSum.h>
#include<88_mergeSortedArray.h>
#include<973_kClosest.h>
#include<922_sortArrayByParityII.h>
#include<547_findCircleNum.h>
#include<34_searchRange.h>
#include<198_rob.h>
#include<42_trap.h>
#include<55_canJump.h>
#include<33_search.h>
#include<215_findKthLargest.h>
#include<136_singleNum.h>
#include<92_reverseBetween.h>
#include<461_hamingDistance.h>
#include<611_triangleNumber.h>
#include<103_zigzagLevelOrder.h>
#include<457_circularArrayLoop.h>
#include<154_findMin.h>
#include<offer21_exchange.h>
#include<313_nthSuperUglyNumber.h>
#include<1583_unhappyFriends.h>
#include<213_rob.h>
#include<47_permuteUnique.h>
using namespace std;
using namespace tree;

void test_case_hard() {
    test_findMin();
	//test_findMedianSortedArrays();
	//test_reverseKListNode();
	//test_rmDuplicates();
    //test_maxSlidingWindow();
    //test_trap();
    //test_countRangeSum();
}

void test_case_simple() {
    test_exchange();
	//test_lengthOfLongestSubstring();
	//tet_longestCommonPrefix();
    //test_strStr();
    //test_divingBoard();
    //test_intersection();
    //test_intersection2();
    //test_maxStockProfit();
    //test_plusOne();
    //test_maxSubArray();
    //test_reverseString();
    //tree::test_maxdepth();
    //test_merge_array();
    //test_sortArrayByParityII();
    //test_hammingDistance();
}

void test_case_mid() {
    test_permuteUnique();
    //test_rob2();

    //test_unhappyFriends();
    //test_nthSuperUglyNumber();
    //test_circularArrayLoop();
    //test_zigzagLevelOrder();

    //test_sumTree();
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
    //test_lengthOfLIS();
    //test_minimumTotal();
    //test_kClosest();
    //test_searchRange();
    //test_rob();
    //test_search();
    //test_findKthLargest();
    //test_singleNumber2();
    //test_reverseBetween();
    //test_triangleNumber();
}

int main() {
	printf("*******************\n");
	printf("*-hello leet code 2021-*\n");
	printf("*******************\n");
	
	//test_case_simple();
	test_case_mid();
	//test_case_hard();

	printf("\n");
	system("pause");
	return -1;
}

