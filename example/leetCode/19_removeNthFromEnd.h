#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
//#include"list.h"
using namespace std;
namespace temp {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* faster = head;
		ListNode* normal = head;
		if (faster->next == nullptr && n == 1) {
			return nullptr;
		}
		while (faster != nullptr && n--) {
			faster = faster->next;
		}
		if (faster == nullptr) {
			head = head->next;
			return head;
		}
		while (faster->next != nullptr) {
			normal = normal->next;
			faster = faster->next;
		}


		ListNode* tmp;
		tmp = normal->next->next;
		//printf("tmp value %d\n", tmp->val);
		normal->next = tmp;

		return head;
	}
	ListNode* removeNthFromEnd_BEST(ListNode* head, int n)
	{

		ListNode* faster = head;
		ListNode* normal = head;
		while (n--) {
			faster = faster->next;
		}
		if (faster == nullptr) {
			head = head->next;
			return head;
		}
		while (faster->next != nullptr) {
			normal = normal->next;
			faster = faster->next;
		}
		normal->next = normal->next->next;
	}
	void test_rmNthFromEnd()
	{
		ListNode *res1 = new ListNode(1);
		ListNode *res2 = new ListNode(2);;
		ListNode *res3 = new ListNode(3);;
		ListNode *res4 = new ListNode(4);;

		res1->next = res2;
		res2->next = res3;
		res3->next = res4;

		ListNode* res = removeNthFromEnd(res1, 2);

		while (res != nullptr) {
			printf("value %d\n", res->val);
			res = res->next;
		}
	}
}
