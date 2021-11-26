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
class Solution700 {
public:
    void midTree(TreeNode* root, vector<TreeNode*>& vec) {
        if (root == nullptr) return;
        midTree(root->left, vec);
        vec.push_back(root);
        midTree(root->right, vec);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        vector<TreeNode*> vec;
        midTree(root, vec);
        for(auto it : vec) {
            if(it->val == val) {
                return it;
            }
        }
        return nullptr;
    }
};
