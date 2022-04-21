```c
int searchTimes(int* nums, int l, int r, int target, int flag){
    int m = -1, border = -1;

    while(l <= r)
    {
        m = (l+r)/2;
        if(nums[m] == target)
        {
            if(flag) l = m+1;
            else r = m-1;
            border = m;
        }
        else if(nums[m] > target) r = m-1;
        else l = m+1;
    }
    return border;
}

int search(int* nums, int numsSize, int target){
    int lTarget = -1, rTarget = -1;

    lTarget = searchTimes(nums, 0, numsSize-1, target, 0);
    rTarget = searchTimes(nums, 0, numsSize-1, target, 1);

    return lTarget == -1 ? 0 : (rTarget-lTarget+1);
}
```

