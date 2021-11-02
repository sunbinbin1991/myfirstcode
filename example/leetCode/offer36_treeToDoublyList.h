/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution_offer_36 {
    vector<Node*> vec;
public:
    void getWholeNode(Node* root) {
        if (root == nullptr) return;
        getWholeNode(root->left);
        vec.push_back(root);
        getWholeNode(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        getWholeNode(root);
        if(vec.empty()) return nullptr;
        if(vec.size() == 1) {
            vec[0]->left = vec[0];
            vec[0]->right = vec[0];
            return vec[0];
        }
        
        for(int i = 0; i < vec.size(); i++) {
            if (i == 0) {
                vec[i]->left = vec.back();
                vec[i]->right = vec[i+1];
            } else if(i == vec.size() - 1) {
                vec[i]->left = vec[i - 1];
                vec[i]->right = vec.front();
            } else {
                vec[i]->left = vec[i - 1];
                vec[i]->right = vec[i + 1];
            }
        }
        for(auto n : vec) {
            printf("%d\n", n->val);
            printf("f:%d\n", vec.front()->val);
            printf("e:%d\n", vec.back()->val);
        }
        return vec[0];
    }
};
