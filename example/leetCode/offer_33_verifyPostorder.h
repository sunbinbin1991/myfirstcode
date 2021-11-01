class Solution_offer_33 {
public:
    bool verifyPostorder(vector<int>& postorder) {
        // 给定一棵二叉搜索树，判断该树是否为二叉搜索树后序遍历
        return helper(postorder, 0, postorder.size()-1);
    }
    
    bool helper(vector<int>& postorder, int start, int end){
        if (start >= end) return true;
        int root = postorder[end];
        int temp;
        while(postorder[temp] < postorder[end]){
            // 这里mid最后指向的是右子树的第一个节点
            temp++;
        }
        int mid = temp;
        // 左子树已经判断，现在需要判断右子树
        for (int i=mid; i<end; ++i){
            if (postorder[i]<postorder[end])
                return false;
        }
        
        return helper(postorder, start, mid-1) && helper(postorder, mid, end-1);
    }
};

