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
class Solution {
public:
    int sumTree (TreeNode * root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        sum += root->val;
        return sum + left + right;
    }

    int findTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        int diff = 0;
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        diff += abs(left - right);
        printf("l :%d, r:%d\n", left, right);
        diff += findTilt(root->left) + findTilt(root->right);
        return diff;
    }
};
