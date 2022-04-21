## 题面

\283. Move Zeroes

Easy

8738236Add to ListShare

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

 

**Example 1:**

```
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```

**Example 2:**

```
Input: nums = [0]
Output: [0]
```

 

**Constraints:**

- `1 <= nums.length <= 104`
- `-231 <= nums[i] <= 231 - 1`

 

**Follow up:** Could you minimize the total number of operations done?

## 解题思路

nowIndex记录当前数0的最小位置。

```


void moveZeroes(int* nums, int numsSize){
    int nowIndex = -1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] == 0 && nowIndex == -1) nowIndex = i;
        
        if(nowIndex != -1 && nums[i] != 0)
        {
            int t = nums[nowIndex];
            nums[nowIndex] = nums[i];
            nums[i] = t;
            
            nowIndex = 0;
            while(nowIndex < numsSize && nums[nowIndex] != 0) nowIndex++;
        }
    }
    
    return ;
}
```

