#pragma once
#include<tree.h>
class Solution358 {
public:
    /*ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead; // ��һ����Ҫ�ú����һ��
        return head;
    }*/
};

