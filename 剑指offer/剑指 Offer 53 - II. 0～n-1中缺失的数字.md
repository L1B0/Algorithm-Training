```c
int missingNumber(int* nums, int numsSize){
    int l = 0, r = numsSize-1, m = -1;
    while(l <= r )
    {
        m = (l+r)/2;
        if(nums[m] == m) l = m+1;
        else r = m-1;
    }
    return l;
}
```

