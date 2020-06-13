#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
namespace temp {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr) {
			return l2;
		} else if (l2 == nullptr) {
			return l1;
		} else if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
}