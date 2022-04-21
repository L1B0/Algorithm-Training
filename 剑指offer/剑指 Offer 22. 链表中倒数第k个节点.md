```c++
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
/*
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int len = 0;
        ListNode *tHead = head;
        while(tHead != NULL){
            tHead = tHead->next;
            len ++;
        }
        k = len-k+1;
        tHead = head;
        while(--k){
            tHead = tHead->next;
        }
        return tHead;
    }
*/
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *former, *latter;
        
        former = latter = head;
        for(int i=0;i<k;i++) former = former->next;

        while(former != NULL)
        {
            former = former->next;
            latter = latter->next;
        }

        return latter;
    }
};
```

