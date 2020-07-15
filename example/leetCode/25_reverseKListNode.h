#pragma once
#include"typedef.h"

ListNode* reverseListNode(ListNode* phead)
{
	ListNode* targetres = nullptr;
	ListNode* tmp = nullptr;
	int count = 1;
	int k = 3;
	ListNode* subNodes = nullptr;
	ListNode* mergeNodes = nullptr;
	while (phead) {
		tmp = phead->next;
		phead->next = subNodes;
		subNodes = phead;
		phead = tmp;
		if (count++ == k) {
			count = 1;
			ListNode* tmptemp = nullptr;
			mergeNodes = targetres;
			if (targetres == nullptr) {
				targetres = subNodes;
				subNodes = nullptr;
				continue;
			}
			while (mergeNodes) {
				mergeNodes = mergeNodes->next;
				if (mergeNodes == nullptr || mergeNodes->next == nullptr) {
					mergeNodes->next = subNodes;
					subNodes = nullptr;
					break;
				}
			}
		}
	}

	if (subNodes != nullptr) {
		while (mergeNodes) {
			mergeNodes = mergeNodes->next;
			if ( mergeNodes->next == nullptr|| mergeNodes == nullptr) {
				mergeNodes->next = subNodes;
				subNodes = nullptr;
				break;
			}
		}
	}
	return targetres;
}

ListNode* reverseKListNode(ListNode* phead,int k)
{
	ListNode* res = NULL;
	return res;
}

void test_reverseKListNode() 
{
	ListNode* head = new ListNode(0);

	createList(head);
	//PrintList(head);

	ListNode* res = reverseListNode(head);
	PrintList(head);
}
