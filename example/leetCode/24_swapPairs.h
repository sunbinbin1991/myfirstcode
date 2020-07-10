#include<vector>
#include<21_mergeTwoLists.h>
//using namespace temp;
using namespace std;

ListNode* swapPairs(ListNode* head)
{
	if (!head) return NULL;
	ListNode* prePtr = new ListNode(0);
	prePtr->next = head;
	ListNode* res = prePtr;

	ListNode* curPtr = head;
	ListNode* rearPtr = curPtr->next;
	while (curPtr->next) {
		prePtr->next = rearPtr;
		curPtr->next = curPtr->next->next;
		rearPtr->next = curPtr;
		prePtr = curPtr;
		curPtr = curPtr->next;
		if (!curPtr) break;
		rearPtr = curPtr->next;
	}
	return res->next;
}

void test_swappairs() {
	ListNode* head = new ListNode(0);
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);

	head->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	ListNode* res = swapPairs(head);

	while (res->next) {
		printf("%d ", res->val);
		res = res->next;
	}
}

