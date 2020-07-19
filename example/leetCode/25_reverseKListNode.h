#pragma once
#include"typedef.h"

pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail)
{
	ListNode* prev = tail->next;
	ListNode* p = head;
	while (prev != tail) {
		ListNode* nex = p->next;
		p->next = prev;
		prev = p;
		p = nex;
	}
	return{ tail, head };
}

ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode* hair = new ListNode(0);
	hair->next = head;
	ListNode* pre = hair;

	while (head) {
		ListNode* tail = pre;
		// 查看剩余部分长度是否大于等于 k
		for (int i = 0; i < k; ++i) {
			tail = tail->next;
			if (!tail) {
				return hair->next;
			}
		}
		ListNode* nex = tail->next;
		// 这里是 C++17 的写法，也可以写成
		// pair<ListNode*, ListNode*> result = myReverse(head, tail);
		// head = result.first;
		// tail = result.second;
		tie(head, tail) = myReverse(head, tail);
		// 把子链表重新接回原链表
		pre->next = head;
		tail->next = nex;
		pre = tail;
		head = tail->next;
	}

	return hair->next;
}

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
