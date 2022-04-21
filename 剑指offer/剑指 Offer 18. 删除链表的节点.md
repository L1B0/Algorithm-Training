```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pre = NULL, *tempHead = head;

        while(head != NULL){
            if(head->val == val) break;
            else{
                pre = head;
                head = head->next;
            }
        }

        if(pre == NULL) return tempHead->next;
        
        pre->next = head->next;
        return tempHead;
    }
};
```