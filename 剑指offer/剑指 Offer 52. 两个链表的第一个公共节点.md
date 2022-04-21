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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ATemp = headA, *BTemp = headB;

        while(ATemp != BTemp){
            
            ATemp = ATemp ? ATemp->next : headB;
            BTemp = BTemp ? BTemp->next : headA;
        }
        return ATemp;
    }
};
```