## 题面

Given an integer array `nums` sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

 

**Example 1:**

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**Example 2:**

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

 

**Constraints:**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` is sorted in **non-decreasing** order.

 

**Follow up:** Squaring each element and sorting the new array is very trivial, could you find an `O(n)` solution using a different approach?

## 解题思路



```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int mypow(int a)
{
    return a*a;
}
// start from maxest value
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *ret;
    ret = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    
    int n = numsSize-1, l = 0, r = numsSize-1;
    while(n >= 0)
    {
        int a = mypow(nums[l]), b = mypow(nums[r]);
        if(a < b)
        {
            r --;
            ret[n--] = b;
        }
        else
        {
            l ++;
            ret[n--] = a;
        }
        
    }
    return ret;
}
// start from minest value
/*
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int minIndex = 0, *ret;
    ret = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    
    // 1. find the minest value index
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] > 0)
        {
            if(nums[i] < (-nums[minIndex]))
                minIndex = i;
            break;
        }
        if( (-nums[i]) < (-nums[minIndex]) ) minIndex = i;
    }
    
    // 2. calculate and output the result
    int n = 1, l = minIndex-1, r = minIndex+1;
    ret[0] = mypow(nums[minIndex]);
    
    while(l >= 0 || r < numsSize)
    {
        if(l < 0)
        {
            ret[n++] = mypow(nums[r++]);
            continue;
        }
        if(r >= numsSize)
        {
            ret[n++] = mypow(nums[l--]);
            continue;
        }
        int a = mypow(nums[l]), b = mypow(nums[r]);
        if(a < b)
        {
            l --;
            ret[n++] = a;
        }
        else
        {
            r ++;
            ret[n++] = b;
        }
    }
    return ret;
}
*/
```

