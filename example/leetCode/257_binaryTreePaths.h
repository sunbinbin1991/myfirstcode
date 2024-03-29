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
    vector<vector<int>> result1;
public:
    void dfs(TreeNode* root, vector<int>& path) {
        if(root == nullptr) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if(!path.empty()) {
                result1.push_back(path);
            }
            return;
        }

        if(root->left){
            dfs(root->left, path);
            path.pop_back();
        }

        if(root->right){
            dfs(root->right, path);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path = {};
        // path.push_back(root->val);
        dfs (root, path);
        vector<string> result;
        for(auto paths : result1) {
            string temp = "";
            for(int i = 0; i < paths.size();i++){
                temp += std::to_string(paths[i]);
                if(i != paths.size() - 1){
                    temp += "->";
                }
                std::cout << temp << " ";
            }
            result.push_back(temp);
            std::cout << std::endl;
        }

        return result;
    }
};
