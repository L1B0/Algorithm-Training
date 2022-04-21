```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:

    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        long long num = 0, *addr, *newAddr;
        Node *newHead, *tempNewHead, *tempHead, *newNode;

        addr = new long long[1000];
        newAddr = new long long[1000];
        newHead = new Node(0);
    
        tempHead = head;
        tempNewHead = newHead;
        // copy val
        while(tempHead != NULL)
        {
            tempNewHead->val = tempHead->val;
            addr[num] = (long long)tempHead;
            newAddr[num++] = (long long)tempNewHead;

            if(tempHead->next != NULL)
            {
                newNode = new Node(0);
                tempNewHead->next = newNode;
            }
            tempHead = tempHead->next;
            tempNewHead = tempNewHead->next;
        }
        
        // copy random
        tempHead = head;
        tempNewHead = newHead;
        while(tempHead != NULL)
        {
            int index = 0;
            for(;index < num;index++)
            {
                if(addr[index] == (long long)tempHead->random)
                    break;
            }
            if(index < num)
                tempNewHead->random = (Node*)newAddr[index];

            tempHead = tempHead->next;
            tempNewHead = tempNewHead->next;
        }

        return newHead;
    }
};
```

