/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution236 {
public:
   unordered_map<int, TreeNode*> fa; // 节点值的父节点
   unordered_map<int, bool> vis;

    void dfsTree(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            fa[root->left->val] = root;
            dfsTree(root->left);
        }

        if(root->right != nullptr){
            fa[root->right->val] = root;
            dfsTree(root->right);
        }
       
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfsTree(root);
        while(p != nullptr){
            vis[p->val] = true;
            TreeNode* fa1 = fa[p->val];
            p = fa1;
        }

        while (q != nullptr) {
            if (vis.find(q->val) != vis.end()) {
                return q;
            }
            TreeNode* fa1 = fa[q->val];
            q = fa1;
        }
        return nullptr;
    }
};
