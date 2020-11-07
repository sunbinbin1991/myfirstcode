#pragma once

namespace tree {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* temp; // ����cur����һ���ڵ�
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur) {
        temp = cur->next;  // ����һ�� cur����һ���ڵ㣬��Ϊ������Ҫ�ı�cur->next
        cur->next = pre; // ��ת����
        // ����pre �� curָ��
        pre = cur;
        cur = temp;
    }
    return pre;
}

}

