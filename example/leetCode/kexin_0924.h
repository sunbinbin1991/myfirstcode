//
// Created by s30001871 on 2021/10/15.
//

#ifndef MYFIRSTCODE_TEST_DEMO_0924_H
#define MYFIRSTCODE_TEST_DEMO_0924_H

int dfsDepth(const TreeNode* root) {
    if(root == nullptr){
        return 0;
    }
    int leftDepth = dfsDepth(root->left);
    int rightDepth = dfsDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

vector<int> ValueDepth(const vector<int> &target, TreeNode *root)
{
    deque<TreeNode*> vTrees;
    vTrees.push_back(root);
    map<int, int> mapTree;
    while (root) {
        while (!vTrees.empty()) {
           auto temp = vTrees.front();
           if (mapTree.find(temp->val) != mapTree.end()) {
               int depth = dfsDepth(temp);
               if (mapTree[temp->val] < depth) {
                   mapTree[temp->val] = depth;
               }
           } else {
               mapTree.emplace(std::pair<int,int>(temp->val, dfsDepth(temp)));
           }
            if (temp->left) {
                vTrees.push_back(temp->left);
            }
            if (temp->right) {
                vTrees.push_back(temp->right);
            }
            vTrees.pop_front();
        }

        if (root->left) {
            vTrees.push_back(root->left);
        }
        if (root->right) {
            vTrees.push_back(root->right);
        }
        vTrees
    }

    int res = dfsDepth(root);

    cout << res << endl;
    return {};
}

void test_maxTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);

    vector<int> target = {2, 7};
    auto res = ValueDepth(target, root);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}
#endif //MYFIRSTCODE_TEST_DEMO_0924_H
