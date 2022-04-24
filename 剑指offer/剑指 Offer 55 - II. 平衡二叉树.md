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
    bool result = true;
    bool balanced(int a, int b){
        if(a > b)
            return (a-b) <= 1 ? true : false;
        else
            return (b-a) <= 1 ? true : false;
    }
    int calDepth(TreeNode *node){
        if(node == NULL) return 0;
        return max(calDepth(node->left)+1, calDepth(node->right)+1);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        if(root->left != NULL)
            result &= isBalanced(root->left);
        if(root->right != NULL)
            result &= isBalanced(root->right);

        if(result == false) return false; // faster!!!

        int leftDepth = calDepth(root->left), rightDepth = calDepth(root->right);
        if(balanced(leftDepth, rightDepth)) return result&true;
        else return false;
    }
};
```

后序遍历，剪枝