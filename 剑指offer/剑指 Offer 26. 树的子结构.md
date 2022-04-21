```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isEqualTree(TreeNode *A, TreeNode *B){
        if(A == NULL && B != NULL) return false;

        if(A->val == B->val)
        {
            if(B->left == NULL && B->right == NULL)
                return true;
            else if(B->left == NULL && B->right != NULL)
                return isEqualTree(A->left, B->right) | isEqualTree(A->right, B->right);
            else if(B->left != NULL && B->right == NULL)
                return isEqualTree(A->left, B->left) | isEqualTree(A->right, B->left);
            else
                return isEqualTree(A->left, B->left) & isEqualTree(A->right, B->right);
        }

        return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL) return false;

        TreeNode *Atemp = A, *Btemp = B;
        if( isEqualTree(Atemp, Btemp) )
        {
            return true;
        }

        bool flag = false;
        if(A->left != NULL) flag |= isSubStructure(A->left, B);
        if(A->right != NULL) flag |= isSubStructure(A->right, B);

        return flag;
    }
};
```
