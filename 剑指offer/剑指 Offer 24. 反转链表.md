```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
// 1. malloc a list to store value
struct ListNode* reverseList(struct ListNode* head){
    int *valu, num = 0;
    struct ListNode* temp = head;

    valu = malloc(sizeof(int)*5001);
    while(temp != NULL)
    {
        valu[num++] = temp->val;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        temp->val = valu[--num];
        temp = temp->next;
    }

    free(valu);
    return head;
}
*/
// 2. directly dwap
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* pre = NULL, *cur = head, *nex = NULL;
    while(cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}
```

