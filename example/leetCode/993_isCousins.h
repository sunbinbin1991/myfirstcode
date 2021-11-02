/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution993 {
    map<TreeNode*, int> father;
    map<int, TreeNode* > self;
    map<TreeNode*, int> depthMap;
    int m_depth = 0;
public:
    int GetDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(GetDepth(root->left), GetDepth(root->right)) + 1;
    }

    void levelOrder(TreeNode* root) {
        if (root == nullptr) return ;
        if (root->left != nullptr) {
            father[root->left] = root->val;
            levelOrder(root->left);
        }
        if (root->right != nullptr) {
            father[root->right] = root->val;
            levelOrder(root->right);
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        levelOrder(root);
        deque<TreeNode*> vec;
        vec.push_back(root);
        while(!vec.empty()) {
             deque<TreeNode*> vec2 = vec;
            for (int i = 0; i < vec2.size(); i++) {
                auto pt = vec2[i];
                depthMap[pt] = m_depth;
                self[pt->val] = pt;
                if (pt->left != nullptr) {
                    vec.push_back(pt->left);
                }
                if (pt->right != nullptr) {
                    vec.push_back(pt->right);
                }   
                vec.pop_front();             
            }
            m_depth ++;
        }

        int d1 = depthMap[self[x]];
        int d2 = depthMap[self[y]];
        
        int f1 = father[self[x]];
        int f2 = father[self[y]];
        if(d1 == d2 && f1 != f2 && x != y) {
            return true;
        }
        return false;
    }
};
