#pragma once
#include"typedef.h"

ListNode* reverseListNode(ListNode* phead)
{
	ListNode* res = nullptr;
	ListNode* tmp = nullptr;
	while (phead) {
		//tmp = phead->next;
		//phead->next = res;
		//res = phead;
		//phead = tmp;

		tmp = phead->next;
		phead->next = res;
		res = phead;
		phead = tmp;
		//printf("%d\n", phead->val);
	}
	return res;
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
	PrintList(res);
}
