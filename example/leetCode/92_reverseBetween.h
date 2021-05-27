#pragma once

#include<vector>
#include<iostream>
#include<stack>

void reverseLinkedList2(ListNode *head)
{
    // Ҳ����ʹ�õݹ鷴תһ������
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while (cur != nullptr) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
}

ListNode* reverseBetween2(ListNode* head, int left, int right)
{
    // ��Ϊͷ�ڵ��п��ܷ����仯��ʹ������ͷ�ڵ���Ա��⸴�ӵķ�������
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;

    ListNode *pre = dummyNode;
    // �� 1 ����������ͷ�ڵ��� left - 1 �������� left �ڵ��ǰһ���ڵ�
    // ����д�� for ѭ�����������
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }

    // �� 2 ������ pre ���� right - left + 1 �������� right �ڵ�
    ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
        rightNode = rightNode->next;
    }

    // �� 3 �����жϳ�һ����������ȡ����
    ListNode *leftNode = pre->next;
    ListNode *curr = rightNode->next;

    // ע�⣺�ж�����
    pre->next = nullptr;
    rightNode->next = nullptr;

    // �� 4 ����ͬ�� 206 �⣬��ת�����������
    reverseLinkedList2(leftNode);

    // �� 5 �����ӻص�ԭ����������
    pre->next = rightNode;
    leftNode->next = curr;
    return dummyNode->next;
}
using namespace std;
//using namespace LeetCode;

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode* root = head;
    ListNode* temp = head;
    stack<ListNode*> vListNode;
    vector<ListNode*> vListNodeL;
    vector<ListNode*> vListNodeR;
    int val = 0;
    while (head) {
        val++;
        if (val <= left) {
            vListNodeL.push_back(head);
        } else if(val > right){
            vListNodeR.push_back(head);
        } else {
            vListNode.push(head);
        }
        head = head->next;
    }
    if (left == 1) {
        root = vListNode.top();
    }
    int leftNum = vListNodeL.size();
    for (size_t i = 0; i < vListNodeL.size(); i++) {
        root->next = vListNodeL[i];
        root = root->next;
    }

    while (!vListNode.empty()) {
        root->next = vListNode.top();
        root = root->next;
        vListNode.pop();
    }

    for (size_t i = 0; i < vListNodeR.size(); i++) {
        root->next = vListNodeR[i];
        root = root->next;
    }
    return root;
}

void test_reverseBetween() {
    ListNode* root = new ListNode(1);
    int k = 1;
    while (k++ < 6) {
        root->next = new ListNode(k);
        root = root->next;
    }
    auto ans = reverseBetween(root, 2, 4);
    while (ans) {
        std::cout << ans->val << std::endl;
        ans = ans->next;
    }
}