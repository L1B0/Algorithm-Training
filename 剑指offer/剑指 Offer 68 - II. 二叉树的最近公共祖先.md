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
    int Level;
    bool flag;
    void find(TreeNode* root, TreeNode* node, TreeNode *result, int level){
        if(flag == true) return ;

        if(root->left != NULL)
        {
            result[level] = *root;
            find(root->left, node, result, level+1);
        }

        if(flag == true) return ;
        if(root->val == node->val)
        {
            result[level] = *root;
            Level = level;
            flag = true;
            return;
        }

        if(root->right != NULL)
        {
            result[level] = *root;
            find(root->right, node, result, level+1);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result1, *result2, result;
        int level1=0, level2=0;
        result1 = new TreeNode[20000];
        result2 = new TreeNode[20000];

        flag = false;
        find(root, p, result1, 0);
        level1 = Level;

        flag = false;
        find(root, q, result2, 0);
        level2 = Level;

        int i=0;
        while(1){
            if(i > level1 || i > level2) break;
            
            if(result1[i].val == result2[i].val) result = result1[i];
            else break;
            i++;
        }

        return &result;
    }
};
```

记录路径；



一个更牛的思路

```
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *left, *right;

        if(root == NULL || root == p || root == q) return root;

        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL) return right;
        if(right == NULL) return left;

        return root;
    }
};
```

