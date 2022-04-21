```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    
    void findAllPath(TreeNode* node, int target, vector<int> cur){
        if(node == NULL) return ;

        if(node->val == target && node->left == NULL && node->right == NULL){
            cur.push_back(node->val);
            result.push_back(cur);
            return ;
        }
        else{
            cur.push_back(node->val);
            findAllPath(node->left, target-node->val, cur);
            findAllPath(node->right, target-node->val, cur);
            return ;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        result.resize(0);
        vector<int> current;
        
        findAllPath(root, target, current);
        return result;
    }
};
```

