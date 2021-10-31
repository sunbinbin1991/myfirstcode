class Solution230 {
public:
    void preOrder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        preOrder(root->left, res);
        res.push_back(root->val);
        preOrder(root->right, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr || k < 0) return 0;
        vector<int> res;
        preOrder(root, res);
        if (res.size() < k) {
            return 0;
        }
        return res[k-1];
    }
};
