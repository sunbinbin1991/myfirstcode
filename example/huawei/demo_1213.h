#pragma once
struct Node {
    int val;
    Node* next;
    Node(int v) {
        val = v;
    }
};

void reverseNode(vector<vector<Node*>> allNodes) {

}

Node* reverseKNode(Node* root, int k) {
    if (k < 0) return {};
    if (root == nullptr) return {};
    if (root->next == nullptr || k == 0) return root;

    // calculate node nums
    Node* dummy = root;
    int nodeNums = 0;
    Node* firstNode = nullptr;
    bool findNewRoot = false;
    vector<vector<Node*>> allNodes;
    vector<Node*> kNodes;
    while (dummy->next){
        nodeNums++;
        kNodes.push_back(dummy);
        if (nodeNums % k == 0) {
            allNodes.push_back(kNodes);
            kNodes = {};
        }
        if (!findNewRoot && nodeNums % k == 0) {
            firstNode = dummy;
            findNewRoot = true;
        }
        dummy = dummy->next;
    }
    
    if (nodeNums % k != 0) {
        allNodes.push_back(kNodes);
    }
    // split node by k

    // reverse part

    // combine node
    // return reverse node

}


void test_1213()
{
    printf("hello world 2023/12/13");
    Node N1(1);
    Node N2(2);
    Node N3(3);
    Node N4(4);
    Node N5(5);
    Node N6(6);
    Node N7(7);
    Node N8(8);
    N1.next = &N2;
    N2.next = &N3;
    N3.next = &N4;
    N4.next = &N5;
    N5.next = &N6;
    N6.next = &N7;
    N7.next = &N8;
    int k = 3;
    Node* root = &N1;
    reverseKNode(root, k);
}