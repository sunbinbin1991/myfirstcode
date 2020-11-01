#pragma once
#include<vector>
#include<stack>
#include<104_maxDepth.h>
using namespace std;
//void dfs(int step)
//{
//    �жϱ߽�
//    {
//        ��Ӧ����
//    }
//        ����ÿһ�ֿ���
//    {
//        ����check����
//        ���
//        ������һ��dfs(step + 1)
//        �ָ���ʼ״̬�����ݵ�ʱ��Ҫ�õ���
//    }
//}

namespace tree {
    TreeNode* generateTree2()
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->left->left = new TreeNode(15);
        root->left->right = new TreeNode(7);
        //root->right->right->right = new TreeNode(7);
        return root;
    }
    int dfs(TreeNode* root, int prevSum)
    {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }

    void dfsTree(TreeNode* root, int depth, std::stack<int> &path,
        vector<stack<int>> &res)
    {
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        path.push(root->val);
        if (root->left != nullptr) {
            printf("root->left->val = %d\n", root->left->val);
            path.push(root->left->val);
            dfsTree(root->left, depth, path, res);
        } else if (root->right != nullptr) {
            printf("root->right->val = %d\n", root->right->val);
            path.push(root->right->val);
            dfsTree(root->right, depth, path, res);
        } else {
           // dfsTree(root, depth, path, res);
        }
        path.pop();
    }

    void test_sumTree() {
        TreeNode* firstTreeNode = generateTree2();
        vector<int> startVal;
        startVal.push_back(firstTreeNode->val);
        vector<stack<int>> res;
        stack<int> path;
        dfsTree(firstTreeNode, 0, path, res);
    }

}