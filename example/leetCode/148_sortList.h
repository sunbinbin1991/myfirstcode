//
// Created by s30001871 on 2021/8/31.
//

#ifndef MYFIRSTCODE_148_SORTLIST_H
#define MYFIRSTCODE_148_SORTLIST_H
bool comList(ListNode* la, ListNode* lb){
    return la->val < lb->val;
}
ListNode* sortList(ListNode* head) {
    if(head == nullptr) return nullptr;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = dummy->next;

    vector<ListNode*> vListNode;
    while (curr) {
        vListNode.push_back(curr);
        curr = curr->next;
    }

    sort(vListNode.begin(), vListNode.end(), comList);
    ListNode* dummy2 = new ListNode(-1);
    dummy2->next = vListNode[0];
    ListNode* curr2 = dummy2->next;
//    cout <<"size = " <<  curr2->val << endl;
    for (int i = 1; i < vListNode.size(); i++) {
         cout << vListNode[i]->val << endl;
        curr2->next = vListNode[i];
         cout << curr2->next->val << endl;
        curr2 = curr2->next;
    }
    curr2->next = nullptr;
    return dummy2->next;
}

void test_sortList(){
    ListNode* root = new ListNode(4);
    root->next = new ListNode(2);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(3);
    sortList(root);
}

#endif //MYFIRSTCODE_148_SORTLIST_H
