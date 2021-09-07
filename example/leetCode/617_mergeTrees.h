TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;

    TreeNode * mr = new TreeNode(root1->val + root2->val);
    mr->left = mergeTrees(root1->left, root2->left);
    mr->right = mergeTrees(root1->right, root2->right);
    return mr;
}
