#pragma once
#include"typedef.h"

ListNode* reverseListNode(ListNode* phead)
{
	ListNode* res = NULL;
	ListNode* tmp = NULL;
	ListNode* p = phead;
	while (p->next) {
		tmp = p->next;
		tmp->next = res;
		res = tmp;
		p = p->next;
		printf("%d\n", p->val);
	}
	return tmp;
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
	PrintList(head);

	ListNode* res = reverseListNode(head);
	PrintList(res);
}
