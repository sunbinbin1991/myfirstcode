    bool isSame(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return true;
        }
        if (A == nullptr) {
            return false;
        }

        if(A->val == B->val) {
            return isSame(A->left, B->left) && isSame(A->right, B->right);    
        } else {
            return false;
        }
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr){
            return false;
        }

        if(A->val == B->val && (isSame(A->left, B->left) && isSame(A->right, B->right)))
        {
            return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
