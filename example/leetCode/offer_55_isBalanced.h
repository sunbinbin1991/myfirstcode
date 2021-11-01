/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helped(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if(std::abs(depth(left) - depth(right)) <= 1) {
            bool flag1 = true;
            bool flag2 = true;
            if(left != nullptr) {
                flag1 = helped(left->left, left->right);
            }

            if(right != nullptr) {
                flag2 = helped(right->left, right->right);
            }
            return flag2 && flag1;
        } else { 
            return false;
        }
    }

    int depth(TreeNode* root) {
        if(!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return helped(root, root);
    }
};
