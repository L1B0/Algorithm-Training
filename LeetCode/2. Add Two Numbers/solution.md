## 题面

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

 

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## 解题思路

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    bool flag = false;
    int last_val = 0;
    struct ListNode *last_node, *temp, *temp2, *addOne;
    
    temp = l1;
    temp2 = l2;
    while(1)
    {   
        int t = temp->val + last_val;
        if(!flag && temp2 != NULL) t += temp2->val;
        
        temp->val = t%10;
        if(!flag && temp2 != NULL) temp2->val = t/10;

        last_val = t/10;
        last_node = temp;
        
        if(temp->next == NULL && temp2 != NULL && temp2->next != NULL)
        {
            flag = true;
            temp->next = temp2->next;
            temp2 = NULL;
        }
        
        temp = temp->next;
        if(!flag && temp2 != NULL) temp2 = temp2->next;

        if(temp == NULL) break;;
    }
    
    
    if(last_val != 0)
    {
        addOne = (struct ListNode*)malloc(sizeof(struct ListNode));
        addOne->val = last_val;
        addOne->next = NULL;
        last_node->next = addOne;
    }
    
    return l1;
}
```

第二种方法

```

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    bool flag = false;
    int last_val = 0;
    struct ListNode *last_node, *temp, *temp2, *addOne;
    
    // 1. find the longer list
    temp = l1;
    temp2 = l2;
    while(1)
    {
        if(temp == NULL || temp2 == NULL) break;
        
        temp = temp->next;
        temp2 = temp2->next;
    }
    
    if(temp == NULL)
    {
        temp = l2;
        temp2 = l1;
        flag = true;
    }
    else
    {
        temp = l1;
        temp2 = l2;
    }
    
    // 2. add temp2 to temp
    while(1)
    {
        int t = last_val + temp->val + (temp2 == NULL ? 0 : temp2->val);
        
        last_val = t/10;
        temp->val = t%10;
        
        last_node = temp;
        temp = temp->next;
        if(temp2 != NULL) temp2 = temp2->next;
        
        if(temp == NULL) break;
    }
    
    // 3. if need add one node
    if(last_val != 0)
    {
        addOne = (struct ListNode*)malloc(sizeof(struct ListNode));
        addOne->val = last_val;
        addOne->next = NULL;
        last_node->next = addOne;
    }
    
    return flag == true ? l2 : l1;
}
```

