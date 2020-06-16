#pragma once
#include<vector>
#include<21_mergeTwoLists.h>

using namespace temp;
using namespace std;

void test_mergeKnode() {
	vector<ListNode*> ListNodes;
	ListNode * start = nullptr;
	for (int i = 0; i < ListNodes.size(); i++) {
		start = mergeTwoLists(start, ListNodes[i]);
	}
}