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

    Node* connect2(Node* root) {
        if (root == nullptr) {
            return root;
        }
        
        // 初始化队列同时将第一层节点加入队列中，即根节点
        queue<Node*> Q;
        Q.push(root);
        
        // 外层的 while 循环迭代的是层数
        while (!Q.empty()) {
            
            // 记录当前队列大小
            int size = Q.size();
            
            // 遍历这一层的所有节点
            for(int i = 0; i < size; i++) {
                
                // 从队首取出元素
                Node* node = Q.front();
                Q.pop();
                
                // 连接
                if (i < size - 1) {
                    node->next = Q.front();
                }
                
                // 拓展下一层节点
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
        }
        
        // 返回根节点
        return root;
    }

 
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
