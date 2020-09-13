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
        printf("dep = %d\n", dep);
    }
}