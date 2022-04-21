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
    typedef struct Node{
        int val, level, nullFlag;
    }Node;
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        queue<pair<Node*, TreeNode*>> que;
        Node *nodeList = new Node[10000]; // 总节点数可能有几千
        int num = 0, levNum[1000] = {0}; // 记录每层节点数

        nodeList[num].val = root->val;
        nodeList[num].level = 1;
        nodeList[num++].nullFlag = false;
        levNum[1] = 1;

        que.push({&nodeList[0], root});
        while(!que.empty())
        {
            auto [t,tTree] = que.front();
            que.pop();

            if(t->nullFlag == true)
            {
                continue;
            }
            
            if(tTree->left != NULL)
            {
                nodeList[num].val = tTree->left->val;
                nodeList[num].level = t->level + 1;
                nodeList[num].nullFlag = false;
                que.push({&nodeList[num], tTree->left});
                levNum[nodeList[num].level] ++;
                num ++;
            }
            else
            {
                nodeList[num].level = t->level + 1;
                nodeList[num].nullFlag = true;
                que.push({&nodeList[num], tTree->left});
                levNum[nodeList[num].level] ++;
                num ++;
            }
            if(tTree->right != NULL)
            {
                nodeList[num].val = tTree->right->val;
                nodeList[num].level = t->level + 1;
                nodeList[num].nullFlag = false;
                que.push({&nodeList[num], tTree->right});
                levNum[nodeList[num].level] ++;
                num ++;
            }
            else
            {
                nodeList[num].level = t->level + 1;
                nodeList[num].nullFlag = true;
                que.push({&nodeList[num], tTree->right});
                levNum[nodeList[num].level] ++;
                num ++;
            }
        }

        int nowLev = 1, ii = 0;
        while(nowLev <= nodeList[num-1].level)
        {
            int nums = levNum[nowLev];
            for(int i=0; i<nums/2; i++)
            {
                if(nodeList[ii+i].nullFlag || nodeList[ii+nums-i-1].nullFlag)
                {
                    if(nodeList[ii+i].nullFlag != nodeList[ii+nums-i-1].nullFlag)
                        return false;
                }
                else if(nodeList[ii+i].val != nodeList[ii+nums-i-1].val) return false;
            }
            nowLev ++;
            ii += nums;
        }

        return true;
    }
};
```