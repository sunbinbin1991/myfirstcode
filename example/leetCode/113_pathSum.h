   void dfsPathSum(TreeNode* root, vector<vector<int>> & paths, vector<int> & path, int targetSum) {
        if(root->right == nullptr && root->left == nullptr){
            int sum = 0;
            for (int i = 0; i < path.size(); ++i) {
                sum += path[i];
            }
            if(sum == targetSum){
                paths.push_back(path);
            }
            return;
        }
        if(root->left){
            path.push_back(root->left->val);
            dfsPathSum(root->left, paths,path, targetSum);
            path.pop_back();
        }

        if(root->right){
            path.push_back(root->right->val);
            dfsPathSum(root->right, paths,path, targetSum);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<vector<int>> paths;
        vector<int> path;
        path.push_back(root->val);
        dfsPathSum(root, paths, path, targetSum);
        return paths;
    }
