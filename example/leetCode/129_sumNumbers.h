//
// Created by s30001871 on 2021/9/18.
//

#ifndef MYFIRSTCODE_129_SUMNUMBERS_H
#define MYFIRSTCODE_129_SUMNUMBERS_H

class Solution129 {
public:
    int dfs(TreeNode* root, int prevSum) {
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

void dfsPathMine_WRONG(set<string>& paths, string& path, TreeNode* root){
    if(root == nullptr){
        if(!path.empty()) {
            paths.insert(path);
        }
        return;
    }
    path += std::to_string(root->val);
    dfsPathMine_WRONG(paths, path, root->left);
    path.erase(path.end() - 1);

    path += std::to_string(root->val);
    dfsPathMine_WRONG(paths, path, root->right);
    path.erase(path.end() - 1 );

}

void dfsPath(vector<string>& paths, string& path, TreeNode* root){
    if(root->left == nullptr && root->right == nullptr){
        path += std::to_string(root->val);
        paths.push_back(path);
        path.erase(path.end() - 1 );
        return;
    }
    path += std::to_string(root->val);
    if(root->left != nullptr) {
        dfsPath(paths, path, root->left);
    }
    if(root->right != nullptr){
        dfsPath(paths, path, root->right);
    }
    path.erase(path.end() - 1 );
}

string stringAdd2 (string num1,string num2) {
    if(num1.empty()) return num2;
    if(num2.empty()) return num1;
    int len1 = num1.size();
    int len2 = num2.size();
    int len = min(len1,len2);
    int index = 0;
    int carry = 0;
    string res = "";
    while(index  < len) {
        int pos1 = num1[index] - '0';
        int pos2 = num2[index] - '0';

        res += std::to_string((pos1 + pos2 + carry) % 10);
        carry = (pos1 + pos2 + carry) / 10;
        index++;
    }
    string tmp = num1.size() > num2.size() ? num1 : num2;
    int maxLen = max(num1.size(), num2.size());
    for (int i = index; i < maxLen; ++i) {
        int pos1 = tmp[i] - '0';
        res +=  std::to_string((pos1 + carry) % 10);
        carry = (pos1 + carry) / 10;
    }
    if( carry != 0) {
        res += std::to_string(carry);
    }
    return res;
}

int sumNumbers(TreeNode* root) {
    if(root == nullptr) return 0;
    vector<string> paths;
    string path = "";
    string res = "";
    dfsPath(paths, path, root);
    for(auto pt: paths) {
        reverse(pt.begin(), pt.end());
        res = stringAdd2(res, pt);
        cout <<"pt : "<< pt.c_str() << endl;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    int i = 0;
    while(i < res.size()){
        if(res[i] == '0'){
            i++;
        } else {
            break;
        }
    }
    res = res.substr(i, res.size() - i);

    return atoi(res.c_str());
}

void test_sumNumbers(){
    TreeNode * root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
//    root->left->left->left = new TreeNode(7);
//    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(0);
//    root->right->left = new TreeNode(1);
//    root->right->right = new TreeNode(6);
//    root->right->right->right = new TreeNode(1);
    auto res = sumNumbers(root);
    cout << res << endl;
}

#endif //MYFIRSTCODE_129_SUMNUMBERS_H
