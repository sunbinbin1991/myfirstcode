#pragma once
struct ListNode
{
	int m_key;
	ListNode * next;

	int val;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct ComplexListNode {
	int m_value;
	ComplexListNode * m_pNext;
	ComplexListNode * m_pSibling;
};


inline void createList(ListNode* &pHead)
{
	pHead = new ListNode(0);
	pHead->m_key = 0;
	pHead->next = NULL;
	ListNode* p = pHead;    
	for (int i = 1; i<10; i++)
	{
		ListNode* pNewNode = new ListNode(0);
		pNewNode->m_key = i;
		pNewNode->val = i;
		pNewNode->next = NULL;
		p->next = pNewNode;
		p = pNewNode;
	}
}

inline void PrintList(ListNode* &pHead) 
{
	int count = 0;
	ListNode* part = pHead;
	while(part && part->next){
		printf("[%d] %d\n", count++, part->val);
		part = part->next;
	}
}


