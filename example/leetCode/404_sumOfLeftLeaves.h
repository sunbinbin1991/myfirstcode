    int helper(TreeNode* root){
        if (root == nullptr) return 0;
        int res = 0;
        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                 res += root->left->val;
            }
            res += helper(root->left);
        }
        if (root->right!= nullptr) {
            res += helper(root->right);
        }
        return res;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        res += helper(root);
        return res;
    }
class Solution404 {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) {
        int ans = 0;
        if (node->left) {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};

