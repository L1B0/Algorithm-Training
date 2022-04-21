## 题面

Given an array, rotate the array to the right by `k` steps, where `k` is non-negative.

 

**Example 1:**

```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Example 2:**

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

 

**Constraints:**

- `1 <= nums.length <= 105`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 105`

 

**Follow up:**

- Try to come up with as many solutions as you can. There are at least **three** different ways to solve this problem.
- Could you do it in-place with `O(1)` extra space?

## 解题思路

分解问题，为三次翻转数组。

```c
void myswap(int* nums, int l, int r)
{
    int t;
    while(l < r)
    {
        t = nums[l];
        nums[l++] = nums[r];
        nums[r--] = t;
    }
    return ;
}
void rotate(int* nums, int numsSize, int k){
    k = k%numsSize;
    if(k == 0) return;
    
    myswap(nums, 0, numsSize-k-1);
    myswap(nums, numsSize-k, numsSize-1);
    myswap(nums, 0, numsSize-1);
    
    return ;
}


/* failed
// 1. malloc a new list
void rotate(int* nums, int numsSize, int k){
    int flag = 1;
    k = k%numsSize;
    if(k == 0) return;
    
    
    for(int i=0;i< ((numsSize / k) * k);i++)
    {
        int t_index = numsSize-k+i%k, t;

        t_index = t_index%numsSize;
        
        t = nums[t_index];
        nums[t_index] = nums[i];
        nums[i] = t;
    }
    
    for (int i = ((numsSize / k) * k); i < numsSize-1;i++)
    {
        int m4x = i, t;
        for (int j = i + 1; j < numsSize;j++)
        {
            if (nums[m4x] > nums[j])
            {
                t = nums[m4x];
                nums[m4x] = nums[j];
                nums[j] = t;
                m4x = j;
            }
        }
    }
    return;
}
*/
```

