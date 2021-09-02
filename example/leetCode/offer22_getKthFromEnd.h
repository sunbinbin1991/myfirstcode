    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy->next;
        ListNode* fast = dummy->next;
        while (--k) {
            if(fast->next) {
                fast = fast->next;
            }
        }
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
            // cout << "s "<< slow->val <<endl;
            // cout << "f "<< fast->val <<endl;
        }
        return slow;
    }
