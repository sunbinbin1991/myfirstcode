#pragma once
struct ListNode
{
	int m_key;
	ListNode * next;
};

struct ComplexListNode {
	int m_value;
	ComplexListNode * m_pNext;
	ComplexListNode * m_pSibling;
};


inline void createList(ListNode* &pHead)
{
	pHead = new ListNode;
	pHead->m_key = 0;
	pHead->next = NULL;
	ListNode* p = pHead;    
	for (int i = 1; i<10; i++)
	{
		ListNode* pNewNode = new ListNode;
		pNewNode->m_key = i;
		pNewNode->next = NULL;
		p->next = pNewNode;
		p = pNewNode;
	}
}


