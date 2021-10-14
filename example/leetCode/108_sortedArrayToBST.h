    TreeNode * dfsTreeBST(vector<int>& nums, int left, int right)
    {
        if(left > right){
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = dfsTreeBST(nums, left, mid - 1);
        root->right = dfsTreeBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return dfsTreeBST(nums, 0, nums.size() - 1);
    }
