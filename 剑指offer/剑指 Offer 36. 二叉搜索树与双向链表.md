中序遍历（递增），第一个节点作为pre，之后依次更新pre，并设置now。

最后将头尾相连。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
  ，   }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    int nums;
    Node *pre;
    void find(Node *now){
        
        if(now->left != NULL)
            find(now->left);

        if(nums != 0)
        {
            now->left = pre;
            pre->right = now;
        }
        pre = now;
        nums++;
        
        if(now->right != NULL)
            find(now->right);
        return ;
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        nums = 0;
        Node *tRoot = root, *first = root, *last = root;

        find(tRoot);

        while(first->left != NULL) first = first->left;
        while(last->right != NULL) last = last->right;

        first->left = last;
        last->right = first;

        return first;
    }
};
```

