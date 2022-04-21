

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    int *result, num=10001;
    result = malloc(sizeof(int)*num);

    while(head != NULL) 
    {
        result[--num] = head->val;
        head = head->next;
    }

    *returnSize = 10001-num;
    return &result[num];
}
```

