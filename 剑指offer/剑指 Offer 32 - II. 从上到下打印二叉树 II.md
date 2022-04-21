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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        vector<int> current;
        int level = 1;
        queue<pair<int,TreeNode*>> que;

        if(root == NULL) return output;
        
        que.push({level, root});
        while(!que.empty())
        {
            auto [curL, curN] = que.front();
            if(curN == NULL)
            {
                que.pop();
                continue;
            }

            if(curL == level)
            {
                current.push_back(curN->val);
                que.pop();
                que.push({curL+1, curN->left});
                que.push({curL+1, curN->right});
            }
            else
            {
                level ++;
                output.push_back(current);
                current.resize(0);
            }
        }

        output.push_back(current);

        return output;
    }
};
```