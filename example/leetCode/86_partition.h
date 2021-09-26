/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution86 {
public:
    ListNode* partition(ListNode* head, int x) {
        deque<ListNode*> frontQue;
        deque<ListNode*> backQue;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy->next;
        while (cur) {
            if (cur->val < x) {
                frontQue.push_back(cur);
            } else {
                backQue.push_back(cur);
            }
            cur = cur->next;
        }
        ListNode* dummy2 = new ListNode();
        dummy2->next = head;
        ListNode* cur2 = dummy2;
        while(!frontQue.empty()){
            cur2->next = frontQue.front();
            cur2 = cur2->next;
            frontQue.pop_front();
        }

        while(!backQue.empty()){
            cur2->next = backQue.front();
            cur2 = cur2->next;
            backQue.pop_front();
        }
        cur2->next = nullptr;
        return dummy2->next;
    }
};
