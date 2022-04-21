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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> output;
        queue<TreeNode*> que;

        if(root != NULL) que.push(root);
        while(!que.empty())
        {
            TreeNode *t;
            t = que.front();
            output.push_back(t->val);

            que.pop();
            if(t->left != NULL) que.push(t->left);
            if(t->right != NULL) que.push(t->right);
        }

        return output;
    }
};
```