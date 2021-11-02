class Solution237 {
public:
    void deleteNode(ListNode* node) {
        if(node->next == nullptr) {
            return;
        }
        // ListNode* temp = node->next->next;
        // node = nullptr;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
