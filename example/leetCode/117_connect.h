/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution117 {
public:

    Node* connect(Node* root) {
        deque<Node*> dNode;
        dNode.push_back(root);
        while(!dNode.empty()){
            int len = dNode.size();
            deque<Node*> dNodeTmp;
            deque<Node*> dNodeTmp2;

            for (int i = 0; i < len; ++i) {
                auto front = dNode.front();
                if(!front) break;
                if (front->left != nullptr) {
                    dNodeTmp.push_back(front->left);
                    cout << front->left->val << " ";
                }

                if(front->right != nullptr) {
                    dNodeTmp.push_back(front->right);
                    cout << front->right->val << " ";
                }
                dNode.pop_front();
            }
            cout << endl;
            dNodeTmp2 = dNodeTmp;
            while(!dNodeTmp2.empty()){
                auto front = dNodeTmp2.front();
                dNodeTmp2.pop_front();
                if(!dNodeTmp2.empty()){
                    auto front2 = dNodeTmp2.front();
                    front->next = front2;
                }
            }
            dNode = dNodeTmp;
        }
        return root;
    }
};
