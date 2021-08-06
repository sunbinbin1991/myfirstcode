#pragma once
#include<vector>
#include<deque>
//#include"tree.h"
using namespace tree;
vector<int> getVec(queue<TreeNode*>treeQue, queue<TreeNode*>& treeQue2) {
    vector<int> temp;
    while (!treeQue.empty()) {
        auto front = treeQue.front();
        if (front->left) {
            treeQue2.push(front->left);
        }
        if (front->right) {
            treeQue2.push(front->right);
        }
        temp.push_back(front->val);
        treeQue.pop();
    }
    return temp;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    if (root == nullptr) return{};
    vector<vector<int>> ans;
    queue<TreeNode*> treeQue;
    treeQue.push(root);
    bool isFromLeft = true;
    while (!treeQue.empty()) {
        queue<TreeNode*> treeQue2;
        if (isFromLeft) {
            vector<int> temp = getVec(treeQue, treeQue2);
            ans.push_back(temp);
        }
        if (!isFromLeft) {
            vector<int> temp = getVec(treeQue, treeQue2);
            for (size_t i = 0; !temp.empty() && i < temp.size() / 2; i++) {
                swap(temp[i], temp[temp.size() - 1 - i]);
            }
            ans.push_back(temp);
        }
        isFromLeft = !isFromLeft;
        treeQue = treeQue2;
    }
    return ans;
}

void test_zigzagLevelOrder()
{
    TreeNode* rot = new TreeNode(3);
    rot->left = new TreeNode(9);
    rot->right = new TreeNode(20);
    rot->right->left = new TreeNode(15);
    rot->right->right = new TreeNode(7);

    TreeNode* rot2 = new TreeNode(1);
    rot2->left = new TreeNode(2);
    rot2->right = new TreeNode(3);
    rot2->left->left = new TreeNode(4);
    rot2->left->right = new TreeNode(5);
    rot2->right->left = new TreeNode(6);
    rot2->right->right = new TreeNode(7);

    auto res = zigzagLevelOrder(rot2);
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

    return;
}