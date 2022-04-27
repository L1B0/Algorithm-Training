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
    map<int,int> index;
    map<int,int>::iterator it1, it2;
    TreeNode* myBuild(vector<int>& preorder, int root,  int ll, int rr){
        if(ll > rr) return NULL;

        TreeNode *node = new TreeNode(preorder[root]);
        if(ll == rr) return node;

        it1 = index.find(node->val);
        int mid = it1->second;
        
        node->left = myBuild(preorder, root+1, ll, mid-1);
        node->right = myBuild(preorder, root+mid-ll+1, mid+1, rr);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;

        map<int,int>::iterator it1, it2;

        for(int i=0;i<preorder.size();i++)
        {
            index.insert(pair<int, int>(inorder[i],i));
        }

        return myBuild(preorder, 0, 0, preorder.size()-1);
    }
};
```

