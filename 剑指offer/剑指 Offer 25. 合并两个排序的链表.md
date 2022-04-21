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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3, *l3Temp = NULL, *l3Pre = NULL;

        while(l1 != NULL || l2 != NULL){
            l3 = new ListNode();
            if(l3Temp == NULL)
                l3Temp = l3;

            if(l1 == NULL){
                l3->val = l2->val;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                l3->val = l1->val;
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                l3->val = l2->val;
                l2 = l2->next;
            }
            else{
                l3->val = l1->val;
                l1 = l1->next;
            }

            if(l3Pre != NULL) l3Pre->next = l3;
            l3Pre = l3;
        }
        
        return l3Temp;
    }
};
```