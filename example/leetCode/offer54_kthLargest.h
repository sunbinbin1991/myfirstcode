    void travese(TreeNode * root, vector<int>& res){
        if(root == nullptr) return;
 
        travese(root->left, res);
        res.push_back(root->val);
        travese(root->right, res);
        // printf("%d ",root->val);
    }

    int kthLargest(TreeNode* root, int k) {
        vector<int> res;
        travese(root, res);
        if(!res.empty() && k > res.size()) return 0;
        return res.empty() ? 0 : res[res.size() - k];
    }
