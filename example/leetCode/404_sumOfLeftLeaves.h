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
