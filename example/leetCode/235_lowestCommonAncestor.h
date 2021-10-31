/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution235 {
    unordered_map<int, TreeNode*> fa; // 节点值的父节点
    unordered_map<int, bool> vis;
public:
    void dfsTree(TreeNode * root) {
        if (!root) return;
        vis[root->val] = false;
        if(root->left){
            fa[root->left->val] = root;
        }
        if(root->right){
            fa[root->right->val] = root;
        }
        dfsTree(root->left);
        dfsTree(root->right);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        dfsTree(root);
        if(fa[p->val] == q) return q;
        if(fa[q->val] == p) return p;

        TreeNode* temp = p;

        while (temp != root){
            vis[temp->val] = true;
            temp = fa[temp->val];
        }

        temp = q;
        while (temp != root){
            if (vis[temp->val]){
                return temp;
            }
            temp = fa[temp->val];
        }

        return root;
    }
};
