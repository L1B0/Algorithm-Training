```c++
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
    int nums, result;
    void find(TreeNode* root, int k){
        if(root->right != NULL) find(root->right, k);
        nums ++;
        if(nums > k) return; // make faster
        if(nums == k)
        {
            result = root->val;
            return ;
        }
        if(root->left != NULL) find(root->left, k);
    }
    int kthLargest(TreeNode* root, int k) {
        nums = 0;

        find(root, k);
        return result;
    }
};
```

中序遍历，将左右顺序反过来即可。