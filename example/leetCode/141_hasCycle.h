#pragma once
#include"typedef.h"
#include<set>

using namespace std;
bool hasCycle(ListNode *head)
{
    std::set<ListNode*> NodeSet;
    while (head != nullptr) { 
        if (NodeSet.find(head) != NodeSet.end) {
            return true;
        } else {
            NodeSet.insert(head);
        }
    }
    return false;
}

void test_hasCycle() 
{

}