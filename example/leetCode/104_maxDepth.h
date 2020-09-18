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
#include<queue>
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
         /  \
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

    void DFS(TreeNode *root, int level,  vector<vector<int>> &res) 
    {
        if (root == nullptr) {
            return;
        }

        if (res.empty()) {
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
        } else {
            //printf(" test %d %d \n", res.size(),level);
            if (res.size() == level) {
                vector<int> tmp;
                tmp.push_back(root->val);
                res.push_back(tmp);
            } else {
                res[res.size() - 1].push_back(root->val);
            }
        }
        DFS(root->left, level + 1, res);
        DFS(root->right, level + 1, res);
    }

    TreeNode* generateTree() {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->left->left = new TreeNode(15);
        root->left->right = new TreeNode(7);
        //root->right->right->right = new TreeNode(7);
        return root;
    }

    int maxDepth(TreeNode* root)
    {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    //void bfs(TreeNode root)
    //{
    //    Queue<TreeNode> queue = new ArrayDeque<>();
    //    queue.add(root);
    //    while (!queue.isEmpty()) {
    //        int n = queue.size();
    //        for (int i = 0; i < n; i++) {
    //            // 变量 i 无实际意义，只是为了循环 n 次
    //            TreeNode node = queue.poll();
    //            if (node.left != null) {
    //                queue.add(node.left);
    //            }
    //            if (node.right != null) {
    //                queue.add(node.right);
    //            }
    //        }
    //    }
    //}

    void test_maxdepth() 
    {
        TreeNode *root = generateTree();
        // 1: 获取节点的深度
        int dep = maxDepth(root);

        // 2：遍历所有节点
        vector<TreeNode> res = traversal(*root);
        for (size_t i = 0; i < res.size(); i++) {
            //printf("%d\n", res[i].val);
        }

        // 3：层次遍历所有节点
        vector<vector<int>> resvec;
        DFS(root, 0, resvec);
        for (size_t i = 0; i < resvec.size(); i++) {
            for (size_t j = 0; j < resvec[i].size(); j++) {
                printf("%d ", resvec[i][j]);
            }
            printf("\n");
        }

    }

    
}