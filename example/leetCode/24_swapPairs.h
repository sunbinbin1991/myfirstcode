#include<vector>
#include<21_mergeTwoLists.h>
using namespace temp;
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

