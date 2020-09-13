#pragma once
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
namespace tree {



    using namespace std;
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    /*
         3
        / \
       9  20
         / \
       15   7 
    */

    vector<TreeNode> traversal(TreeNode root)
    {
        vector<TreeNode> res;
        stack<TreeNode> stack;
        stack.emplace(root);
        while (!stack.empty()) {
            TreeNode node = stack.top();
            res.push_back(node);
            stack.pop();
            if (node.right != NULL) {
                stack.emplace(*node.right);
            }
            if (node.left != NULL) {
                stack.emplace(*node.left);
            }
        }
        return res;
    }

    TreeNode* generateTree() {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        root->right->right->right = new TreeNode(7);
        return root;
    }

    int maxDepth(TreeNode* root)
    {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void test_maxdepth() 
    {
        TreeNode *root = generateTree();
        int dep = maxDepth(root);

        vector<TreeNode> res = traversal(*root);
        for (size_t i = 0; i < res.size(); i++) {
            printf("%d\n", res[i].val);
        }
    }
}