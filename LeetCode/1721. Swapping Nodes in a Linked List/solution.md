## 题面

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100

## 解题思路

遍历两次单向链表，第一遍找到左边第k个node以及链表长度length，第二遍根据length找到右边第k个node。
接着交换两个node的val。


```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    int length = 1;
    struct ListNode *left = head, *right = head, *head_temp = head; 
    // 1. find left kth node and the length
    while(head_temp->next != NULL)
    {
        length ++;
        head_temp = head_temp->next;
        if(length == k)
            left = head_temp;
    }
    // 2. find right kth node
    int t_len = 1;
    head_temp = head;
    while(head_temp->next != NULL)
    {
        t_len ++;
        head_temp = head_temp->next;
        if(t_len == (length-k+1))
            right = head_temp;
    }
    // 3. swap the value
    int val_temp = left->val;
    left->val = right->val;
    right->val = val_temp;
    
    return head;
}
```