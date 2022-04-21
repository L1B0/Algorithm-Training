## 题面

Given a **1-indexed** array of integers `numbers` that is already ***sorted in non-decreasing order\***, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return *the indices of the two numbers,* `index1` *and* `index2`*, **added by one** as an integer array* `[index1, index2]` *of length 2.*

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

 

**Example 1:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

**Example 2:**

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

**Example 3:**

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

 

**Constraints:**

- `2 <= numbers.length <= 3 * 104`
- `-1000 <= numbers[i] <= 1000`
- `numbers` is sorted in **non-decreasing order**.
- `-1000 <= target <= 1000`
- The tests are generated such that there is **exactly one solution**.

## 解题思路

nlogn，循环+二分

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int solve(int* numbers, int l, int r, int value)
{
    int ret = -1;
    if(numbers[r] < value) return ret;
    
    while(l <= r)
    {
        int m = (l+r)/2;
        if(numbers[m] == value)
        {
            ret = m;
            break;
        }
        if(numbers[m] < value) l = m+1; // 注意l r的赋值
        else r = m-1;
    }
    return ret;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ret;
    ret = malloc(sizeof(int)*2);
    
    for(int i=0;i<numbersSize-1;i++)
    {
        int t = solve(numbers, i+1, numbersSize-1, target-numbers[i]);
        if(t != -1)
        {
            ret[0] = i+1;
            ret[1] = t+1;
            break;
        }
    }
    
    memcpy(numbers, ret, sizeof(int)*2);
    free(ret);
    
    *returnSize = 2;
    return numbers;
}
```

