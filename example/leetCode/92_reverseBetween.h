#pragma once

#include<vector>
#include<iostream>
#include<stack>

void reverseLinkedList2(ListNode *head)
{
    // 也可以使用递归反转一个链表
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
    // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;

    ListNode *pre = dummyNode;
    // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
    // 建议写在 for 循环里，语义清晰
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }

    // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
    ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
        rightNode = rightNode->next;
    }

    // 第 3 步：切断出一个子链表（截取链表）
    ListNode *leftNode = pre->next;
    ListNode *curr = rightNode->next;

    // 注意：切断链接
    pre->next = nullptr;
    rightNode->next = nullptr;

    // 第 4 步：同第 206 题，反转链表的子区间
    reverseLinkedList2(leftNode);

    // 第 5 步：接回到原来的链表中
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