/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int val = INT_MIN;
        for (auto chid : root->children) {
            val = max(maxDepth(chid), val);
        }
        return val == INT_MIN ? 1: val + 1;
    }
};
