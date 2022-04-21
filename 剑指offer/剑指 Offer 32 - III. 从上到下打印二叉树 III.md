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
    typedef struct myNode{
        TreeNode* node;
        int level;
    }myNode;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        vector<int> current;
        int nowLevel = 1, start = 0, nodeNum = 0;
        myNode que[2001];

        if(root == NULL) return output;
        
        que[nodeNum].node = root;
        que[nodeNum ++].level = nowLevel;

        while(start < nodeNum)
        {
            if(que[start].node == NULL)
            {
                start ++;
                continue;
            }

            if(que[start].node->left != NULL)
            {
                que[nodeNum].node = que[start].node->left;
                que[nodeNum].level = que[start].level+1;
                nodeNum ++;
            }
            if(que[start].node->right != NULL)
            {
                que[nodeNum].node = que[start].node->right;
                que[nodeNum].level = que[start].level+1;
                nodeNum ++;
            }
            start ++;
        }

        nowLevel = 1;
        for(int i=0;i<nodeNum;i++)
        {
            if(que[i].level != nowLevel)
            {
                if(nowLevel % 2 == 0) reverse(current.begin(), current.end());

                output.push_back(current);
                current.resize(0);
                nowLevel ++;
            }
            current.push_back(que[i].node->val);
        }
        if(nowLevel % 2 == 0) reverse(current.begin(), current.end());
        output.push_back(current);

        return output;
    }
};
```